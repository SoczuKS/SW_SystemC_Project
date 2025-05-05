#include "App.hpp"
#include "Fifo.hpp"

namespace sw_project
{
App::App()
    : fifo{std::make_shared<Fifo>()}
    , inputModule{fifo}
    , outputModule{fifo}
{}

int App::start(int argc, char** argv)
{
    return 0;
}
} // namespace sw_project
