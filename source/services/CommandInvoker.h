
#ifndef COMMANDINVOKER_H
#define COMMANDINVOKER_H
#include <model/commandFactory/CommandFactory.h>

#include "FigureService.h"
#include "services/CommandFactoryRegistry.h"
#include "model/command/Command.h"
#include "model/DTO/CommandDTO.h"


class CommandInvoker {
private:
    std::shared_ptr<CommandFactoryRegistry> fact_registry;
    std::shared_ptr<FigureService> figure_service;

    [[nodiscard]] std::shared_ptr<Command> build_command(const std::shared_ptr<CommandDTO> &dto) const;
public:
    explicit CommandInvoker(
        std::shared_ptr<CommandFactoryRegistry> fact_registry,
        std::shared_ptr<FigureService> figure_service);
    ~CommandInvoker() = default;

    void receive(const std::optional<CommandDTO> &dto) const;
    void invoke(const std::shared_ptr<Command> &command) const;
};



#endif

