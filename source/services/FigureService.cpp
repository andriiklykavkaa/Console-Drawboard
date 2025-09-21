#include "FigureService.h"

#include <iostream>

#include "CommandFactoryRegistry.h"

bool FigureService::overlap(std::shared_ptr<Shape> new_shape) {
    auto new_px_poses = new_shape->get_px_poses();

    for (auto& s : repository->get_all()) {
        if (s->get_symbol() != new_shape->get_symbol() ||
            s->get_color()  != new_shape->get_color())
            continue;

        auto s_px_poses = s->get_px_poses();
        for (auto [nx, ny] : new_px_poses) {
            for (auto [x, y] : s_px_poses) {
                if (nx == x && ny == y) {
                    return true;
                }
            }
        }
    }
    return false;
}

FigureService::FigureService(
    std::unique_ptr<DataService> data_service,
    std::unique_ptr<Board> board,
    std::unique_ptr<FigureRepository> repository)

: data_service(std::move(data_service))
, board(std::move(board))
, repository(std::move(repository))
{}

void FigureService::draw() {
    board->set_pixels(repository->get_all());
    board->draw();
}

void FigureService::list() {
    std::cout << "< SHAPES:" << std::endl;
    auto shapes_ref = repository->get_all();

    for (const auto& shape : shapes_ref)
        shape->to_string();
}

void FigureService::display() {
    std::cout << "< Square:    [col]['square'][x][y][a]" << std::endl;
    std::cout << "< Rectangle: [col]['rect'][x][y][w][h]" << std::endl;
    std::cout << "< Square:    [col]['circle'][x][y][r]" << std::endl;
}

void FigureService::add(std::shared_ptr<Shape> shape) {
    if (!board->validate(shape)) {
        std::cerr << "\nError. Shape cannot be placed." << std::endl;
        return;
    }

    if (overlap(shape)) {
        std::cerr << "\nError. Shape overlaps." << std::endl;
        return;
    }

    repository->add(shape);
}

void FigureService::select(std::variant<int, std::pair<int, int>> selector) {
    std::shared_ptr<Shape> shape;

    std::visit([&](auto &&val) {
        using T = std::decay_t<decltype(val)>;

        if constexpr (std::is_same_v<T, int>) {
            shape = repository->get_by_id(val);
        } else if constexpr (std::is_same_v<T, std::pair<int, int>>) {
            shape = repository->get_by_coords(val.first, val.second);
        }
    }, selector);


    if (shape == nullptr) {
        std::cerr << "Shape not found." << std::endl;
        return;
    }

    selected_shape = shape;
    repository->bring_to_front(shape->get_id());
}

void FigureService::remove() {
    if (selected_shape == nullptr) {
        std::cout << "No selected shape." << std::endl;
        return;
    }
    repository->remove_by_id(selected_shape->get_id());
    selected_shape = nullptr;
}

void FigureService::edit(std::vector<int> sizes) {
    if (selected_shape == nullptr) {
        std::cout << "No selected shape." << std::endl;
        return;
    }

    std::shared_ptr<Shape> copy = selected_shape->clone();
    copy->set_sizes(sizes);

    if (!board->validate(copy)) {
        std::cerr << "\nError. Shape cannot be edited" << std::endl;
        return;
    }

    if (overlap(copy)) {
        std::cerr << "\nError. Shape overlaps." << std::endl;
        return;
    }

    selected_shape = std::move(copy);
}

void FigureService::paint(Color color) {
    if (selected_shape == nullptr) {
        std::cout << "No selected shape." << std::endl;
        return;
    }

    std::shared_ptr<Shape> copy = selected_shape->clone();
    copy->set_color(color);

    if (overlap(copy)) {
        std::cerr << "\nError. Shape overlaps." << std::endl;
        return;
    }

    selected_shape->set_color(color);
}

void FigureService::move(std::pair<int, int> &coods) {
    if (selected_shape == nullptr) {
        std::cerr << "\nNo selected shape." << std::endl;
        return;
    }

    std::shared_ptr<Shape> copy = selected_shape->clone();
    copy->set_xy(coods);

    if (!board->validate(copy)) {
        std::cerr << "\nError. Shape cannot be edited" << std::endl;
        return;
    }

    if (overlap(copy)) {
        std::cerr << "\nError. Shape overlaps." << std::endl;
        return;
    }

    selected_shape = std::move(copy);
}

void FigureService::clear() {
    repository->remove_all();
}

void FigureService::save(std::string &file_name) {
    data_service->save(repository->get_all(), file_name);
}

void FigureService::load(std::string &file_name) {
    data_service->load(repository->get_all(), file_name);
}