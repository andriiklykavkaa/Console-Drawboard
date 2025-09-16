#include "Square.h"

#include <iostream>

Square::Square(Color color, std::pair<int, int> xy, int a)
    : Shape(color, xy), a(a)
{}

void Square::to_string() {
    std::cout << "ID: "<< ID << ", Square, x: " << xy.first  << ", y: " << xy.second  <<", a=" << a << std::endl;
}