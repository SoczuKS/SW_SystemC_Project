cmake_minimum_required(VERSION 4.0.0)
project(SW_SystemC_Project)

include(FetchContent)

FetchContent_Declare(
        SystemC
        GIT_REPOSITORY https://github.com/accellera-official/systemc
        GIT_TAG refs/tags/3.0.1)
FetchContent_MakeAvailable(SystemC)

add_subdirectory(sandbox)

set(INCLUDES
        ${CMAKE_CURRENT_SOURCE_DIR}/include/App.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Controller.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/TimeSwitchTask.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Time.hpp
)

set(SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/App.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Controller.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/TimeSwitchTask.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

add_executable(SW_SystemC_Project ${INCLUDES} ${SOURCES})
target_include_directories(SW_SystemC_Project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(SW_SystemC_Project PRIVATE SystemC::systemc)
