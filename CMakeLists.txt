cmake_minimum_required(VERSION 4.0)
project(karensoppgave)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

include(FetchContent)
set(THREEPP_BUILD_TESTS OFF)
set(THREEPP_BUILD_EXAMPLES OFF)
FetchContent_Declare(
        threepp
        GIT_REPOSITORY https://github.com/markaren/threepp.git
        GIT_TAG 619cdaacc2e7dc6ea709d8c7f482e2994af7349d
)
FetchContent_MakeAvailable(threepp)
#...
add_executable(karen2 main.cpp)
target_link_libraries(karen2 PUBLIC threepp::threepp)


