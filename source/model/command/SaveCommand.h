#ifndef SAVECOMMAND_H
#define SAVECOMMAND_H
#include "Command.h"
#include "services/FigureService.h"

class SaveCommand : public Command {
private:
    bool is_trackable = false;
    std::string file_name;
public:
    explicit SaveCommand(std::string file_name) : file_name(std::move(file_name)) {}
    ~SaveCommand() override = default;

    void execute() override {
        if (auto p = performer.lock())
            p->save(file_name);
    }
};



#endif //SAVECOMMAND_H
