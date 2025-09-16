#ifndef RENDERER_H
#define RENDERER_H
#include <iostream>


class Renderer {
private:

public:
    explicit Renderer() = default;
    ~Renderer() = default;

    void render() {
        std::cout << "Rendering map." << std::endl;
    }
};



#endif
