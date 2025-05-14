#include "OutputModule.hpp"
#include "Fifo.hpp"

namespace sw_project
{
OutputModule::OutputModule(const bool& running, IFifoRead<Time>& fifo)
    : sc_module(sc_core::sc_module_name{"OutputModule"})
    , running{running}
    , fifo{fifo}
    , states{
        {Time::min25, false},
        {Time::min35, false},
        {Time::min45, false},
        {Time::min75, false},
        {Time::min85, false}
    }
{
    SC_THREAD(setOutput);
}

void OutputModule::setOutput()
{
    while (running)
    {
        auto time = fifo.read();
        states.at(time) = !states.at(time);

        const auto enabledNum = std::count_if(states.cbegin(),
                                              states.cend(),
                                              [](const auto& it)
                                              {
                                                  return it.second;
                                              });

        if (0 == enabledNum)
        {
            std::cout << "Off\n";
        }
        else if (enabledNum == 1)
        {
            const auto enabledTime = std::find_if(states.cbegin(),
                                                  states.cend(),
                                                  [](const auto& it)
                                                  {
                                                      return it.second;
                                                  });

            if (enabledTime == states.cend())
            {
                throw std::runtime_error("Time not found in states map");
            }

            std::cout << "Time " << enabledTime->first << '\n';
        }
        else
        {
            std::cout << "Error\n";
        }

        wait(2.5, sc_core::SC_SEC);
    }
}
}
