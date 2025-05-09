#pragma once
#include <ostream>

namespace sw_project
{
enum class Time : std::int8_t
{
    unknown = -1,
    min25 = 25,
    min35 = 35,
    min45 = 45,
    min75 = 75,
    min85 = 85
};

std::ostream& operator<<(std::ostream& os, const Time& t);
}
