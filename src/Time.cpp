#include "Time.hpp"
#include <ostream>

namespace sw_project
{
std::ostream& operator<<(std::ostream& os, const Time& t)
{
    switch (t)
    {
    case Time::min25:
        os << "min25";
        break;
    case Time::min35:
        os << "min35";
        break;
    case Time::min45:
        os << "min45";
        break;
    case Time::min75:
        os << "min75";
        break;
    case Time::min85:
        os << "min85";
        break;
    default:
        os << "unknown";
        break;
    }

    return os;
}
}
