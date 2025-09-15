#ifndef DRAWFACTORY_H
#define DRAWFACTORY_H
#include "CommandFactory.h"


class DrawFactory : public CommandFactory {

public:
    DrawFactory() = default;
    ~DrawFactory() override = default;
    std::shared_ptr<Command> build(std::vector<std::string> params) override;
};



#endif
