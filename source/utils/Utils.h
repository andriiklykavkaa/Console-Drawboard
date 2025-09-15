#ifndef UTILSMANAGER_H
#define UTILSMANAGER_H
#include <iostream>
#include <string>
#include <model/figure/Rectangle.h>

#include "model/colors/Color.h"
#include "model/figure/Shape.h"


class Utils {
private:
    Utils() = default;
    Utils(const Utils&) = delete;
    Utils& operator=(const Utils&) = delete;
public:

    enum class ShapeTag {
        Rect, Box, Circle
    };

    static Utils& shared() {
        static Utils instance;
        return instance;
    }

    static std::optional<Color> parse_color(const std::string &str_color) {
        if (str_color == "red")
            return std::make_optional(Color::RED);
        else if (str_color == "blue")
            return std::make_optional(Color::BLUE);
        else if (str_color == "green")
            return std::make_optional(Color::GREEN);
        else if (str_color == "white")
            return std::make_optional(Color::WHITE);
        else {
            std::cerr << "Invalid color param." << std::endl;
            return std::nullopt;
        }

    }

    static std::optional<ShapeTag> tag(const std::string &str_shape) {
        if (str_shape == "rect")
            return std::make_optional(ShapeTag::Rect);
        else {
            std::cerr << "Invalid shape tag param." << std::endl;
            return std::nullopt;
        }
    }

    static std::optional<std::tuple<int, int>> parse_coords(const std::string &str_x, const std::string &str_y) {

        int x, y;
        try {
            x = std::stoi(str_x);
            y = std::stoi(str_y);
        } catch (std::invalid_argument &e) {
            std::cerr << "Invalid coords." << std::endl;
            return std::nullopt;
        }

        return std::make_optional(std::make_tuple(x, y));
    }

    static std::optional<int> parse_num(const std::string &str_n) {
        int n;
        try {
            n = std::stoi(str_n);
        } catch (std::invalid_argument &e) {
            std::cerr << "Invalid syntax. Expected number." << std::endl;
            return std::nullopt;
        }
        return std::make_optional(n);
    }
};



#endif
