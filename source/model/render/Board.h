#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>

#include "model/figure/Shape.h"
#include "model/Pixel.h"

class Board {
private:
    int w, h;
    std::vector<std::vector<Pixel>> grid;

    void init_grid();

public:
    Board(int w, int h);
    ~Board();

    void draw();
    bool validate(std::shared_ptr<Shape> shape);
    void reset();
    void set_pixels(const std::vector<std::shared_ptr<Shape>>& shapes);
};

#endif // BOARD_H
