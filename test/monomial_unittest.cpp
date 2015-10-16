//
// Created by Дарья Колодзей on 16.10.15.
//
#include "gtest/gtest.h"
#include "Monomial.h"
#include <vector>

TEST(MonomialTest, Equality) {
    Variable x("x"), x1("x");
    Variable y("y");

    Monomial p(x), p1(x1), q(y);

    EXPECT_EQ(p, p1);
    EXPECT_FALSE(q == p);
    EXPECT_EQ(x * y, y * x);
}

TEST(MonomialTest, Print1) {
    std::stringstream ss;
    Monomial p = Monomial(Variable("x"));
    ss << p;
    EXPECT_EQ("x", ss.str());
}

TEST(MonomialTest, Print2) {
    std::stringstream ss;
    Variable x("x");
    Monomial p = x * x;
    ss << p;
    EXPECT_EQ("(x^2)", ss.str());
}

TEST(MonomialTest, Print21) {
    std::stringstream ss;
    Variable x("x");
    Variable y("y");
    Monomial p = x * x * y;
    ss << p;
    EXPECT_EQ("(x^2)y", ss.str());
}

TEST(MonomialTest, Multiplication) {
    Variable x("x");
    Variable y("y");
    Monomial p = pow(x, 3) * pow(y, 5);
    Monomial q = pow(x, 2) * pow(y, 9);
    EXPECT_EQ(pow(x, 5) * pow(y, 14), p * q);
    EXPECT_EQ(pow(x, 4) * pow(y, 5), p * x);
    EXPECT_EQ(pow(x, 4) * pow(y, 5), x * p);
}

TEST(MonomialTest, Сomparison) {
    Variable x("x"), y("y"), z("z");
    std::vector<Monomial> a;
    for (int i = 0; i <= 2; ++i)
        for (int j = 0; j <= 2; ++j)
            for (int k = 0; k <= 2; ++k)
                a.push_back(pow(x, i) * pow(y, j) * pow(z, k));
    std::sort(a.begin(), a.end());
    std::stringstream ss;
    for (auto it = a.begin(); it != a.end(); ++it)
        ss << *it << " ";
    std::stringstream as;
    for (int i = 2; i >= 0; --i)
        for (int j = 2; j >= 0; --j)
            for (int k = 2; k >= 0; --k) {
                as << pow(x, i) * pow(y, j) * pow(z, k) << " ";
            }
    EXPECT_EQ(as.str(), ss.str());
}
