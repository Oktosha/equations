add_library (EquationsLibrary Variable.cpp Variable.h Z.h Operation.h CalculateRPN.cpp CalculateRPN.h)
add_executable (demo main.cpp)
target_link_libraries (demo EquationsLibrary)