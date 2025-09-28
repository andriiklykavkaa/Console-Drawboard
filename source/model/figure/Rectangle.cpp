#include "Rectangle.h"

#include <iostream>
#include <utility>
#include <nlohmann/json.hpp>

Rectangle::Rectangle(DrawMode mode, Color color, std::pair<int, int> xy, std::pair<int,int> wh)
: Shape(mode, color, xy), wh(std::move(wh))
{}

std::shared_ptr<Shape> Rectangle::clone() {
    return std::make_shared<Rectangle>(*this);
}

std::vector<std::pair<int,int>> Rectangle::get_px_poses() {
    std::vector<std::pair<int,int>> px_poses;

    if (mode == DrawMode::FILL) {
        for (int y = 0; y < wh.second; ++y) {
            for (int x = 0; x < wh.first; ++x) {
                px_poses.emplace_back(xy.first + x, xy.second + y);
            }
        }
    } else {
        for (int x = 0; x < wh.first; ++x) {
            px_poses.emplace_back(xy.first + x, xy.second);
            px_poses.emplace_back(xy.first + x, xy.second + wh.second-1);
        }
        for (int y = 0; y < wh.second; ++y) {
            px_poses.emplace_back(xy.first, xy.second + y);
            px_poses.emplace_back(xy.first + wh.first-1, xy.second + y);
        }
    }

    return px_poses;
}

bool Rectangle::contains(int x, int y) {
    std::vector<std::pair<int, int>> poses = get_px_poses();
    for (auto [px, py] : poses) {
        if (px == x && py == y) return true;
    }
    return false;
}

void Rectangle::set_sizes(std::vector<int>& sizes) {
    if (sizes.size() != 1 && sizes.size() != 2) {
        std::cerr << "Error: Invalid argument count." << std::endl;
        return;
    }

    wh.first = sizes.at(0);
    wh.second = sizes.size() == 2 ? sizes.at(1) : sizes.at(0);
}

char Rectangle::get_symbol() {
    return 'R';
}


nlohmann::json Rectangle::to_json() {
    return {
        {"type", "rectangle"},
        {"mode", static_cast<int>(mode)},
        {"color", static_cast<int>(color)},
        {"x", xy.first},
        {"y", xy.second},
        {"w", wh.first},
        {"h", wh.second}
    };
}

std::shared_ptr<Rectangle> Rectangle::from_json(const nlohmann::json& json) {
    return std::make_shared<Rectangle>(
        static_cast<DrawMode>(json.at("mode").get<int>()),
        static_cast<Color>(json.at("color").get<int>()),
        std::make_pair(json.at("x").get<int>(), json.at("y").get<int>()),
        std::make_pair(json.at("w").get<int>(), json.at("h").get<int>())
        );
}

void Rectangle::to_string() {
    std::cout << "ID: "<< id << ", Rectangle, color=" << color << " x: " << xy.first  << ", y: " << xy.second << ", w=" <<
        wh.first << ", h=" << wh.second << std::endl;
}
