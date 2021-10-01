cmake_minimum_required(VERSION 3.20)
project(tidsmatare)

set(CMAKE_CXX_STANDARD 14)

add_executable(tidsmatare main-entry-point.cpp)


add_subdirectory(stopper)

target_include_directories(tidsmatare
        PUBLIC ${PROJECT_SOURCE_DIR}/stopper)

target_link_directories(tidsmatare
        PUBLIC stopper)
target_link_libraries(tidsmatare
        stopper
        )