// Copyright 2021 Schenikova

#include <gtest/gtest.h>
#include <string>
#include "Group.h"
#include "Student.h"
#include "Deanary.h"

TEST(StudentTest, test1) {
  unsigned int id = 12345678;
  std::string fio = "Veselov Ignatiy Lvovich";
  Student student(id, fio);
  EXPECT_EQ(12345678, student.getId());
}

TEST(StudentTest, test2) {
  unsigned int id = 98765432;
  std::string fio = "Naumov Velor Iosifovich";
  Student student(id, fio);
  student.addMark(10);
  EXPECT_EQ(10.0, student.getAveragemark());
}

TEST(GroupTest, test3) {
  unsigned int id = 98765432;
  std::string fio = "Naumov Velor Iosifovich";
  Student student(id, fio);
  std::string spec = "PI";
  std::string title = "19PI-1";
  Group group(title, spec);
  student.addMark(10);
  group.addStudent(&student);
  student.addToGroup(&group);
  EXPECT_EQ(&student, group.getStudentById(98765432);
}

TEST(GroupTest, test4) {
  unsigned int id = 98765432;
  std::string fio = "Naumov Velor Iosifovich";
  Student student(id, fio);
  std::string spec = "PI";
  std::string title = "19PI-1";
  Group group(title, spec);
  student.addMark(10);
  group.addStudent(&student);
  student.addToGroup(&group);
  EXPECT_EQ(&group, student.getGroup());
}

TEST(GroupTest, test5) {
  unsigned int id = 98765432;
  std::string fio = "Naumov Velor Iosifovich";
  Student student(id, fio);
  std::string spec = "PI";
  std::string title = "19PI-1";
  Group group(title, spec);
  student.addMark(10);
  student.addMark(10);
  student.addMark(10);
  student.addMark(10);
  group.addStudent(&student);
  student.addToGroup(&group);
  student.getAveragemark();
  EXPECT_EQ(10.0, group.getAveragemark());
}

