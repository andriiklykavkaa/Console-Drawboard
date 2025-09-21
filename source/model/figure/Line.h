#ifndef LINE_H
#define LINE_H
#include "Shape.h"


class Line : public Shape {
private:
    std::pair<int,int> vec;

public:
    Line(DrawMode mode, Color color, std::pair<int, int> axy, std::pair<int,int> bxy);
    std::shared_ptr<Shape> clone() override;

    std::vector<std::pair<int,int>> get_px_poses() override;
    bool contains(int x, int y) override;
    void set_sizes(std::vector<int>& sizes) override;
    char get_symbol() override;

    void to_string() override;
    nlohmann::json to_json() override;
    static std::shared_ptr<Line> from_json(const nlohmann::json& json);
};


#endif
