cmake_minimum_required(VERSION 3.20)
project(tidsmatare)

set(CMAKE_CXX_STANDARD 14)

add_executable(tidsmatare main-entry-point.cpp)


add_subdirectory(stopper)
add_subdirectory(function_analyzer)

target_include_directories(tidsmatare
        PUBLIC ${PROJECT_SOURCE_DIR}/stopper
        PUBLIC ${PROJECT_SOURCE_DIR}/function_analyzer
        )

target_link_directories(tidsmatare
        PUBLIC stopper
        PUBLIC function_analyzer)

target_link_libraries(tidsmatare
        stopper
        fn_analyzer
        )