#include "utils/Utils.h"

std::optional<DrawMode> Utils::parse_mode(const std::string& str_mode) {
    if (str_mode == "fill")  return std::make_optional(DrawMode::FILL);
    if (str_mode == "frame") return std::make_optional(DrawMode::FRAME);

    std::cerr << "\nInvalid draw mode." << std::endl;
    return std::nullopt;
}

std::optional<Color> Utils::parse_color(const std::string &str_color) {
    if (str_color == "red")   return std::make_optional(Color::RED);
    if (str_color == "blue")  return std::make_optional(Color::BLUE);
    if (str_color == "green") return std::make_optional(Color::GREEN);
    if (str_color == "white") return std::make_optional(Color::WHITE);
    if (str_color == "grey")  return std::make_optional(Color::GREY);

    std::cerr << "\nInvalid color param." << std::endl;
    return std::nullopt;
}

std::optional<Utils::ShapeTag> Utils::tag(const std::string &str_shape) {
    if (str_shape == "rect")     return std::make_optional(ShapeTag::Rect);
    if (str_shape == "circle")   return std::make_optional(ShapeTag::Circle);
    if (str_shape == "triangle") return std::make_optional(ShapeTag::Triangle);
    if (str_shape == "line")     return std::make_optional(ShapeTag::Line);

    std::cerr << "\nInvalid shape tag param." << std::endl;
    return std::nullopt;
}

std::optional<std::tuple<int,int>> Utils::parse_coords(const std::string& str_x, const std::string& str_y) {
    try {
        int x = std::stoi(str_x);
        int y = std::stoi(str_y);
        return std::make_optional(std::make_tuple(x, y));
    } catch (std::invalid_argument&) {
        std::cerr << "Invalid coords." << std::endl;
        return std::nullopt;
    }
}

std::optional<int> Utils::parse_num(const std::string& str_n) {
    try {
        return std::make_optional(std::stoi(str_n));
    } catch (std::invalid_argument&) {
        std::cerr << "Invalid syntax. Expected number." << std::endl;
        return std::nullopt;
    }
}

std::string Utils::get_color_code(Color c) {
    switch (c) {
        case Color::BLUE:  return "\033[34m";
        case Color::RED:   return "\033[31m";
        case Color::GREEN: return "\033[32m";
        case Color::WHITE: return "\033[37m";
        case Color::GREY:  return "\033[90m";
        default:           return "\033[0m";
    }
}
