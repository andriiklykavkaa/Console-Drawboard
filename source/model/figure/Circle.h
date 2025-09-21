#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"


class Circle : public Shape {
private:
    int r;

public:
    Circle(DrawMode mode, Color color, std::pair<int, int> xy, int r);
    std::shared_ptr<Shape> clone() override;

    std::vector<std::pair<int,int>> get_px_poses() override;
    bool contains(int x, int y) override;
    void set_sizes(std::vector<int>& sizes) override;
    char get_symbol() override;

    void to_string() override;
    nlohmann::json to_json() override;
    static std::shared_ptr<Circle> from_json(const nlohmann::json& json);
};




#endif
