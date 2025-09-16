#include "Rectangle.h"

#include <iostream>

Rectangle::Rectangle(Color color, std::pair<int, int> xy, std::pair<int,int> wh)
: Shape(color, xy), wh(wh)
{}

void Rectangle::to_string() {
    std::cout << "ID: "<< ID << ", Rectangle, x: " << xy.first  << ", y: " << xy.second << ", w=" <<
        wh.first << ", h=" << wh.second << std::endl;
}