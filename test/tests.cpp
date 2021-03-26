// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "../include/Deanary.h"

TEST(Student, test1) {
Student student(1123, "1 2 3");
EXPECT_EQ(1123, student.GetId());
}

TEST(Student, test2) {
Student student(1123, "1 2 3");
EXPECT_EQ("1 2 3", student.GetFio());
}

TEST(Student, test3) {
Student student(1123, "1 2 3");
EXPECT_EQ(0, student.CountAvgMark());
}