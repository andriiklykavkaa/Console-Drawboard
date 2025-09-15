#ifndef ADDCOMMANDFACTORY_H
#define ADDCOMMANDFACTORY_H
#include "CommandFactory.h"


class AddFactory : public CommandFactory {
public:
    std::shared_ptr<Command> build(std::vector<std::string> params) override;
};



#endif
