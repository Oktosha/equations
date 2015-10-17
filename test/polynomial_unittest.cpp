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

TEST(PolynomialTest, Print) {
    Polynomial<int> p(Variable("x"));
    std::stringstream ss;
    ss << p;
    EXPECT_EQ("x", ss.str());
}

TEST(PolynomialTest, Multiplication) {
    Polynomial<int> p(Variable("x"));
    p = p * 4;
    std::stringstream ss;
    ss << p;
    EXPECT_EQ("4x", ss.str());
    EXPECT_EQ(3 * p, p * 3);
}

TEST(PolynomialTest, Addition1) {
    Variable x("x"), y("y");
    Polynomial<double> p = 0.5 * Polynomial<double>(y) + 1.3 * Polynomial<double>(x);
    std::stringstream ss;
    ss << p;
    EXPECT_EQ("1.3x + 0.5y", ss.str());
}

TEST(PolynomialTest, Addition2) {
    Variable x("x");
    Polynomial<int> p = 3 * Polynomial<int>(x) + 5 * Polynomial<int>(x);
    std::stringstream ss;
    ss << p;
    EXPECT_EQ("8x", ss.str());
}

TEST(PolynomialTest, Addition3) {
    Variable x("x"), y("y");
    Polynomial<int> p = 3 * Polynomial<int>(x * y) + 5 * Polynomial<int>(x);
    Polynomial<int> q = 4 * Polynomial<int>(pow(x, 2) * y) + 7 * Polynomial<int>(x) + Polynomial<int>(y);
    std::stringstream ss;
    Polynomial<int> sum = p + q;
    ss << sum;
    EXPECT_EQ("4(x^2)y + 3xy + 12x + y", ss.str());
}