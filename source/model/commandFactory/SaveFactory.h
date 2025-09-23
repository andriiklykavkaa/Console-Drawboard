#ifndef SAVEFACTORY_H
#define SAVEFACTORY_H
#include <iostream>

#include "CommandFactory.h"
#include "model/command/SaveCommand.h"


class SaveFactory : public CommandFactory {

public:
    SaveFactory() = default;
    ~SaveFactory() override = default;
    std::shared_ptr<Command> build(const std::vector<std::string>& params) override {
        if (params.size() != 1) {
            std::cout << "Invalid command arguments. 'save' expects 1 parameter 'path'" << std::endl;
            return nullptr;
        }

        std::shared_ptr<Command> command = std::make_shared<SaveCommand>(params.at(0));
        return command;
    }
};


#endif //SAVEFACTORY_H
