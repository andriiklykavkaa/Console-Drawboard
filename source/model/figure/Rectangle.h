#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
#include "model/colors/Color.h"


class Rectangle : public Shape {
private:
    std::pair<int,int> wh;

public:
    Rectangle(Color color, std::pair<int, int> xy, std::pair<int,int> hw);
    ~Rectangle() = default;
    // ~Rectangle() override = default;
    // void draw() override;
};



#endif
