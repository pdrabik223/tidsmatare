cmake_minimum_required(VERSION 3.20)
project(tidsmatare)

set(CMAKE_CXX_STANDARD 14)

add_executable(tidsmatare
        main-entry-point.cpp
        function_timer_base.h   function_timer_base.cpp
        )


