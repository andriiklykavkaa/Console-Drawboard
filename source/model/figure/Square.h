#ifndef SQUARE_H
#define SQUARE_H
#include <utility>

#include "Shape.h"
#include "model/colors/Color.h"


class Square : public Shape {
private:
    int a;

public:
    Square(Color color, std::pair<int, int> xy, int a);
    ~Square() = default;
    // ~Square() override = default;
    // void draw() override;
};



#endif
