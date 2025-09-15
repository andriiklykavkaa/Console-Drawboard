
#include "InputParser.h"

#include <utility>

#include "model/DTO/CommandDTO.h"

InputParser::InputParser(std::shared_ptr<CommandInvoker> invoker)
: invoker(std::move(invoker))
{}

void InputParser::poll_events(const std::string& input) const {
    std::istringstream iss(input);

    std::vector<std::string> tokens;
    std::string word;

    while (iss >> word)
        tokens.push_back(word);

    if (tokens.empty())
        invoker->receive(std::nullopt);

    std::string name = tokens.at(0);
    tokens.erase(tokens.begin());
    invoker->receive(CommandDTO{name, tokens});
}
