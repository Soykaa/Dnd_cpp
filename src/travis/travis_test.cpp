#include "gtest/gtest.h"

#include "travis/travis.h"

TEST(Sum, AddsValues) {
    EXPECT_EQ(Sum(1, 2), 4);
}
