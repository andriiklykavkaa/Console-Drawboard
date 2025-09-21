#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <services/CommandInvoker.h>

class InputParser {
private:
    std::shared_ptr<CommandInvoker> invoker;
public:
    explicit InputParser(std::shared_ptr<CommandInvoker> invoker);
    ~InputParser() = default;
    void poll_events(const std::string& input) const;
};


#endif
