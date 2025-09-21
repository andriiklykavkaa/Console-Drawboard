#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <vector>

#include "model/figure/Shape.h"
#include "utils/Utils.h"
#include "model/Pixel.h"

class Board {
private:
    int w, h;
    std::vector<std::vector<Pixel>> grid;

    void init_grid() {
        grid.clear();
        grid.resize(h);
        for (auto& row : grid) {
            row.assign(w, Pixel{'$', Color::GREY});
        }
    }

public:
    Board(const int w, const int h): w(w), h(h) {
        init_grid();
    }

    ~Board() = default;

    void draw() {
        for (auto &l: grid) {
            for (auto &px: l)
                std::cout << Utils::get_color_code(px.color) << px.symbol << "\033[0m";
            std::cout << std::endl;
        }
    }

    bool validate(std::shared_ptr<Shape> shape) {
        std::vector<std::pair<int, int>> poses = shape->get_px_poses();
        if (poses.empty()) return false;

        int count = 0;
        for (auto [x, y] : poses) {
            if (x >= 0 && x < w && y >= 0 && y < h) {
                count++;
            }
        }

        if (count == 0) return false;
        if (count >= w * h) return false;

        return true;
    }

    void reset() {
        grid.clear();
        grid.resize(h);
        for (auto& row : grid) {
            row.assign(w, Pixel{'$', Color::WHITE});
        }
    }

    void set_pixels(const std::vector<std::shared_ptr<Shape>>& shapes) {
        this->reset();
        for (auto& shape: shapes) {
            char sym = shape->get_symbol();
            auto px_poses = shape->get_px_poses();
            for (auto [x,y]: px_poses) {
                if (y >= 0 && y < h && x >= 0 && x < w) {
                    grid[y][x] = Pixel{sym, shape->get_color()};
                }
            }
        }
    }

};

// add red rect 2 2 10 10
// add blue circle 5 5 5

#endif
