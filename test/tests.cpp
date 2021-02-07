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

TEST(DeanaryTest, test7) {
  Deanary dean;
  dean.createGroups("GroupsForTest.txt");
  dean.fireStudents("NamesForTest.txt");
  dean.initHeads();
  EXPECT_EQ("TomKing",
            dean.getGroup("FundamentalMathematics")->getHead()->getFio());
}

TEST(DeanaryTest, test8) {
  Deanary dean;
  dean.createGroups("GroupsForTest.txt");
  dean.fireStudents("NamesForTest.txt");
  dean.initHeads();
  EXPECT_EQ(
      "DonBarrett",
      dean.getGroup("AppliedMathematicsAndInformatics")->getHead()->getFio());
}

TEST(DeanaryTest, test9) {
  Deanary dean;
  dean.createGroups("GroupsForTest.txt");
  dean.fireStudents("NamesForTest.txt");
  dean.initHeads();
  dean.MoveStudents(1, "AppliedMathematicsAndInformatics");
  EXPECT_EQ(true, dean.getGroup("FundamentalMathematics")->isEmpty());
}

TEST(DeanaryTest, test10) {
  Deanary dean;
  dean.createGroups("GroupsForTest.txt");
  dean.fireStudents("NamesForTest.txt");
  EXPECT_EQ("TomKing",
            dean.getGroup("FundamentalMathematics")->getStudent(1)->getFio());
}

TEST(DeanaryTest, test11) {
  Deanary dean;
  dean.createGroups("GroupsForTest.txt");
  dean.fireStudents("NamesForTest.txt");
  EXPECT_EQ("DonBarrett", dean.getGroup("AppliedMathematicsAndInformatics")
                              ->getStudent(1)
                              ->getFio());
}
