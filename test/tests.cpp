// Copyright 2020 GHA Test Team

#include "Deanary.h"
#include "Group.h"
#include "Student.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(Test, test1) {
Student s1(1, "10 0");
s1.AddMark(0);
s1.AddMark(10);
EXPECT_FLOAT_EQ(5, s1.getAverageMark());
}