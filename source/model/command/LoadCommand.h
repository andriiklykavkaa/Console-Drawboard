#ifndef LOADCOMMAND_H
#define LOADCOMMAND_H
#include "Command.h"

#include <utility>
#include "services/FigureService.h"

class LoadCommand : public Command {
private:
    bool is_trackable = false;
    std::string file_name;
public:
    explicit LoadCommand(std::string file_name): file_name(std::move(file_name)) {}
    ~LoadCommand() override = default;

    void execute() override {
        if (auto p = performer.lock())
            p->load(file_name);
    }
};

#endif //LOADCOMMAND_H
