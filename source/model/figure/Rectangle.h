#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
#include "model/colors/Color.h"


class Rectangle : public Shape {
private:
    std::pair<int,int> wh = {0, 0};

public:
    Rectangle(DrawMode mode, Color color, std::pair<int, int> xy, std::pair<int,int> hw);
    std::shared_ptr<Shape> clone() override;

    std::vector<std::pair<int,int>> get_px_poses() override;
    bool contains(int x, int y) override;
    void set_sizes(std::vector<int>& sizes) override;
    char get_symbol() override;

    void to_string() override;
    nlohmann::json to_json() override;
    static std::shared_ptr<Rectangle> from_json(const nlohmann::json& json);
};



#endif
