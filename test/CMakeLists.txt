set(EQUATIONS_LIB_INCLUDE_DIR ../src)
include_directories(${EQUATIONS_LIB_INCLUDE_DIR})

add_executable (dummy test.cpp)
target_link_libraries (dummy EquationsLibrary)