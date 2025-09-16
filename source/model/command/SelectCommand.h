#ifndef SELECTCOMMAND_H
#define SELECTCOMMAND_H
#include "Command.h"
#include "services/FigureService.h"

class SelectCommand : public Command {
private:
    bool is_trackable = false;
    int shape_ID;
public:
    explicit SelectCommand(int shape_ID) : shape_ID(shape_ID) {}
    ~SelectCommand() override = default;
    void execute() override {
        if (auto p = performer.lock())
            p->select(shape_ID);
    }
};

#endif //SELECTCOMMAND_H
