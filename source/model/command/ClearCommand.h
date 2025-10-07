#ifndef CLEARCOMMAND_H
#define CLEARCOMMAND_H
#include "Command.h"
#include "services/FigureService.h"


class ClearCommand : public Command {
private:
    bool is_trackable = false;

public:
    explicit ClearCommand() = default;
    ~ClearCommand() override = default;

    void execute() override {
        if (auto p = performer.lock())
            p->clear();
    }
};

#endif //CLEARCOMMAND_H
