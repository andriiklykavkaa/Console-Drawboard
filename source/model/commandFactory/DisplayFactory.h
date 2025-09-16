#ifndef DISPLAYFACTORY_H
#define DISPLAYFACTORY_H
#include <iostream>
#include <memory>

#include "CommandFactory.h"
#include "model/command/DisplayCommand.h"


class DisplayFactory : public CommandFactory {

public:
    DisplayFactory() = default;
    ~DisplayFactory() override = default;
    std::shared_ptr<Command> build(std::vector<std::string> params) override {
        if (!params.empty()) {
            std::cout << "Invalid command arguments. 'draw' expects no parameters" << std::endl;
            return nullptr;
        }

        auto command = std::make_shared<DisplayCommand>();
        return command;
    }
};


#endif //DISPLAYFACTORY_H
