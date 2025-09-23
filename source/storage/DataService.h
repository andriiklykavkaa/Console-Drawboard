#pragma once

#include <fstream>
#include "model/figure/Shape.h"


class DataService {

public:
    explicit DataService() = default;
    ~DataService() = default;

    std::optional<std::vector<std::shared_ptr<Shape>>> load(const std::string &path);
    void save(std::vector<std::shared_ptr<Shape>>& shapes, const std::string &path);
};

