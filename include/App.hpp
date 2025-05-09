#pragma once
#include <memory>
#include "Fifo.hpp"
#include "InputModule.hpp"
#include "OutputModule.hpp"
#include "Time.hpp"

namespace sw_project
{
class App
{
public:
    App();

    int start(int argc, char** argv);

private:
    bool running;
    std::unique_ptr<Fifo<Time> > fifo;
    InputModule inputModule;
    OutputModule outputModule;
};
}
