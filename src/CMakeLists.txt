add_library (EquationsLibrary Variable.cpp Variable.h Z.h Operation.h CalculateRPN.h ParseRPN.h)
add_executable (demo main.cpp)
target_link_libraries (demo EquationsLibrary)