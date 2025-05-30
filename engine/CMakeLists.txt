project(engine)

add_compile_options(-Wall -Wextra -Werror -pedantic)

# sources
include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/**/*.cpp
)

add_library(
    amethyst
    ${SOURCES}
)

target_include_directories(
    amethyst
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${PROJECT_SOURCE_DIR}/vendor/glad/include
)

target_link_libraries(
    amethyst
    PRIVATE
        glad
        glm
        glfw
)

# test sources
file(GLOB_RECURSE TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/test/**/*.cpp
)
add_executable(
    amethyst_test
    ./test/Main.cpp
    ${TEST_SOURCES}
)

target_include_directories(
    amethyst_test
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(
    amethyst_test
    PRIVATE
        amethyst
        glad
        UnitTest++
)
