#include "InputModule.hpp"
#include "Fifo.hpp"

namespace sw_project
{
InputModule::InputModule(std::shared_ptr<Fifo> fifo)
    : fifo{std::move(fifo)}
{}
}
