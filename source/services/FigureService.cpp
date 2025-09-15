#include "FigureService.h"

#include <iostream>


void FigureService::receive(std::shared_ptr<Command> &command) {
    std::cout << "Command received" << std::endl;
}
