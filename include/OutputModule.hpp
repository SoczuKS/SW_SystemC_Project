#pragma once
#include <map>
#include <systemc>
#include "IFifoRead.hpp"
#include "Time.hpp"

namespace sw_project
{
class OutputModule final : public sc_core::sc_module
{
public:
    OutputModule(const bool&, IFifoRead<Time>&);

    ~OutputModule() override = default;

private:
    const bool& running;
    IFifoRead<Time>& fifo;
    std::map<Time, bool> states;

    void setOutput();
};
}
