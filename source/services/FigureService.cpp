#include "FigureService.h"

#include <iostream>


FigureService::FigureService(
    std::unique_ptr<DataService> data_service,
    std::unique_ptr<Renderer> renderer,
    std::unique_ptr<FigureRepository> repository)

: data_service(std::move(data_service))
, renderer(std::move(renderer))
, repository(std::move(repository))
{}

void FigureService::draw() {
    this->renderer->render();
}

void FigureService::list() {
    std::cout << "< SHAPES:" << std::endl;
    auto shapes_ref = repository->get_shapes();

    for (const auto& shape : shapes_ref)
        shape->to_string();
}

void FigureService::display() {
    std::cout << "< Square:    [col]['square'][x][y][a]" << std::endl;
    std::cout << "< Rectangle: [col]['rect'][x][y][w][h]" << std::endl;
    std::cout << "< Square:    [col]['circle'][x][y][r]" << std::endl;
}

void FigureService::add(std::shared_ptr<Shape> shape) {
    repository->add(shape);
}

void FigureService::select(int id) {
    std::shared_ptr<Shape> shape = repository->get_by_id(id);
    if (shape == nullptr) {
        std::cerr << "Shape not found." << std::endl;
        return;
    }

    selected_shape = shape;
    repository->bring_to_front(id);
}

void FigureService::remove() {
    if (selected_shape == nullptr)
        std::cout << "No selected shape." << std::endl;
    else {
        repository->remove_by_id(selected_shape->get_id());
        selected_shape == nullptr;
    }
}

// void FigureService::edit() {
//     return;
// }

void FigureService::paint(Color color) {
    if (selected_shape == nullptr)
        std::cout << "No selected shape." << std::endl;
    else
        selected_shape->set_color(color);
}

void FigureService::move(std::pair<int, int> &coods) {
    if (selected_shape == nullptr)
        std::cout << "No selected shape." << std::endl;
    else
        selected_shape->set_xy(coods);
}

void FigureService::clear() {
    repository->remove_all();
}

void FigureService::save(std::string &file_name) {
    data_service->save(repository->get_all(), file_name);
}

void FigureService::load(std::string &file_name) {
    repository->load_all(data_service->load(file_name));
}