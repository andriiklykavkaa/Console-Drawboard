
#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H

#include "Command.h"
#include "services/FigureService.h"


class DrawCommand : public Command {
private:
    bool is_trackable = false;
public:
    DrawCommand() = default;
    ~DrawCommand() override = default;
    void execute() override {
        if (auto p = performer.lock())
            p->draw();
    }
};



#endif //DRAWCOMMAND_H
