#pragma once
#include "CommandFactory.h"


class AddFactory : public CommandFactory {
public:
    static constexpr int MIN_PARAM_COUNT = 6;
    static constexpr int RECT_PARAM_COUNT_TYPE_1 = 6;
    static constexpr int RECT_PARAM_COUNT_TYPE_2 = 7;
    static constexpr int CIRCLE_PARAM_COUNT = 6;
    static constexpr int TRIANGLE_PARAM_COUNT = 6;
    static constexpr int LINE_PARAM_COUNT = 7;

    std::shared_ptr<Command> build(const std::vector<std::string>& params) override;
};
