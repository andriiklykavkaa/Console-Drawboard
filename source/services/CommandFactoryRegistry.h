#ifndef COMMANDFACTORYREGISTRY_H
#define COMMANDFACTORYREGISTRY_H
#include <map>
#include <model/commandFactory/CommandFactory.h>


class CommandFactoryRegistry {
private:
    std::map<std::string, std::shared_ptr<CommandFactory>> facts;
public:
    void register_fact(const std::tuple<std::string, std::shared_ptr<CommandFactory>> &fact_info);
    bool is_fact_present(const std::string &name);
    std::shared_ptr<CommandFactory> get_fact(const std::string& name);
};




#endif
