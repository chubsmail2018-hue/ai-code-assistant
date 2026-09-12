cmake_minimum_required(VERSION 3.10)
project(AICodeAssistant)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/main.cpp
    src/assistant.cpp
    src/code_generator.cpp
    src/c_analyzer.cpp
    src/cpp_analyzer.cpp
    src/language_parser.cpp
)

# Create executable
add_executable(ai_assistant ${SOURCES})

# Include directories
target_include_directories(ai_assistant PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Compiler flags
if(MSVC)
    target_compile_options(ai_assistant PRIVATE /W4)
else()
    target_compile_options(ai_assistant PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Installation
install(TARGETS ai_assistant DESTINATION bin)
