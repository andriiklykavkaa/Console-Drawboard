#ifndef LISTFACTORY_H
#define LISTFACTORY_H

#include <iostream>

#include "CommandFactory.h"
#include "model/command/ListCommand.h"


class ListFactory : public CommandFactory {

public:
    ListFactory() = default;
    ~ListFactory() override = default;
    std::shared_ptr<Command> build(std::vector<std::string> params) override {
        if (!params.empty()) {
            std::cout << "Invalid command arguments. 'draw' expects no parameters" << std::endl;
            return nullptr;
        }

        auto command = std::make_shared<ListCommand>();
        return command;
    }
};


#endif //LISTFACTORY_H
