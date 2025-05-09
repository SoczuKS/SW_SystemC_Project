#pragma once
#include <systemc>

#include "IFifoRead.hpp"
#include "IFifoWrite.hpp"

namespace sw_project
{
template <class T>
class Fifo final : public sc_core::sc_module, public IFifoWrite<T>, public IFifoRead<T>
{
public:
    explicit Fifo(const bool& running)
        : sc_module(sc_core::sc_module_name{"Fifo"})
        , running{running}
        , fifo{10}
    {}

    ~Fifo() override = default;

    T read() override
    {
        T value{};
        while (!fifo.nb_read(value))
        {
            wait(fifo.data_written_event());
        }
        return value;
    }

    void write(T value) override
    {
        while (!fifo.nb_write(value))
        {
            wait(fifo.data_read_event());
        }
    }

private:
    const bool& running;
    sc_core::sc_fifo<T> fifo;
};
}
