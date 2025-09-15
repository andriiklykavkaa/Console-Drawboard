#include <iostream>
#include <model/commandFactory/AddFactory.h>
#include <model/commandFactory/DrawFactory.h>

#include "input/InputParser.h"

int main() {
    auto figure_service = std::make_shared<FigureService>();
    auto fact_registry = std::make_shared<CommandFactoryRegistry>();

    fact_registry->register_fact({std::string("draw"), std::make_shared<DrawFactory>()});
    fact_registry->register_fact({std::string("add"), std::make_shared<AddFactory>()});

    auto invoker = std::make_shared<CommandInvoker>(fact_registry, figure_service);
    auto parser = std::make_shared<InputParser>(invoker);

    std::cout << "Welcome to FigureBoard!" << std::endl;
    std::string input;
    while (true) {

        std::cout << "Enter command: ";
        std::getline(std::cin, input);
        parser->poll_events(input);
    }
    return 0;
}
