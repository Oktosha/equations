add_library (EquationsLibrary
        Variable.cpp Variable.h
        Monomial.cpp Monomial.h
        Polynomial.h)
add_executable (demo main.cpp)
target_link_libraries (demo EquationsLibrary)