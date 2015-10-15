add_library (EquationsLibrary Variable.cpp Variable.h)
add_executable (demo main.cpp)
target_link_libraries (demo EquationsLibrary)