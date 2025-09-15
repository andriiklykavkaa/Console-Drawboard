
#include "AddCommand.h"

#include <iostream>
#include <utility>

AddCommand::AddCommand(std::shared_ptr<Shape> shape)
    : shape(std::move(shape))
{}


void AddCommand::execute() {
    std::cout << "'add' executed";
}
