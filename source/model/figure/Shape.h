

#ifndef IFIGURE_H
#define IFIGURE_H
#include <vector>

#include "model/colors/Color.h"


class Shape {
protected:
    static int id_counter;
    int id;

    std::pair<int, int> xy;
    Color color;

public:
    Shape(Color color, std::pair<int, int> xy)
    : id(id_counter++), xy(xy), color(color)
    {}

    ~Shape() = default;
    virtual void to_string() = 0;
    // virtual void draw();

    void set_color(Color color) {
        this->color = color;
    }

    void set_xy(std::pair<int, int> xy) {
        this->xy = xy;
    }

    int get_id() {
        return id;
    }
};


#endif
