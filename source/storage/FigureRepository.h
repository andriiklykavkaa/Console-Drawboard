#ifndef FIGUREREPOSITORY_H
#define FIGUREREPOSITORY_H

#include <unordered_map>
#include <vector>
#include <memory>

#include "model/figure/Shape.h"

class FigureRepository {
private:
    std::vector<std::shared_ptr<Shape>> shapes;
    std::pmr::unordered_map<int, std::shared_ptr<Shape>> ids;

public:
    explicit FigureRepository();
    ~FigureRepository();

    void add(const std::shared_ptr<Shape>& shape);

    std::vector<std::shared_ptr<Shape>>& get_all();
    std::shared_ptr<Shape> get_by_id(int id);
    std::shared_ptr<Shape> get_by_coords(int x, int y);

    void remove_all();
    void remove_by_id(int id);
    void bring_to_front(int id);

    void load_all(std::vector<std::shared_ptr<Shape>>& shapes);
};

#endif // FIGUREREPOSITORY_H
