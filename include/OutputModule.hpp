#pragma once
#include <map>
#include <memory>
#include <systemc>
#include "Time.hpp"

namespace sw_project
{
class Fifo;

class OutputModule final : public sc_core::sc_module
{
public:
    explicit OutputModule(std::shared_ptr<Fifo>);

private:
    std::shared_ptr<Fifo> fifo;
    std::map<Time, bool> states;
};
}
