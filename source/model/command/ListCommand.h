#ifndef LISTCOMMAND_H
#define LISTCOMMAND_H
#include "Command.h"
#include "services/FigureService.h"


class ListCommand : public Command {
private:
    bool is_trackable = false;
public:
    explicit ListCommand() = default;
    ~ListCommand() override = default;

    void execute() override {
        if (auto p = performer.lock())
            p->list();
    }
};



#endif
