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
        auto iter = ids.find(id);
        return (iter != ids.end()) ? iter->second : nullptr;
    }

    std::shared_ptr<Shape> get_by_coords(int x, int y) {
        for (auto it = shapes.rbegin(); it != shapes.rend(); ++it) {
            if ((*it)->contains(x,y)) return *it;
        }
        return nullptr;
    }

    void remove_all() {
        ids.clear();
        shapes.clear();
    }

    void load_all(std::vector<std::shared_ptr<Shape>>& shapes) {
        this->shapes = std::move(shapes);
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
        auto iter = std::find_if(
            shapes.begin(),
            shapes.end(),
            [id](std::shared_ptr<Shape>& s){ return s->get_id() == id; }
        );

        if (iter == shapes.end()) return;
        auto ptr = std::move(*iter);
        shapes.erase(iter);
        shapes.push_back(std::move(ptr));
    }
};



#endif
