#ifndef CLEARFACTORY_H
#define CLEARFACTORY_H
#include <iostream>

#include "CommandFactory.h"
#include "model/command/ClearCommand.h"


class ClearFactory : public CommandFactory {

public:
    ClearFactory() = default;
    ~ClearFactory() override = default;
    std::shared_ptr<Command> build(std::vector<std::string> params) override {
        if (!params.empty()) {
            std::cout << "Invalid command arguments. 'draw' expects no parameters" << std::endl;
            return nullptr;
        }

        auto command = std::make_shared<ClearCommand>();
        return command;
    }
};

#endif //CLEARFACTORY_H
