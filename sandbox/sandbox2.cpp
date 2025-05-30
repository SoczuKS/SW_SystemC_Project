#include <systemc>

class Proc : public sc_core::sc_module
{
public:
    explicit Proc(const sc_core::sc_module_name& name)
        : sc_module{name}
    {
        SC_THREAD(thread);
        SC_METHOD(method);
    }

    void thread()
    {
        int idx{0};
        while (true)
        {
            std::cout << "thread" << idx++ << " @ " << sc_core::sc_time_stamp() << std::endl;
            wait(1.0, sc_core::SC_SEC);
        }
    }

    void method()
    {
        int idx{0};
        std::cout << "method" << idx++ << " @ " << sc_core::sc_time_stamp() << std::endl;
        next_trigger(1.0, sc_core::SC_SEC);
    }
};

int sc_main(int, char**)
{
    Proc p("process");
    sc_start(4, sc_core::SC_SEC);
    return 0;
}
