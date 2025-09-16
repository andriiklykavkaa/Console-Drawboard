
#include "CommandInvoker.h"

#include <iostream>
#include <utility>
#include <model/commandFactory/AddFactory.h>
#include <model/commandFactory/DrawFactory.h>

CommandInvoker::CommandInvoker(
    std::shared_ptr<CommandFactoryRegistry> fact_registry,
    std::shared_ptr<FigureService> figure_service)
: fact_registry(std::move(fact_registry))
, figure_service(std::move(figure_service))
{}

std::shared_ptr<Command> CommandInvoker::build_command(const std::shared_ptr<CommandDTO> &dto) const {
    if (!fact_registry->is_fact_present(dto->name)) {
        std::cout << "Unrecognized command." << std::endl;
        return nullptr;
    }
    auto fact = fact_registry->get_fact(dto->name);
    auto command = fact->build(dto->params);
    return command;
}


void CommandInvoker::receive(const std::optional<CommandDTO> &dto) const {
    if (!dto.has_value())
        return;

    auto command_data = std::make_shared<CommandDTO>(dto.value());
    std::shared_ptr<Command> command = this->build_command(command_data);
    if (command == nullptr) return;

    this->invoke(command);
}

void CommandInvoker::invoke(std::shared_ptr<Command> &command) const {
    command->set_performer(figure_service);
    command->execute();
}

