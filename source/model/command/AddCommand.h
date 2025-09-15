
#ifndef ADDCOMMAND_H
#define ADDCOMMAND_H
#include "Command.h"
#include "model/colors/Color.h"
#include "model/figure/Shape.h"


class AddCommand : public Command {
private:
    std::shared_ptr<Shape> shape;
    bool is_trackable = true;
public:
    AddCommand(std::shared_ptr<Shape>);
    ~AddCommand() = default;

    void execute() override;
};



#endif
