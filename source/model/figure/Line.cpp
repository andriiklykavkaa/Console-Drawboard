#include "Line.h"

#include <iostream>
#include <nlohmann/json.hpp>


Line::Line(DrawMode mode, Color color, std::pair<int, int> axy, std::pair<int,int> bxy)
: Shape(mode, color, axy), vec(bxy.first - axy.first, bxy.second - axy.second)
{}

std::shared_ptr<Shape> Line::clone() {
    return std::make_shared<Line>(*this);
}

std::vector<std::pair<int,int>> Line::get_px_poses() {
    std::vector<std::pair<int,int>> px_poses;

    int x0 = xy.first;
    int y0 = xy.second;
    int x1 = x0 + vec.first;
    int y1 = x0 + vec.second;

    int dx = std::abs(x1 - x0);
    int dy = std::abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;


    while (true) {
        px_poses.emplace_back(x0, y0);

        if (x0 == x1 && y0 == y1) break;

        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx)  { err += dx; y0 += sy; }
    }

    return px_poses;
}

bool Line::contains(int x, int y) {
    std::vector<std::pair<int, int>> poses = get_px_poses();
    for (auto [px, py] : poses) {
        if (px == x && py == y) return true;
    }
    return false;
}

void Line::set_sizes(std::vector<int>& sizes) {
    std::cerr << std::endl << "Error: 'Line' cannot be resized" << std:: endl;
    return;
}

char Line::get_symbol() {
    return 'L';
}


nlohmann::json Line::to_json() {
    return {
        {"type", "line"},
        {"mode", static_cast<int>(mode)},
        {"color", static_cast<int>(color)},
        {"ax", xy.first},
        {"ay", xy.second},
        {"bx", xy.first + vec.first},
        {"by", xy.second + vec.second}
    };
}

std::shared_ptr<Line> Line::from_json(const nlohmann::json& json) {
    return std::make_shared<Line>(
        static_cast<DrawMode>(json.at("mode").get<int>()),
        static_cast<Color>(json.at("color").get<int>()),
        std::make_pair(json.at("ax").get<int>(), json.at("ay").get<int>()),
        std::make_pair(json.at("bx").get<int>(), json.at("by").get<int>())
        );
}

void Line::to_string() {
    std::cout << "ID: "<< id << ", Line, color=" << color << ", (x0, y0): (" << xy.first  << ", " << xy.second << "), (x1, y1): (" <<
        xy.first + vec.first << ", " << xy.second + vec.second << ")" << std::endl;
}
