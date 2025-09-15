#include "DrawFactory.h"

#include <iostream>

#include "model/command/DrawCommand.h"

std::shared_ptr<Command> DrawFactory::build(std::vector<std::string> params) {
    if (!params.empty()) {
        std::cout << "Invalid command arguments. 'draw' expects no parameters" << std::endl;
        return nullptr;
    }

    auto command = std::make_shared<DrawCommand>();
    return command;
}

