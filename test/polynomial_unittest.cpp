//
// Created by Дарья Колодзей on 17.10.15.
//
#include "gtest/gtest.h"
#include "Polynomial.h"

TEST(PolynomialTest, Equality) {
    Variable x("x"), y("y");
    Polynomial<int> p(x), q(y);
    EXPECT_EQ(p, p);
    EXPECT_FALSE(p == q);
}