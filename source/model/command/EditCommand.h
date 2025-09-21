#ifndef EDITCOMMAND_H
#define EDITCOMMAND_H
#include "Command.h"
#include "model/figure/Shape.h"


class EditCommand : public Command {
private:
    std::vector<int> sizes;
    bool is_trackable = true;
public:
    explicit EditCommand(std::vector<int> sizes) : sizes(std::move(sizes)) {}
    ~EditCommand() override = default;

    void execute() override {
        if (auto p = performer.lock())
            p->edit(sizes);
    }
};

#endif //EDITCOMMAND_H
