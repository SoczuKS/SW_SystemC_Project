#pragma once
#include <map>

#include "Time.hpp"

namespace sw_project
{
class Controller
{
public:
    Controller();

private:
    std::map<Time, bool> states;
};
}
