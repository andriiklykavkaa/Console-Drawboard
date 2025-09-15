

#ifndef IFIGURE_H
#define IFIGURE_H
#include <vector>

#include "model/colors/Color.h"


class Shape {
protected:
    static int ID_counter;
    int ID;

    std::pair<int, int> xy;
    Color color;

public:
    Shape(Color color, std::pair<int, int> xy)
    : ID(ID_counter++), xy(xy), color(color)
    {}

    // virtual ~Shape() = default;
    // virtual void draw();
};


#endif
