#ifndef PAINTCOMMAND_H
#define PAINTCOMMAND_H

#include "Command.h"
#include "model/colors/Color.h"
#include "services/FigureService.h"

class PaintCommand : public Command {
private:
    bool is_trackable = true;
    Color color;
public:
    explicit PaintCommand(Color color) : color(color) {}
    ~PaintCommand() override = default;
    void execute() override {
        if (auto p = performer.lock())
            p->paint(color);
    }
};

#endif //PAINTCOMMAND_H
