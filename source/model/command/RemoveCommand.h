#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include "Command.h"
#include "services/FigureService.h"

class RemoveCommand : public Command {
private:
    bool is_trackable = true;
public:
    explicit RemoveCommand() = default;
    ~RemoveCommand() override = default;
    void execute() override {
        if (auto p = performer.lock())
            p->remove();
    }
};

#endif //REMOVECOMMAND_H
