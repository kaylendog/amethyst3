cmake_minimum_required(VERSION 3.20)
project(
    Amethyst3
    VERSION 0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

# project variables
set(VENDOR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor")

# dependencies
add_subdirectory(vendor/glad)
add_subdirectory(vendor/glm)
add_subdirectory(vendor/glfw)
add_subdirectory(vendor/unittest-cpp)

add_subdirectory(engine)

# examples
add_subdirectory(examples/cube)
