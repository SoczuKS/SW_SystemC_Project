cmake_minimum_required(VERSION 3.31)
project(SW_SystemC_Project)

include(FetchContent)

FetchContent_Declare(
        SystemC
        GIT_REPOSITORY https://github.com/accellera-official/systemc
        GIT_TAG refs/tags/3.0.1)
FetchContent_MakeAvailable(SystemC)

add_subdirectory(sandbox)

add_executable(SW_SystemC_Project main.cpp)
target_link_libraries(SW_SystemC_Project SystemC::systemc)
