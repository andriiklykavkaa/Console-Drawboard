#ifndef IFIGURE_H
#define IFIGURE_H

#include <memory>
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
    int id = 0;

    DrawMode mode = DrawMode::FILL;
    Color color = Color::WHITE;
    std::pair<int, int> xy = {0, 0};

public:
    Shape(DrawMode mode, Color color, std::pair<int, int> xy);
    virtual ~Shape();

    virtual std::shared_ptr<Shape> clone() = 0;

    virtual std::vector<std::pair<int,int>> get_px_poses() = 0;
    virtual bool contains(int x, int y) = 0;
    virtual void set_sizes(std::vector<int>& sizes) = 0;

    int get_id() const;
    virtual char get_symbol() = 0;

    void set_color(Color color);
    Color get_color() const;

    void set_xy(std::pair<int, int> xy);
    std::pair<int, int> get_xy() const;

    virtual void to_string() = 0;
    virtual nlohmann::json to_json() = 0;
};

#endif
