
#include "InputParser.h"
#include "model/DTO/CommandDTO.h"

#include <sstream>

InputParser::InputParser(std::shared_ptr<CommandInvoker> invoker)
: invoker(std::move(invoker))
{}

void InputParser::poll_events(const std::string& input) const {
    if (input.empty()) return;
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
