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
  EXPECT_EQ(false, group.containsStudent(2));
}

TEST(DeanaryTest, test7) {
  Group *group = new Group("FundamentalMathematics", "FM");
  group->AddStudent(new Student(1, "TestName"));
  Deanary dean;
  dean.AddGroup(group);
  EXPECT_EQ(true, dean.getGroup("FundamentalMathematics")->containsStudent(1));
}

TEST(DeanaryTest, test8) {
  Group *group = new Group("FundamentalMathematics", "FM");
  group->AddStudent(new Student(1, "TestName"));
  Deanary dean;
  dean.AddGroup(group);
  dean.initHeads();
  EXPECT_EQ(
      true,
      dean.getGroup("FundamentalMathematics")->getHead()->isHeadOfGroup());
}

TEST(DeanaryTest, test9) {
  Group *group = new Group("FundamentalMathematics", "FM");
  Deanary dean;
  dean.AddGroup(group);
  EXPECT_EQ(true, dean.getGroup("FundamentalMathematics")->isEmpty());
}

TEST(DeanaryTest, test10) {
  Group *group = new Group("FundamentalMathematics", "FM");
  Deanary dean;
  dean.AddGroup(group);
  EXPECT_EQ(nullptr, dean.getGroup("FundamentalMathematics")->getHead());
}
