set(EQUATIONS_LIB_INCLUDE_DIR ../src)
set(gtest_SOURCE_DIR ../googletest/googletest/)
set(gtest_BINARY_DIR ../target/googletest/googletest/)

include_directories(${EQUATIONS_LIB_INCLUDE_DIR} ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
link_directories(${gtest_BINARY_DIR})

add_executable(variable_unittest variable_unittest.cpp)

target_link_libraries(variable_unittest gtest gtest_main)
target_link_libraries(variable_unittest EquationsLibrary)

add_executable(zp_unittest zp_unittest.cpp)

target_link_libraries(zp_unittest gtest gtest_main)
target_link_libraries(zp_unittest EquationsLibrary)