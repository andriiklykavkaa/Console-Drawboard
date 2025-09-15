#include "AddFactory.h"

#include <iostream>
#include <model/command/AddCommand.h>

#include "model/colors/Color.h"
#include "model/figure/Shape.h"
#include "model/figure/Square.h"
#include "utils/Utils.h"

std::shared_ptr<Command> AddFactory::build(std::vector<std::string> tokens) {
    if(tokens.size() < 5) {
        std::cerr << "Invalid arguments. " << std::endl;
        return nullptr;
    }

    auto color = Utils::parse_color(tokens.at(0));
    auto tag = Utils::tag(tokens.at(1));

    if (!color.has_value() || !tag.has_value())
        return nullptr;

    std::shared_ptr<Shape> shape;
    switch (tag.value()) {
        case Utils::ShapeTag::Rect: {
            if (tokens.size() != 6) {
                std::cerr << "Expected 6 params for rectangle." << std::endl;
                return nullptr;
            }
            auto w = Utils::parse_num(tokens.at(2));
            auto h  = Utils::parse_num(tokens.at(3));
            auto coords = Utils::parse_coords(tokens.at(4), tokens.at(5));

            if (!w.has_value() || !h.has_value() || !coords.has_value())
                return nullptr;

            shape = std::make_shared<Rectangle>(color.value(), coords.value(), std::make_pair(w.value(),h.value()));
            break;
        }

        case Utils::ShapeTag::Box: {
            if (tokens.size() != 5) {
                std::cerr << "Expected 5 params for square." << std::endl;
                return nullptr;
            }
            auto a  = Utils::parse_num(tokens.at(2));
            auto coords = Utils::parse_coords(tokens.at(4), tokens.at(5));

            if (!a.has_value() || !coords.has_value())
                return nullptr;

            shape = std::make_shared<Square>(color.value(), coords.value(), a.value());
            break;
        }
        default:
            break;
    }

    if (!shape) {
        std::cerr << "Failed to build shape." << std::endl;
        return nullptr;
    }
    std::shared_ptr<AddCommand> command = std::make_shared<AddCommand>(shape);
    return command;
}
