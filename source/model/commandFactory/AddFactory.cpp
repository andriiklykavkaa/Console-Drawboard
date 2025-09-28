#include "AddFactory.h"

#include <iostream>
#include <model/command/AddCommand.h>

#include "model/figure/Circle.h"
#include "model/figure/Line.h"
#include "model/figure/Rectangle.h"
#include "model/figure/Shape.h"
#include "model/figure/Triangle.h"

#include "utils/Utils.h"

std::shared_ptr<Command> AddFactory::build(const std::vector<std::string>& tokens) {
    if(tokens.size() < MIN_PARAM_COUNT) {
        std::cerr << "\nInvalid arguments. " << std::endl;
        return nullptr;
    }

    const std::optional<DrawMode> mode = Utils::parse_mode(tokens.at(0));
    const std::optional<Color> color = Utils::parse_color(tokens.at(1));
    const std::optional<Utils::ShapeTag> tag = Utils::tag(tokens.at(2));

    if (!mode.has_value() || !color.has_value() || !tag.has_value())
        return nullptr;

    std::shared_ptr<Shape> shape;
    switch (tag.value()) {
        case Utils::ShapeTag::Rect: {
            if (tokens.size() != RECT_PARAM_COUNT_TYPE_1 && tokens.size() != RECT_PARAM_COUNT_TYPE_2) {
                std::cerr << "\nExpected " << RECT_PARAM_COUNT_TYPE_1
                << "or " << RECT_PARAM_COUNT_TYPE_2 << "params for rectangle." << std::endl;
                return nullptr;
            }
            std::optional<std::pair<int, int>> coords = Utils::parse_coords(tokens.at(3), tokens.at(4));
            std::optional<int> w = Utils::parse_num(tokens.at(5));
            std::optional<int> h  = tokens.size() == RECT_PARAM_COUNT_TYPE_2 ? Utils::parse_num(tokens.at(6)) : w;

            if (!coords.has_value() || !w.has_value() || !h.has_value())
                return nullptr;

            shape = std::make_shared<Rectangle>(mode.value(), color.value(), coords.value(), std::make_pair(w.value(),h.value()));
            break;
        }

        case Utils::ShapeTag::Circle: {
            if (tokens.size() != CIRCLE_PARAM_COUNT) {
                std::cerr << "\nExpected "<< CIRCLE_PARAM_COUNT<< "params for circle." << std::endl;
                return nullptr;
            }
            std::optional<std::pair<int, int>> coords = Utils::parse_coords(tokens.at(3), tokens.at(4));
            std::optional<int> r = Utils::parse_num(tokens.at(5));

            if (!coords.has_value() || !r.has_value())
                return nullptr;

            shape = std::make_shared<Circle>(mode.value(), color.value(), coords.value(), r.value());
            break;
        }

        case Utils::ShapeTag::Triangle: {
            if (tokens.size() != TRIANGLE_PARAM_COUNT) {
                std::cerr << "\nExpected " << TRIANGLE_PARAM_COUNT << " params for triangle." << std::endl;
                return nullptr;
            }
            std::optional<std::pair<int, int>> coords = Utils::parse_coords(tokens.at(3), tokens.at(4));
            std::optional<int> h = Utils::parse_num(tokens.at(5));

            if (!coords.has_value() || !h.has_value())
                return nullptr;

            shape = std::make_shared<Triangle>(mode.value(), color.value(), coords.value(), h.value());
            break;
        }

        case Utils::ShapeTag::Line: {
            if (tokens.size() != LINE_PARAM_COUNT) {
                std::cerr << "\nExpected " << LINE_PARAM_COUNT << "params for line." << std::endl;
                return nullptr;
            }
            std::optional<std::pair<int, int>> a_coords = Utils::parse_coords(tokens.at(3), tokens.at(4));
            std::optional<std::pair<int, int>> b_coords = Utils::parse_coords(tokens.at(5), tokens.at(6));

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
