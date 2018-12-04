cmake_minimum_required(VERSION 3.12)
project(HierarchicalScheduling)

set(CMAKE_CXX_STANDARD 14)

add_executable(HierarchicalScheduling main.cpp Flow.cpp Flow.h Fifo.cpp Fifo.h Level.cpp Level.h Package.cpp Package.h Scheduler.cpp Scheduler.h Simulator.cpp Simulator.h)