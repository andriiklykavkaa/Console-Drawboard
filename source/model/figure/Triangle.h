#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"


class Triangle : public Shape {
private:
    int h;

public:
    Triangle(DrawMode mode, Color color, std::pair<int, int> xy, int h);
    std::shared_ptr<Shape> clone() override;

    std::vector<std::pair<int,int>> get_px_poses() override;
    bool contains(int x, int y) override;
    void set_sizes(std::vector<int>& sizes) override;
    char get_symbol() override;

    void to_string() override;
    nlohmann::json to_json() override;
    static std::shared_ptr<Triangle> from_json(nlohmann::json& json);
};



#endif
