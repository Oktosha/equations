cmake_minimum_required(VERSION 3.3)
set(PROJECT_NAME equations)
project(${PROJECT_NAME})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(googletest/googletest)


add_custom_target(
    run
    COMMAND demo
    DEPENDS demo
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)

enable_testing ()
add_test (NAME variable_unittest COMMAND variable_unittest)
add_test (NAME monomial_unittest COMMAND monomial_unittest)
add_test (NAME polynomial_unittest COMMAND polynomial_unittest)