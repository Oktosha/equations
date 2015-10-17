//
// Created by Дарья Колодзей on 17.10.15.
//
#include "gtest/gtest.h"
#include "Z.h"

TEST(ZpTest, Equality) {
    Z<7> x(3 + 6), y(-5), z(2);
    Z<7> t(5);
    EXPECT_EQ(x, y);
    EXPECT_EQ(x, z);
    EXPECT_EQ(y, z);
    EXPECT_FALSE(t == y);
}

TEST(Zp, Operations) {
    Z<7> x(4), y(5);
    EXPECT_EQ(Z<7>(2), x + y);
    EXPECT_EQ(Z<7>(6), x * y);
    EXPECT_EQ(Z<7>(1), y - x);
}

TEST(Zp, Print) {
    std::stringstream ss;
    ss << Z<11>(4) << " " << Z<11>(-3) << " " << Z<11>(13);
    EXPECT_EQ("4 8 2", ss.str());
}