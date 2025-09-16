#ifndef MOVEFACTORY_H
#define MOVEFACTORY_H
#include <iostream>

#include "CommandFactory.h"
#include "model/command/MoveCommand.h"
#include "utils/Utils.h"


class MoveFactory : public CommandFactory {

public:
    MoveFactory() = default;
    ~MoveFactory() override = default;
    std::shared_ptr<Command> build(std::vector<std::string> tokens) override {
        if (tokens.size() != 2) {
            std::cout << "Invalid command arguments. 'move' expects 2 coords" << std::endl;
            return nullptr;
        }

        auto coords  = Utils::parse_coords(tokens.at(0), tokens.at(1));
        if (!coords.has_value())
            return nullptr;

        auto command = std::make_shared<MoveCommand>(coords.value());
        return command;
    }
};


#endif //MOVEFACTORY_H
