#ifndef DRAWFACTORY_H
#define DRAWFACTORY_H
#include <iostream>

#include "CommandFactory.h"
#include "model/command/DrawCommand.h"


class DrawFactory : public CommandFactory {

public:
    DrawFactory() = default;
    ~DrawFactory() override = default;
    std::shared_ptr<Command> build(const std::vector<std::string>& params) override {
        if (!params.empty()) {
            std::cout << "Invalid command arguments. 'draw' expects no parameters" << std::endl;
            return nullptr;
        }

        std::shared_ptr<Command> command = std::make_shared<DrawCommand>();
        return command;
    }
};



#endif
