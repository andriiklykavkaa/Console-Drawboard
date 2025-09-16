#ifndef PAINTFACTORY_H
#define PAINTFACTORY_H
#include <iostream>

#include "CommandFactory.h"
#include "model/command/PaintCommand.h"
#include "utils/Utils.h"


class PaintFactory : public CommandFactory {

public:
    PaintFactory() = default;
    ~PaintFactory() override = default;
    std::shared_ptr<Command> build(std::vector<std::string> tokens) override {
        if (tokens.size() != 1) {
            std::cout << "Invalid command arguments. 'select' expects 1 param ID" << std::endl;
            return nullptr;
        }

        auto color  = Utils::parse_color(tokens.at(0));
        if (!color.has_value())
            return nullptr;

        auto command = std::make_shared<PaintCommand>(color.value());
        return command;
    }
};

#endif //PAINTFACTORY_H
