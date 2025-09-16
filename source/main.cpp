#include <iostream>
#include "input/InputParser.h"


#include <model/commandFactory/AddFactory.h>
#include <model/commandFactory/DrawFactory.h>

#include "model/commandFactory/ClearFactory.h"
#include "model/commandFactory/DisplayFactory.h"
#include "model/commandFactory/ListFactory.h"
#include "model/commandFactory/LoadFactory.h"
#include "model/commandFactory/MoveFactory.h"
#include "model/commandFactory/PaintFactory.h"
#include "model/commandFactory/RemoveFactory.h"
#include "model/commandFactory/SaveFactory.h"
#include "model/commandFactory/SelectFactory.h"

int main() {
    auto data_service = std::make_unique<DataService>();
    auto renderer = std::make_unique<Renderer>();
    auto figure_repository = std::make_unique<FigureRepository>();

    auto figure_service = std::make_shared<FigureService>(
        std::move(data_service),
        std::move(renderer),
        std::move(figure_repository)
        );
    auto fact_registry = std::make_shared<CommandFactoryRegistry>();

    fact_registry->register_fact({std::string("draw"), std::make_shared<DrawFactory>()});
    fact_registry->register_fact({std::string("list"), std::make_shared<ListFactory>()});
    fact_registry->register_fact({std::string("display"), std::make_shared<DisplayFactory>()});
    fact_registry->register_fact({std::string("add"), std::make_shared<AddFactory>()});
    fact_registry->register_fact({std::string("select"), std::make_shared<SelectFactory>()});
    fact_registry->register_fact({std::string("remove"), std::make_shared<RemoveFactory>()});
    fact_registry->register_fact({std::string("paint"), std::make_shared<PaintFactory>()});
    fact_registry->register_fact({std::string("move"), std::make_shared<MoveFactory>()});
    fact_registry->register_fact({std::string("clear"), std::make_shared<ClearFactory>()});
    fact_registry->register_fact({std::string("save"), std::make_shared<SaveFactory>()});
    fact_registry->register_fact({std::string("load"), std::make_shared<LoadFactory>()});

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
