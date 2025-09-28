#include "model/figure/Shape.h"

char Shape::symbol = '#';
int Shape::id_counter = 0;

Shape::Shape(DrawMode mode, Color color, std::pair<int, int> xy)
    : mode(mode), id(id_counter++), color(color), xy(std::move(xy)) {}

Shape::~Shape() = default;

void Shape::set_color(Color c) {
    color = c;
}

Color Shape::get_color() const {
    return color;
}

void Shape::set_xy(std::pair<int, int> pos) {
    xy = pos;
}

std::pair<int, int> Shape::get_xy() const {
    return xy;
}

int Shape::get_id() const {
    return id;
}
