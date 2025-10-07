#include "CommandFactoryRegistry.h"

void CommandFactoryRegistry::register_fact(
    const std::tuple<std::string, std::shared_ptr<CommandFactory>> &fact_info) {
    facts[std::get<0>(fact_info)] = std::get<1>(fact_info);
}

bool CommandFactoryRegistry::is_fact_present(const std::string &name) {
    return facts.count(name) > 0;
}

std::shared_ptr<CommandFactory> CommandFactoryRegistry::get_fact(const std::string &name) {
    return (facts.count(name) > 0) ? facts.at(name) : nullptr;
}
