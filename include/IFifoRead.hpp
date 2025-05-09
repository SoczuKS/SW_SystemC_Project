#pragma once

namespace sw_project
{
template <class T>
class IFifoRead
{
public:
    virtual ~IFifoRead() = default;

    virtual T read() = 0;
};
}
