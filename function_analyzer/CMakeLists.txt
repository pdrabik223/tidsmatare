add_library(fn_analyzer
analyzer_base.h analyzer_base.cpp)


target_include_directories(fn_analyzer
        PUBLIC ${PROJECT_SOURCE_DIR}/function_stopper
        )

target_link_directories(fn_analyzer

        PUBLIC function_stopper)


target_link_libraries(fn_analyzer
        fn_stopper
        )