#ifndef RENDERER_H
#define RENDERER_H
#include <iostream>

#include "model/render/Board.h"


class Renderer {
private:
    std::shared_ptr<Board> board;

public:
    explicit Renderer(std::shared_ptr<Board> board);
    ~Renderer() = default;


    void render(std::vector<std::shared_ptr<Shape>>& shapes) {
        board->set_pixels(shapes);
        board->draw();
    }

};



#endif
