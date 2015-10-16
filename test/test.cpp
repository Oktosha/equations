#include "Variable.h"
#include <iostream>
#include "gtest/gtest.h"


TEST(VariableTest, Sample) {
    Variable x(3);
    EXPECT_EQ(2, x.get_x());
}