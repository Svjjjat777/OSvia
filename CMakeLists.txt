cmake_minimum_required(VERSION 3.10)
project(OSvia)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(CURL REQUIRED)
find_package(nlohmann_json REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src)

# Add source files
set(SOURCES
    src/main.cpp
    src/core/kernel.cpp
    src/core/window_manager.cpp
    src/apps/calculator.cpp
    src/apps/browser.cpp
    src/apps/weather.cpp
    src/games/flappy_bird.cpp
    src/games/snake.cpp
    src/utils/network.cpp
    src/utils/ui.cpp
)

# Create executable
add_executable(osvia ${SOURCES})

# Link libraries
target_link_libraries(osvia PRIVATE CURL::libcurl nlohmann_json::nlohmann_json)
