#include "App.hpp"
#include "Fifo.hpp"

namespace sw_project
{
App::App()
    : running{true}
    , fifo{std::make_unique<Fifo<Time> >(running)}
    , inputModule{running, *fifo}
    , outputModule{running, *fifo}
{}

int App::start(int, char**)
{
    sc_core::sc_start();
    return 0;
}
} // namespace sw_project
