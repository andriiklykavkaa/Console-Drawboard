#include "storage/FigureRepository.h"

#include <algorithm>
#include <iostream>

FigureRepository::FigureRepository() = default;
FigureRepository::~FigureRepository() = default;

void FigureRepository::add(const std::shared_ptr<Shape>& shape) {
    ids[shape->get_id()] = shape;
    shapes.push_back(shape);
}

std::vector<std::shared_ptr<Shape>>& FigureRepository::get_all() {
    return shapes;
}

std::shared_ptr<Shape> FigureRepository::get_by_id(int id) {
    auto iter = ids.find(id);
    return (iter != ids.end()) ? iter->second : nullptr;
}

std::shared_ptr<Shape> FigureRepository::get_by_coords(int x, int y) {
    for (auto it = shapes.rbegin(); it != shapes.rend(); ++it) {
        if ((*it)->contains(x, y)) return *it;
    }
    return nullptr;
}

void FigureRepository::remove_all() {
    ids.clear();
    shapes.clear();
}

void FigureRepository::load_all(std::vector<std::shared_ptr<Shape>>& shapes) {
    ids.clear();
    this->shapes = std::move(shapes);

    for (const auto& s : this->shapes) {
        ids[s->get_id()] = s;
    }
}

void FigureRepository::remove_by_id(int id) {
    ids.erase(id);
    shapes.erase(
        std::remove_if(
            shapes.begin(),
            shapes.end(),
            [id](const auto& s) { return s->get_id() == id; }
        ),
        shapes.end()
    );
}

void FigureRepository::bring_to_front(int id) {
    auto iter = std::find_if(
        shapes.begin(),
        shapes.end(),
        [id](std::shared_ptr<Shape>& s) { return s->get_id() == id; }
    );

    if (iter == shapes.end()) return;

    auto ptr = std::move(*iter);
    shapes.erase(iter);
    shapes.push_back(std::move(ptr));
}
