#ifndef SELECTCOMMAND_H
#define SELECTCOMMAND_H
#include "Command.h"

#include <utility>
#include "services/FigureService.h"

typedef std::variant<int, std::pair<int, int>> Selector;

class SelectCommand : public Command {
private:
    bool is_trackable = false;
    std::variant<int, std::pair<int, int>> selector;
public:
    explicit SelectCommand(Selector selector) : selector(std::move(selector)) {}
    ~SelectCommand() override = default;
    void execute() override {
        if (auto p = performer.lock())
            p->select(selector);
    }
};

#endif //SELECTCOMMAND_H
