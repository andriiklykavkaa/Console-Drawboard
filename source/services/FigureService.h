#ifndef FIGURESERVICE_H
#define FIGURESERVICE_H
#include <memory>
#include <model/command/Command.h>


class Shape;

class FigureService {
private:
    std::shared_ptr<Shape> selected_shape = nullptr;

public:
    void receive(std::shared_ptr<Command> &command);

};



#endif
