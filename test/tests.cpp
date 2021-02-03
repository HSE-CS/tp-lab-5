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

