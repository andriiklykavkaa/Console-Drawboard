#ifndef FIGUREREPOSITORY_H
#define FIGUREREPOSITORY_H
#include <unordered_map>
#include <vector>

#include "model/figure/Shape.h"


class FigureRepository {
private:
    std::vector<std::shared_ptr<Shape>> shapes;

    std::pmr::unordered_map<int, std::shared_ptr<Shape>> ids;
public:
    explicit FigureRepository() = default;
    ~FigureRepository() = default;

    void add(const std::shared_ptr<Shape> &shape) {
        ids[shape->get_id()] = shape;
        shapes.push_back(shape);
    }

    std::vector<std::shared_ptr<Shape>>& get_all() {
        return shapes;
    }

    std::shared_ptr<Shape> get_by_id(int id) {
        std::shared_ptr<Shape> shape = ids.find(id);
        return (shape != ids.end()) ? shape : nullptr;
    }

    void remove_all() {
        ids.clear();
        shapes.clear();
    }

    void load_all(std::vector<std::shared_ptr<Shape>>& shapes) {
        this->shapes = shapes;
        for (const auto& s : shapes) {
            ids[s->get_id()] = s;
        }
    }

    void remove_by_id(int id) {
        ids.erase(id);
        shapes.erase(
            std::remove_if(
                shapes.begin(),
                shapes.end(),
                [id](const auto& s){return s->get_id() == id; }
            ), shapes.end()
        );
    }

    void bring_to_front(int id) {
        auto shape = std::find_if(
            shapes.begin(),
            shapes.end(),
            [id](std::shared_ptr<Shape>& s){ return s->get_id() == id; }
        );

        if (shape == shapes.end()) return;

        shapes.erase(shape);
        shapes.push_back(shape);
    }
};



#endif
