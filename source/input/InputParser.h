
#ifndef INPUTPARSER_H
#define INPUTPARSER_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <services/CommandInvoker.h>

#include "../model/DTO/CommandDTO.h"
/*
 * COMMANDS:
 * help - get command list
 * draw - draw the board
 * shapes - get figure list
 * add [fill/frame][shape][params] - add a shape
 * select [ID]/[coords] - select a shape
 * remove [ID] - remove a shape
 * edit - [pa]
 */

class InputParser {
private:
    std::shared_ptr<CommandInvoker> invoker;
public:
    explicit InputParser(std::shared_ptr<CommandInvoker> invoker);
    ~InputParser() = default;
    void poll_events(const std::string& input) const;
};


#endif
