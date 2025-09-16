#ifndef DATASERVICE_H
#define DATASERVICE_H
#include <string>

#include "model/figure/Shape.h"


class DataService {

public:
    explicit DataService() = default;
    ~DataService() = default;

    std::vector<std::shared_ptr<Shape>> load(std::string &path);
    void save(std::vector<std::shared_ptr<Shape>> shapes, std::string &path);
};



#endif
