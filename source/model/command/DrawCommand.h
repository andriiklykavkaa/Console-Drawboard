
#ifndef DRAWCOMMAND_H
#define DRAWCOMMAND_H
#include "Command.h"


class DrawCommand : public Command {
private:
    bool is_trackable = false;
public:
    DrawCommand() = default;
    ~DrawCommand() = default;
    void execute() override;
};



#endif //DRAWCOMMAND_H
