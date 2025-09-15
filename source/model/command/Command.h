#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <cstdint>

class Command {
private:
    static uint32_t ID_counter;
    uint32_t ID;
    bool is_trackable = false;

public:
    virtual void execute() = 0;

    uint32_t get_ID() const {
        return ID;
    }

    bool get_trackable() const {
        return this->is_trackable;
    }
};

#endif
