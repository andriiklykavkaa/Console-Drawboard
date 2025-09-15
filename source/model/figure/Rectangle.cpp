#include "Rectangle.h"

#include <iostream>

Rectangle::Rectangle(Color color, std::pair<int, int> xy, std::pair<int,int> wh)
: Shape(color, xy), wh(wh)
{}

// void Rectangle::draw() {
//     std::cout << "rectangle drawn" << std::endl;
// }
