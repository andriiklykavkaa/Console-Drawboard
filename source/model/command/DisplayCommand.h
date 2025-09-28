#ifndef DISPLAYCOMMAND_H
#define DISPLAYCOMMAND_H
#include "Command.h"
#include "services/FigureService.h"


class DisplayCommand : public Command {
private:
    bool is_trackable = false;

public:
    explicit DisplayCommand() = default;
    ~DisplayCommand() override = default;

    void execute() override {
        if (auto p = performer.lock())
            p->display();
    }
};



#endif
