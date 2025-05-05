#pragma once
#include <memory>
#include <systemc>

namespace sw_project
{
class Fifo;

class InputModule final : public sc_core::sc_module
{
public:
    explicit InputModule(std::shared_ptr<Fifo>);

private:
    std::shared_ptr<Fifo> fifo;
};
}
