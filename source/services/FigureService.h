#ifndef FIGURESERVICE_H
#define FIGURESERVICE_H


#include <vector>
#include "storage/DataService.h"
#include "storage/FigureRepository.h"
#include "model/colors/Color.h"
#include "model/render/Board.h"

class Shape;

class FigureService {
private:
    std::unique_ptr<DataService> data_service;
    std::unique_ptr<Board> board;
    std::unique_ptr<FigureRepository> repository;

    std::shared_ptr<Shape> selected_shape = nullptr;
    std::vector<std::shared_ptr<Shape>> shapes;

    bool overlap(const std::shared_ptr<Shape> &shape);

public:
    FigureService(
        std::unique_ptr<DataService> data_service,
        std::unique_ptr<Board> board,
        std::unique_ptr<FigureRepository> repository
        );
    ~FigureService() = default;

    void draw();
    void list();
    void display();
    void add(const std::shared_ptr<Shape>&);
    void select(std::variant<int, std::pair<int, int>> selector);
    void remove();
    void edit(std::vector<int> &sizes);
    void paint(Color color);
    void move(const std::pair<int, int>& coords);
    void clear();

    void load(const std::string &file_name);
    void save(const std::string &file_name);

};


#endif
