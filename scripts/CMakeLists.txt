cmake_minimum_required(VERSION 3.10)
project(Calco)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(calco calco.cpp)

# Set compiler warnings
if(MSVC)
    target_compile_options(calculator PRIVATE /W4 /WX)
else()
    target_compile_options(calculator PRIVATE -Wall -Wextra -Werror)
endif()

# Installation (optional)
install(TARGETS calco DESTINATION bin)
