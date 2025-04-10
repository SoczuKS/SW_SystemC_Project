#include "TimeSwitchTask.hpp"

namespace sw_project
{
TimeSwitchTask::TimeSwitchTask(const Time time) : time{time} {}

const Time& TimeSwitchTask::getTime() const
{
    return time;
}
}
