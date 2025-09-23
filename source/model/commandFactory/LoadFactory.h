#ifndef LOADFACTORY_H
#define LOADFACTORY_H
#include <iostream>

#include "CommandFactory.h"
#include "model/command/LoadCommand.h"


class LoadFactory : public CommandFactory {

public:
    LoadFactory() = default;
    ~LoadFactory() override = default;
    std::shared_ptr<Command> build(const std::vector<std::string>& params) override {
        if (params.size() != 1) {
            std::cout << "Invalid command arguments. 'load' expects 1 parameter 'path'" << std::endl;
            return nullptr;
        }

        std::shared_ptr<Command> command = std::make_shared<LoadCommand>(params.at(0));
        return command;
    }
};

#endif //LOADFACTORY_H
