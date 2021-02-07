// Copyright 2021 Kasyanov

#include <gtest/gtest.h>
#include <string>
#include "Deanary.h"
#include "Group.h"
#include "ReadGroup.h"
#include "Student.h"

TEST(DeanaryTest, test1) {
  Group group("Group", "IT");
  Student st(101, "Test_name Test_surname", &group);
  std::string expected = "Test_name Test_surname";
  EXPECT_EQ(expected, st.GetName());
}

TEST(DeanaryTest, test2) {
  Group group("Group", "IT");
  Student st(101, "Test_name Test_surname", &group);
  bool expected = false;
  EXPECT_EQ(expected, st.IsHeadOfGroup());
}

TEST(DeanaryTest, test3) {
  Group group("Group", "IT");
  Student st(101, "Test_name Test_surname", &group);
  bool expected = false;
  EXPECT_EQ(expected, group.isEmpty());
}

TEST(DeanaryTest, test4) {
  Group group("Group", "IT");
  Student st(101, "Test_name Test_surname", &group);
  bool expected = false;
  EXPECT_EQ(expected, group.ContainsStudent(101));
}

TEST(DeanaryTest, test5) {
  Group group("Group", "IT");
  Student st(101, "Test_name Test_surname", &group);
  bool expected = true;
  EXPECT_EQ(expected, group.ContainsStudent("Test_name Test_surname"));
}

TEST(DeanaryTest, test6) {
  Group group("Group", "IT");
  Student st(101, "Test_name Test_surname", &group);
  std::string expected = "Test_name Test_surname";
  EXPECT_EQ(expected, group.GetStudent("Test_name Test_surname").GetName());
}

TEST(DeanaryTest, test7) {
  Group group("Group", "IT");
  Student st(101, "Test_name Test_surname", &group);
  std::string expected = "Test_name Test_surname";
  EXPECT_EQ(expected, group.GetStudent(101).GetName());
}

TEST(DeanaryTest, test8) {
  Group group("Group", "IT");
  Student st(101, "Test_name Test_surname", &group);
  std::vector<Student*> expected = {&st};
  EXPECT_EQ(expected, group.GetAllStudents());
}

TEST(DeanaryTest, test9) {
  Group group("Group", "IT");
  bool expected = true;
  EXPECT_EQ(expected, group.isEmpty());
}

TEST(DeanaryTest, test10) {
  ReadGroup reader({"Test1.txt", "Test2.txt"});
  std::vector<std::string> expected = {"Test1.txt", "Test2.txt"};
  EXPECT_EQ(expected, reader.GetFileNames());
}
