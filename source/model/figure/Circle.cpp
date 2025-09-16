#include "Circle.h"

#include <iostream>

Circle::Circle(Color color, std::pair<int, int> xy, int r)
    : Shape(color, xy), r(r)
{}

void Circle::to_string() {
    std::cout << "ID: "<< ID << ", Circle, x: " << xy.first  << ", y: " << xy.second << ", r=" << r << std::endl;
}