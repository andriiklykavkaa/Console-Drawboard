#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"


class Circle : public Shape {
private:
    int r;

public:
    Circle(Color color, std::pair<int, int> xy, int r);
    void to_string() override;
};




#endif
