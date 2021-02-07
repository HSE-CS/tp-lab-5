// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>

#include <string>

#include "Deanary.h"
#include "Group.h"
#include "Student.h"

TEST(DeanaryTest, test1) {
  Student student(1, "TestName");
  EXPECT_EQ(1, student.getId());
}

TEST(DeanaryTest, test2) {
  Student student(1, "TestName");
  EXPECT_EQ("TestName", student.getFio());
}

TEST(DeanaryTest, test3) {
  Student student(1, "TestName");
  EXPECT_EQ(false, student.isHeadOfGroup());
}

TEST(DeanaryTest, test4) {
  Student student(1, "TestName");
  EXPECT_EQ(0, static_cast<int>(student.getAverageMark()));
}

TEST(DeanaryTest, test5) {
  Group group("TestTitle", "TestSpec");
  EXPECT_EQ(true, group.isEmpty());
}

TEST(DeanaryTest, test6) {
  Group group("TestTitle", "TestSpec");
  EXPECT_EQ(true, group.isEmpty());
}
