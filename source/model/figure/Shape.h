

#ifndef IFIGURE_H
#define IFIGURE_H
#include <utility>
#include <vector>
#include <nlohmann/json_fwd.hpp>

#include "model/colors/Color.h"

enum class DrawMode {
    FILL,
    FRAME
};

class Shape {
protected:
    static char symbol;
    static int id_counter;
    int id;

    DrawMode mode;
    Color color;
    std::pair<int, int> xy;

public:
    Shape(DrawMode mode, Color color, std::pair<int, int> xy)
    : mode(mode), id(id_counter++), xy(std::move(xy)), color(color)
    {}

    ~Shape() = default;
    virtual std::shared_ptr<Shape> clone() = 0;

    virtual std::vector<std::pair<int,int>> get_px_poses() = 0;
    virtual bool contains(int x, int y) = 0;
    virtual bool set_sizes(std::vector<int>& sizes) = 0;
    virtual char get_symbol() = 0;

    virtual void to_string() = 0;
    [[nodiscard]] virtual nlohmann::json to_json() = 0;

    void set_color(Color color) {
        this->color = color;
    }

    Color get_color() {
        return color;
    }

    void set_xy(std::pair<int, int> xy) {
        this->xy = xy;
    }

    std::pair<int, int> get_xy(std::pair<int, int> xy) {
        return xy;
    }

    int get_id() {
        return id;
    }
};


#endif
