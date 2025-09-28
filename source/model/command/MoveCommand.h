#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H
#include "Command.h"
#include "services/FigureService.h"

class MoveCommand : public Command {
private:
    bool is_trackable = true;
    std::pair<int, int> coords;
public:
    explicit MoveCommand(std::pair<int, int> coords) : coords(std::move(coords)) {}
    ~MoveCommand() override = default;
    void execute() override {
        if (auto p = performer.lock())
            p->move(coords);
    }
};


#endif //MOVECOMMAND_H
