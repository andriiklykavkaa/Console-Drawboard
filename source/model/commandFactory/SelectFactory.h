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
        if (tokens.size() != 1 && tokens.size() != 2) {
            std::cout << "Invalid command arguments. 'select' expects 1 param ID" << std::endl;
            return nullptr;
        }

        if (tokens.size() == 1) {
            auto ID  = Utils::parse_num(tokens.at(0));
            if (!ID.has_value())
                return nullptr;

            auto command = std::make_shared<SelectCommand>(ID.value());
            return command;
        }

        if (tokens.size() == 2) {
            auto x  = Utils::parse_num(tokens.at(0));
            auto y  = Utils::parse_num(tokens.at(1));
            if (!x.has_value() || !y.has_value())
                return nullptr;

            auto command = std::make_shared<SelectCommand>(std::make_pair(x.value(), y.value()));
            return command;
        }

        return nullptr;
    }
};


#endif //SELECTFACTORY_H
