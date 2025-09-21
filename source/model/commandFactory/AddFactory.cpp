#include "AddFactory.h"

#include <iostream>
#include <model/command/AddCommand.h>

#include "model/figure/Circle.h"
#include "model/figure/Line.h"
#include "model/figure/Rectangle.h"
#include "model/figure/Shape.h"
#include "model/figure/Triangle.h"

#include "utils/Utils.h"

std::shared_ptr<Command> AddFactory::build(std::vector<std::string> tokens) {
    if(tokens.size() < 6) {
        std::cerr << "\nInvalid arguments. " << std::endl;
        return nullptr;
    }

    auto mode = Utils::parse_mode(tokens.at(0));
    auto color = Utils::parse_color(tokens.at(1));
    auto tag = Utils::tag(tokens.at(2));

    if (!mode.has_value() || !color.has_value() || !tag.has_value())
        return nullptr;

    std::shared_ptr<Shape> shape;
    switch (tag.value()) {
        case Utils::ShapeTag::Rect: {
            if (tokens.size() != 6 && tokens.size() != 7) {
                std::cerr << "\nExpected 6 or 7 params for rectangle." << std::endl;
                return nullptr;
            }
            auto coords = Utils::parse_coords(tokens.at(3), tokens.at(4));
            auto w = Utils::parse_num(tokens.at(5));
            auto h  = tokens.size() == 7 ? Utils::parse_num(tokens.at(6)) : w;

            if (!coords.has_value() || !w.has_value() || !h.has_value())
                return nullptr;

            shape = std::make_shared<Rectangle>(mode.value(), color.value(), coords.value(), std::make_pair(w.value(),h.value()));
            break;
        }

        case Utils::ShapeTag::Circle: {
            if (tokens.size() != 6) {
                std::cerr << "\nExpected 6 params for circle." << std::endl;
                return nullptr;
            }
            auto coords = Utils::parse_coords(tokens.at(3), tokens.at(4));
            auto r = Utils::parse_num(tokens.at(5));

            if (!coords.has_value() || !r.has_value())
                return nullptr;

            shape = std::make_shared<Circle>(mode.value(), color.value(), coords.value(), r.value());
            break;
        }

        case Utils::ShapeTag::Triangle: {
            if (tokens.size() != 6) {
                std::cerr << "\nExpected 6 params for triangle." << std::endl;
                return nullptr;
            }
            auto coords = Utils::parse_coords(tokens.at(3), tokens.at(4));
            auto h = Utils::parse_num(tokens.at(5));

            if (!coords.has_value() || !h.has_value())
                return nullptr;

            shape = std::make_shared<Triangle>(mode.value(), color.value(), coords.value(), h.value());
            break;
        }

        case Utils::ShapeTag::Line: {
            if (tokens.size() != 7) {
                std::cerr << "\nExpected 7 params for line." << std::endl;
                return nullptr;
            }
            auto a_coords = Utils::parse_coords(tokens.at(3), tokens.at(4));
            auto b_coords = Utils::parse_coords(tokens.at(5), tokens.at(6));

            if (!a_coords.has_value() || !b_coords.has_value())
                return nullptr;

            shape = std::make_shared<Line>(mode.value(), color.value(), a_coords.value(), b_coords.value());
            break;
        }

        default:
            break;
    }

    if (!shape) {
        std::cerr << "\nFailed to build shape." << std::endl;
        return nullptr;
    }
    std::shared_ptr<AddCommand> command = std::make_shared<AddCommand>(shape);
    return command;
}
