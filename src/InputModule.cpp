#include "InputModule.hpp"
#include "Fifo.hpp"

namespace sw_project
{
InputModule::InputModule(bool& running, IFifoWrite<Time>& fifo)
    : sc_module{sc_core::sc_module_name{"InputModule"}}
    , running{running}
    , fifo{fifo}
{
    SC_THREAD(readInput);
    SC_THREAD(analyzeInputForTime25);
    SC_THREAD(analyzeInputForTime35);
    SC_THREAD(analyzeInputForTime45);
    SC_THREAD(analyzeInputForTime75);
    SC_THREAD(analyzeInputForTime85);
}

void InputModule::readInput()
{
    std::string i;
    while (running)
    {
        {
            std::lock_guard lock(inputMutex);
            if (input.has_value())
            {
                continue;
            }
            std::cout << "Input 1 - 25min, 2 - 35min, 3 - 45min, 4 - 75min, 5 - 85min, Q - exit: ";
            std::cin >> i;
            if (i == "Q")
            {
                running = false;
                break;
            }
            if (i != "1" && i != "2" && i != "3" && i != "4" && i != "5")
            {
                std::cout << "Invalid input!\n";
                continue;
            }
            input = i;
        }
        wait(0.5, sc_core::SC_SEC);
    }
}

void InputModule::analyzeInputForTime25()
{
    while (running)
    {
        {
            std::lock_guard lock(inputMutex);
            if (input.has_value() && input.value() == "1")
            {
                fifo.write(Time::min25);
                input.reset();
            }
        }
        wait(0.1, sc_core::SC_SEC);
    }
}

void InputModule::analyzeInputForTime35()
{
    while (running)
    {
        {
            std::lock_guard lock(inputMutex);
            if (input.has_value() && input.value() == "2")
            {
                fifo.write(Time::min35);
                input.reset();
            }
        }
        wait(0.1, sc_core::SC_SEC);
    }
}

void InputModule::analyzeInputForTime45()
{
    while (running)
    {
        {
            std::lock_guard lock(inputMutex);
            if (input.has_value() && input.value() == "3")
            {
                fifo.write(Time::min45);
                input.reset();
            }
        }
        wait(0.1, sc_core::SC_SEC);
    }
}

void InputModule::analyzeInputForTime75()
{
    while (running)
    {
        {
            std::lock_guard lock(inputMutex);
            if (input.has_value() && input.value() == "4")
            {
                fifo.write(Time::min75);
                input.reset();
            }
        }
        wait(0.1, sc_core::SC_SEC);
    }
}

void InputModule::analyzeInputForTime85()
{
    while (running)
    {
        {
            std::lock_guard lock(inputMutex);
            if (input.has_value() && input.value() == "5")
            {
                fifo.write(Time::min85);
                input.reset();
            }
        }
        wait(0.1, sc_core::SC_SEC);
    }
}
}
