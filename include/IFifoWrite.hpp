#pragma once

namespace sw_project
{
template <class T>
class IFifoWrite
{
public:
    virtual ~IFifoWrite() = default;

    virtual void write(T) = 0;
};
}
