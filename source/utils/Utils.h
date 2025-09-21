#ifndef UTILSMANAGER_H
#define UTILSMANAGER_H

#include <iostream>
#include <string>
#include <optional>
#include <tuple>

#include "model/colors/Color.h"
#include "model/figure/Shape.h"

class Utils {
public:
    enum class ShapeTag {
        Rect, Circle, Triangle, Line
    };

    static std::optional<DrawMode> parse_mode(const std::string& str_mode);
    static std::optional<Color> parse_color(const std::string& str_color);
    static std::optional<std::tuple<int,int>> parse_coords(const std::string& str_x, const std::string& str_y);
    static std::optional<int> parse_num(const std::string& str_n);

    static std::optional<ShapeTag> tag(const std::string& str_shape);
    static std::string get_color_code(Color c);
};

#endif // UTILSMANAGER_H
