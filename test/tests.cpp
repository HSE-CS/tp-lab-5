// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Deanary.h"
#include "Student.h"
#include "Group.h"

TEST(TestingDeanary, test1) {
  Deanary deanary;
  int a = 0;
  int b = deanary.getAmountGroup();
  EXPECT_EQ(a, b);
}
TEST(TestingDeanary, test2) {
  deanary.createGroups();
  int a = 3;
  int b = deanary.getAmountGroup();
  EXPECT_EQ(a, b);
}
TEST(TestingDeanary, test3) {
  std::string a = "15PMI-2";
  int p = 1;
  std::string b = deanary.getTitleGroup(p);
  EXPECT_EQ(a, b);
}
TEST(TastingDeanary, test4) {
  int a = 0;
  int b = deanary.getAmountStudents(0);
  EXPECT_EQ(a, b);
}
TEST(TestingDeanary, test5) {
  deanary.hireStudent();
  int a = deanary.getAmountStudents(0);
  EXPECT_EQ(a, deanary.getAmountStudents(0));
}
TEST(TestingDeanary, test6) {
  bool a = false;
  bool b = deanary.getGroup(1);
  EXPECT_EQ(a, b);
}
TEST(TestingDeanary, test7) {
  Group* a = deanary.getGroup(0);
  Student* b = a->getStudent(3);
  bool c = false;
  EXPECT_EQ(c, b->isHeadOfGroup());
}
TEST(TestingDeanary, test8) {
  Group* a = deanary.getGroup(0);
  deanary.initHeaders();
  Student* b = a->getHeader();
  bool c = true;
  EXPECT_EQ(c, b->isHeadOfGroup());
}
TEST(TestingDeanary, test9) {
  Group* a = deanary.getGroup(0);
  Student* b = a->getStudent(4);
  EXPECT_EQ(b->getGroup(), a);
}
TEST(TestingDeanary, test10) {
  Group* a = deanary.getGroup(0);
  Student* b = a->getStudent(4);
  int c = 0;
  EXPECT_EQ(c, b->getAverageMark());
}
TEST(TestingDeanary, test11) {
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  Group* a = deanary.getGroup(0);
  Student* b = a->getStudent(4);
  double c = b->getAverageMark();
  EXPECT_EQ(c, b->getAverageMark());
}
TEST(TestingDeanary, test12) {
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  Group* a = deanary.getGroup(0);
  Student* b = a->getStudent(4);
  int c = 3;
  EXPECT_EQ(c, b->getAmountMarks());
}
TEST(TestingDeanary, test13) {
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  int size1 = deanary.getAmountStudents(0);
  deanary.fireStudent(0);
  int size2 = deanary.getAmountStudents(0);
  EXPECT_EQ(size1 - 1, size2);
}
TEST(TestingDeanary, test14) {
  int size1 = deanary.getAmountStudents(1);
  deanary.moveStudent(0, 1);
  int size2 = deanary.getAmountStudents(1);
  EXPECT_EQ(size2 - 1, size1);
}
