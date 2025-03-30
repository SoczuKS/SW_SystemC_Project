#include <systemc>
#include "App.hpp"

int sc_main(int argc, char** argv)
{
    sw_project::App app{};
    return app.start(argc, argv);
}
