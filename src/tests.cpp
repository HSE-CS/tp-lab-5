// Copyright 2021 Tatsenko Alexey
#include <gtest/gtest.h>
#include <string>
#include "Group.h"
#include "Student.h"
#include "Deanary.h"

TEST(StudentGroup, test1) {
  Student student(3333, "Alex");
  EXPECT_EQ("Alex", student.GetFi);
}

TEST(StudentGroup, test2) {
  Student student(3333, "Alex");
  EXPECT_EQ(3333, student.GetId());
}

TEST(StudentGroup, test3) {
  Student student(333, "Alex");
  Group grup("Hse", "Se");
  student.AddToGroup(&grup);
  EXPECT_EQ("Se", student.GetGroup());
}

TEST(StudentGroup, test4) {
  Student student(3333, "Alex");
  student.AddEval(10);
  student.AddEval(9);
  student.AddEval(2);
  EXPECT_EQ(7, student.GetAvarageEval());
}

TEST(StudentGroup, test5) {
  Student student1("1", "Alex");
  Student student2("3", "Ilya");

  Group group("HSE", "SE");
  group.AddStudent(&student1);
  group.AddStudent(&student2);
  EXPECT_EQ("Ilya", group.GetLastStudents());
}

TEST(StudentGroup, test6) {
  Student student1("1", "Alex");
  Student student2("3", "Ilya");
  Group group("HSE", "SE");
  group.ChooseHeader(&student2);
  EXPECT_EQ("Ilya", group.GetHeader());
}

TEST(StudentGroup, test7) {
  Student student1("1", "Alex");
  Student student2("3", "Ilya");
  Group group("HSE", "SE");
  group.AddStudent(&student1);
  group.AddStudent(&student2);
  group.RemoveStudent(&student2);
  EXPECT_EQ("Alex", group.GetLastStudents());
}

TEST(StudentGroup, test8) {
  Student student1("1", "Alex");
  Student student2("3", "Ilya");
  Group HSE("Sarov", "School");
  HSE.AddStudent(&student1);
  HSE.AddStudent(&student2);
  student1.AddEval(10);
  student1.AddEval(10);
  student1.AddEval(10);
  student2.AddEval(9);
  student2.AddEval(9);
  student2.AddEval(9);

  EXPECT_EQ(9.5, HSE.GetAvarageEval());
}

TEST(StudentGroup, test9) {
  Student student1("1", "Alex");
  Student student2("3", "Ilya");

  EXPECT_EQ("3", student2.GetId());
}

TEST(StudentGroup, test10) {
  Student student1("1", "Alex");
  Student student2("3", "Ilya");
  EXPECT_EQ(nullptr, student2.GetGroup());
}
