#include <systemc>
#include "App.hpp"

int sc_main(const int argc, char** argv)
{
    sw_project::App app{};
    return app.start(argc, argv);
}
