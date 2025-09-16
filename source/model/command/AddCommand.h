
#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H
#include "Command.h"
#include "model/figure/Shape.h"
#include "services/FigureService.h"


class AddCommand : public Command {
private:
    std::shared_ptr<Shape> shape;
    bool is_trackable = true;
public:
    explicit AddCommand(std::shared_ptr<Shape> shape) : shape(std::move(shape)) {}
    ~AddCommand() override = default;

    void execute() override {
        if (auto p = performer.lock())
            p->add(shape);
    }
};



#endif
