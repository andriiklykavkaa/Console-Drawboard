

#ifndef COMMANDDTO_H
#define COMMANDDTO_H
#include <string>

struct CommandDTO {
    std::string name;
    std::vector<std::string> params;
};

#endif //COMMANDDTO_H
