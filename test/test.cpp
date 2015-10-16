#include "Variable.h"
#include <iostream>
#include "gtest/gtest.h"


TEST(VariableTest, Equality) {
    Variable x1("x");
    Variable x2("x");
    Variable x3 = x1;
    Variable z("z");
    EXPECT_EQ(x1, x2);
    EXPECT_EQ(x1, x3);
    EXPECT_FALSE(z == x1);
}