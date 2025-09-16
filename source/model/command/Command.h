#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <cstdint>
#include <memory>
#include <utility>

class FigureService;

class Command {
private:
    static uint32_t ID_counter;
    uint32_t ID;

protected:
    std::weak_ptr<FigureService> performer;
    bool is_trackable = false;

public:
    virtual ~Command() = default;

    virtual void execute() = 0;

    uint32_t get_ID() const {
        return ID;
    }

    bool get_trackable() const {
        return this->is_trackable;
    }

    void set_performer(std::weak_ptr<FigureService> p) {
        this->performer = p;
    }
};

#endif
