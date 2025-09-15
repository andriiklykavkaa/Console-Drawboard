#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include "model/command/Command.h"
#include <memory>
#include <string>
#include <vector>
#include <model/command/AddCommand.h>

class CommandFactory {
private:

public:
    virtual ~CommandFactory() = default;
    virtual std::shared_ptr<Command> build(std::vector<std::string> params) = 0;
};



#endif
