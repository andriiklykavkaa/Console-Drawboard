#include "Square.h"

#include <iostream>

Square::Square(Color color, std::pair<int, int> xy, int a)
    : Shape(color, xy), a(a)
{}
//
// void Square::draw() {
//     std::cout << "rectangle drawn" << std::endl;
// }