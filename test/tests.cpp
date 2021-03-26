// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>

// passed
TEST(MyStackTest, test1) {
MyStack<int> st(5);
EXPECT_EQ(true, st.isEmpty());
}
