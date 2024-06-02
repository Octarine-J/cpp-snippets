cmake_minimum_required(VERSION 3.20)
project(snippets-2x)

set(CMAKE_CXX_STANDARD 23)
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

set(SOURCES
        src/arithmetic.cpp
        src/cast.cpp
        src/concepts.cpp
        src/concepts_custom.cpp
        src/control_statements.cpp
        src/functions.cpp
        src/structs.cpp
        src/strings.cpp
)

# -lstdc++exp is required for MinGW to enable some C++23 features
add_executable(all-tests ${SOURCES})
target_link_libraries(all-tests PRIVATE Catch2::Catch2WithMain -lstdc++exp)
