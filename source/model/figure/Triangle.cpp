#include "Triangle.h"

#include <iostream>
#include <nlohmann/json.hpp>


Triangle::Triangle(DrawMode mode, Color color, std::pair<int, int> xy, int h)
: Shape(mode, color, xy), h(h)
{}

std::shared_ptr<Shape> Triangle::clone() {
    return std::make_shared<Triangle>(*this);
}

std::vector<std::pair<int,int>> Triangle::get_px_poses() {
    std::vector<std::pair<int,int>> px_poses;

    int x0 = xy.first;
    int y0 = xy.second;

    if (mode == DrawMode::FILL) {
        for (int dy = 0; dy <= h; ++dy) {
            int y = y0 + dy;
            int x_left  = x0 - dy;
            int x_right = x0 + dy;

            for (int x = x_left; x <= x_right; ++x) {
                px_poses.emplace_back(x, y);
            }
        }
    } else {
        for (int dy = 0; dy <= h; ++dy) {
            px_poses.emplace_back(x0 - dy, y0 + dy);
        }
        for (int dy = 0; dy <= h; ++dy) {
            px_poses.emplace_back(x0 + dy, y0 + dy);
        }
        for (int x = x0 - h; x <= x0 + h; ++x) {
            px_poses.emplace_back(x, y0 + h);
        }
    }

    return px_poses;
}

bool Triangle::contains(int x, int y) {
    auto poses = get_px_poses();
    for (auto [px, py] : poses) {
        if (px == x && py == y) return true;
    }
    return false;
}

void Triangle::set_sizes(std::vector<int>& sizes) {
    if (sizes.size() != 1) {
        std::cerr << "Error: Invalid argument count." << std::endl;
        return;
    }

    h = sizes.at(0);
}

char Triangle::get_symbol() {
    return 'T';
}

nlohmann::json Triangle::to_json() {
    return {
        {"type", "triangle"},
        {"mode", static_cast<int>(mode)},
        {"color", static_cast<int>(color)},
        {"x", xy.first},
        {"y", xy.second},
        {"h", h}
    };
}

std::shared_ptr<Triangle> Triangle::from_json(nlohmann::json& json) {
    return std::make_shared<Triangle>(
        static_cast<DrawMode>(json.at("mode").get<int>()),
        static_cast<Color>(json.at("color").get<int>()),
        std::make_pair(json.at("x").get<int>(), json.at("y").get<int>()),
        json.at("h").get<int>()
        );
}

void Triangle::to_string() {
    std::cout << "ID: "<< id << ", Triangle, color=" << color << " x: " << xy.first  << ", y: " << xy.second << ", h="
    << h << std::endl;
}
