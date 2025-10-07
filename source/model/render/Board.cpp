#include "model/render/Board.h"

#include "utils/Utils.h"

Board::Board(const int w, const int h) : w(w), h(h) {
    init_grid();
}

Board::~Board() = default;

void Board::init_grid() {
    grid.clear();
    grid.resize(h);
    for (auto& row : grid) {
        row.assign(w, Pixel{'$', Color::GREY});
    }
}

void Board::draw() {
    for (auto &l: grid) {
        for (auto &px: l) {
            std::cout << Utils::get_color_code(px.color) << px.symbol << "\033[0m";
        }
        std::cout << std::endl;
    }
}

bool Board::validate(const std::shared_ptr<Shape>& shape) {
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

void Board::reset() {
    grid.clear();
    grid.resize(h);
    for (auto& row : grid) {
        row.assign(w, Pixel{'$', Color::WHITE});
    }
}

void Board::set_pixels(const std::vector<std::shared_ptr<Shape>>& shapes) {
    this->reset();
    for (const std::shared_ptr<Shape>& shape: shapes) {
        char sym = shape->get_symbol();
        std::vector<std::pair<int, int>> px_poses = shape->get_px_poses();
        for (auto [x,y]: px_poses) {
            if (y >= 0 && y < h && x >= 0 && x < w) {
                grid[y][x] = Pixel{sym, shape->get_color()};
            }
        }
    }
}
