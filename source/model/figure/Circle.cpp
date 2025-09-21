#include "Circle.h"

#include <iostream>
#include <nlohmann/json.hpp>

Circle::Circle(DrawMode mode, Color color, std::pair<int, int> xy, int r)
    : Shape(mode, color, xy), r(r)
{}

std::shared_ptr<Shape> Circle::clone() {
    return std::make_shared<Circle>(*this);
}

std::vector<std::pair<int,int>> Circle::get_px_poses() {
    std::vector<std::pair<int,int>> px_poses;
    int rr = r*r;

    if (mode == DrawMode::FILL) {
        for (int y = -r; y <= r; ++y) {
            for (int x = -r; x <= r; ++x) {
                if (x*x + y*y <= rr)
                    px_poses.emplace_back(xy.first+x, xy.second+y);
            }
        }
    } else {
        for (int y = -r; y <= r; ++y) {
            for (int x = -r; x <= r; ++x) {
                int d2 = x*x + y*y;
                if (d2 <= rr && d2 >= (r-1)*(r-1)) {
                    px_poses.emplace_back(xy.first + x, xy.second + y);
                }
            }
        }
    }

    return px_poses;
}

bool Circle::contains(int x, int y) {
    auto poses = get_px_poses();
    for (auto [px, py] : poses) {
        if (px == x && py == y) return true;
    }
    return false;
}

bool Circle::set_sizes(std::vector<int>& sizes) {
    if (sizes.size() != 1) {
        std::cerr << "Error: Invalid argument count" << std::endl;
        return false;
    }

    r = sizes.at(0);
    return true;
}

char Circle::get_symbol() {
    return 'C';
}


nlohmann::json Circle::to_json() {
    return {
            {"type", "circle"},
            {"mode", static_cast<int>(mode)},
            {"color", static_cast<int>(color)},
            {"x", xy.first},
            {"y", xy.second},
            {"r", r},
    };
}

std::shared_ptr<Circle> Circle::from_json(const nlohmann::json& json) {
    return std::make_shared<Circle>(
        static_cast<DrawMode>(json.at("mode").get<int>()),
        static_cast<Color>(json.at("color").get<int>()),
        std::make_pair(json.at("x").get<int>(), json.at("y").get<int>()),
        json.at("r").get<int>()
        );
}

void Circle::to_string() {
    std::cout << "ID: "<< id << ", Circle, x: " << xy.first  << ", y: " << xy.second << ", r=" << r << std::endl;
}