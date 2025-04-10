#include "Controller.hpp"

namespace sw_project
{
Controller::Controller()
    : states{
        {Time::min25, false},
        {Time::min35, false},
        {Time::min45, false},
        {Time::min75, false},
        {Time::min85, false}
    } {}
}
