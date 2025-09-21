#ifndef EDITFACTORY_H
#define EDITFACTORY_H
#include "CommandFactory.h"
#include "model/command/EditCommand.h"
#include "utils/Utils.h"

class EditFactory : public CommandFactory {
public:
    EditFactory() = default;
    ~EditFactory() override = default;
    std::shared_ptr<Command> build(std::vector<std::string> params) override {
        if (params.empty()) {
            std::cerr << "Invalid command arguments. 'edit' expects parameters" << std::endl;
            return nullptr;
        }

        std::vector<int> sizes;
        for (auto& e_str: params) {
            auto e = Utils::parse_num(e_str);
            if (!e.has_value()) {
                std::cerr << "Error: invalid arguments" << std::endl;
                return nullptr;
            }
            sizes.push_back(e.value());
        }

        auto command = std::make_shared<EditCommand>(sizes);
        return command;
    }
};

#endif //EDITFACTORY_H
