cmake_minimum_required(VERSION 3.12)
project(HierarchicalScheduling)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")

add_executable(HierarchicalScheduling main.cpp Flow.cpp Flow.h Level.cpp Level.h Packet.cpp Packet.h Scheduler.cpp Scheduler.h Simulator.cpp Simulator.h Utility.h Utility.cpp)