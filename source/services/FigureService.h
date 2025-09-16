#ifndef FIGURESERVICE_H
#define FIGURESERVICE_H


#include <vector>
#include <model/command/Command.h>

#include "infrastructure/DataService.h"
#include "infrastructure/FigureRepository.h"
#include "infrastructure/Renderer.h"
#include "model/colors/Color.h"

class Shape;

class FigureService {
private:
    std::unique_ptr<DataService> data_service;
    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<FigureRepository> repository;

    std::shared_ptr<Shape> selected_shape = nullptr;
    std::vector<std::shared_ptr<Shape>> shapes;

public:
    FigureService(
        std::unique_ptr<DataService> data_service,
        std::unique_ptr<Renderer> renderer,
        std::unique_ptr<FigureRepository> repository
        );
    ~FigureService() = default;

    void draw();
    void list();
    void display(); // 'shapes' command
    void add(std::shared_ptr<Shape>);
    void select(int ID);
    void remove();
    // void edit();
    void paint(Color color);
    void move(std::pair<int, int>& coords);
    void clear();

    void load(std::string &file_name);
    void save(std::string &file_name);

};


#endif
