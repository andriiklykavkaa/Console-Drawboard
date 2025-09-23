#include "DataService.h"

#include <iostream>
#include <nlohmann/json.hpp>

#include "model/figure/Circle.h"
#include "model/figure/Line.h"
#include "model/figure/Rectangle.h"
#include "model/figure/Triangle.h"

using json = nlohmann::json;

std::optional<std::vector<std::shared_ptr<Shape>>> DataService::load(const std::string &path) {
    std::ifstream file(path);

    if (!file.is_open()) {
        std::cerr << "\nError: Cannot open file." << std::endl;
        return std::nullopt;
    }

    nlohmann::json json;
    file >> json;

    std::vector<std::shared_ptr<Shape>> res;
    for (nlohmann::basic_json<>& e: json) {
        try {
            std::string type = e.at("type").get<std::string>();
            if (type == "rectangle") res.emplace_back(Rectangle::from_json(e));
            else if (type == "circle")    res.emplace_back(Circle::from_json(e));
            else if (type == "triangle")  res.emplace_back(Triangle::from_json(e));
            else if (type == "line")  res.emplace_back(Line::from_json(e));

            res.back()->to_string();
        } catch (std::exception& e) {
            std::cerr << "\nError: Invalid shape in JSON: " << e.what() << std::endl;
            return std::nullopt;
        }
    }

    return std::make_optional(res);
}

void DataService::save(std::vector<std::shared_ptr<Shape>>& shapes, const std::string &path) {
    nlohmann::json json = json::array();
    for (std::shared_ptr<Shape>& s: shapes) {
        json.push_back(s->to_json());
    }
    std::ofstream file(path);
    file << json.dump(4);
}