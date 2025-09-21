#include "DataService.h"

#include <iostream>
#include <nlohmann/json.hpp>

#include "model/figure/Circle.h"
#include "model/figure/Line.h"
#include "model/figure/Rectangle.h"
#include "model/figure/Triangle.h"

using json = nlohmann::json;

void DataService::load(std::vector<std::shared_ptr<Shape>>& shapes, std::string &path) {
    std::ifstream file(path);
    nlohmann::json json;
    file >> json;

    std::vector<std::shared_ptr<Shape>> res;
    for (auto& e: json) {
        try {
            std::string type = e.at("type").get<std::string>();
            if (type == "rectangle") res.emplace_back(Rectangle::from_json(e));
            else if (type == "circle")    res.emplace_back(Circle::from_json(e));
            else if (type == "triangle")  res.emplace_back(Triangle::from_json(e));
            else if (type == "line")  res.emplace_back(Line::from_json(e));
        } catch (std::exception& e) {
            std::cerr << "\nError: Invalid shape in JSON: " << e.what() << std::endl;
            return;
        }
    }

    shapes = std::move(res);
}

void DataService::save(std::vector<std::shared_ptr<Shape>>& shapes, std::string &path) {
    nlohmann::json json = json::array();
    for (auto& s: shapes) {
        json.push_back(s->to_json());
    }
    std::ofstream file(path);
    file << json.dump(4);
}