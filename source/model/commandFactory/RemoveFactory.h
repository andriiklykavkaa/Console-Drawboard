#ifndef REMOVEFACTORY_H
#define REMOVEFACTORY_H
#include <iostream>

#include "CommandFactory.h"
#include "model/command/RemoveCommand.h"

class RemoveFactory : public CommandFactory {

public:
    RemoveFactory() = default;
    ~RemoveFactory() override = default;
    std::shared_ptr<Command> build(const std::vector<std::string>& params) override {
        if (!params.empty()) {
            std::cout << "Invalid command arguments. 'remove' expects no parameters" << std::endl;
            return nullptr;
        }

        std::shared_ptr<Command> command = std::make_shared<RemoveCommand>();
        return command;
    }
};

#endif //REMOVEFACTORY_H
