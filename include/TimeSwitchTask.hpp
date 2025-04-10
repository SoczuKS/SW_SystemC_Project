#pragma once
#include "Time.hpp"

namespace sw_project
{
class TimeSwitchTask {
public:
    explicit TimeSwitchTask(Time);

    [[nodiscard]] const Time& getTime() const;

private:
    const Time time;
};
}
