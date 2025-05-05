#pragma once
#include <memory>
#include "InputModule.hpp"
#include "OutputModule.hpp"

namespace sw_project
{
class Fifo;

class App
{
public:
    App();

    int start(int argc, char** argv);

private:
    std::shared_ptr<Fifo> fifo;
    InputModule inputModule;
    OutputModule outputModule;
};
}
