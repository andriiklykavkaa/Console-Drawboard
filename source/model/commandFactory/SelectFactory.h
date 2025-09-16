#ifndef SELECTFACTORY_H
#define SELECTFACTORY_H

#include <iostream>

#include "CommandFactory.h"
#include "model/command/ListCommand.h"
#include "model/command/SelectCommand.h"
#include "utils/Utils.h"


class SelectFactory : public CommandFactory {

public:
    SelectFactory() = default;
    ~SelectFactory() override = default;
    std::shared_ptr<Command> build(std::vector<std::string> tokens) override {
        if (tokens.size() != 1) {
            std::cout << "Invalid command arguments. 'select' expects 1 param ID" << std::endl;
            return nullptr;
        }

        auto ID  = Utils::parse_num(tokens.at(0));
        if (!ID.has_value())
            return nullptr;

        auto command = std::make_shared<SelectCommand>(ID.value());
        return command;
    }
};


#endif //SELECTFACTORY_H
