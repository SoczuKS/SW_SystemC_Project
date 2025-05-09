#pragma once
#include <optional>
#include <systemc>
#include "IFifoWrite.hpp"
#include "Time.hpp"

namespace sw_project
{
class InputModule final : public sc_core::sc_module
{
public:
    InputModule(bool& running, IFifoWrite<Time>&);

private:
    void readInput();

    void analyzeInputForTime25();

    void analyzeInputForTime35();

    void analyzeInputForTime45();

    void analyzeInputForTime75();

    void analyzeInputForTime85();

    bool& running;
    IFifoWrite<Time>& fifo;
    std::optional<std::string> input;
    std::mutex inputMutex;
};
}
