// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Deanary.h"
#include "Student.h"
#include "Group.h"

/*TEST(TestingDeanary, test1) {
  Deanary deanary;
  int a = 0;
  int b = deanary.getAmountGroup();
  EXPECT_EQ(a, b);
}
TEST(TestingDeanary, test2) {
  Deanary deanary;
  deanary.createGroups();
  int a = 3;
  int b = deanary.getAmountGroup();
  EXPECT_EQ(a, b);
}*/
TEST(TastingDeanary, test3) {
  Deanary deanary;
  deanary.createGroups();
  std::vector<Group*> v = deanary.getGroup();
  int i = 0;
  std::vector<Student*> st = v[i]->getStudentsInGroup();
  int a = 0;
  int b = st.size();
  EXPECT_EQ(a, b);
}
TEST(TestingDeanary, test4) {
  Deanary deanary;
  deanary.createGroups();
  //deanary.hireStudent();
  std::vector<Group*> v = deanary.getGroup();
  int i = 0;
  std::vector<Student*> st = v[i]->getStudentsInGroup();
  int a = 20;
  EXPECT_EQ(a, st.size());
}
TEST(TestingDeanary, test5) {
  Deanary deanary;
  deanary.createGroups();
  deanary.hireStudent();
  std::vector<Group*> v = deanary.getGroup();
  int i = 0;
  std::vector<Student*> st = v[i]->getStudentsInGroup();
  deanary.initHeaders();
  Student* b = v[i]->getHeader();
  bool c = true;
  EXPECT_EQ(c, b->isHeadOfGroup());
}
TEST(TestingDeanary, test6) {
  Deanary deanary;
  deanary.createGroups();
  deanary.hireStudent();
  std::vector<Group*> v = deanary.getGroup();
  int i = 0;
  std::vector<Student*> st = v[i]->getStudentsInGroup();
  Student* b = st[i];
  EXPECT_EQ(b->getGroup(), v[i]);
}
TEST(TestingDeanary, test7) {
  Deanary deanary;
  deanary.createGroups();
  deanary.hireStudent();
  std::vector<Group*> v = deanary.getGroup();
  int i = 0;
  std::vector<Student*> st = v[i]->getStudentsInGroup();
  Student* b = v[i]->getStudent(i);
  double c = 0.0;
  EXPECT_EQ(c, b->getAverageMark());
}
TEST(TestingDeanary, test8) {
  Deanary deanary;
  deanary.createGroups();
  deanary.hireStudent();
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  deanary.addMarksToAll();
  std::vector<Group*> v = deanary.getGroup();
  int i = 0;
  std::vector<Student*> st = v[i]->getStudentsInGroup();
  Student *b = st[i];
  int c = 3;
  EXPECT_EQ(c, b->getAmountMarks());
}
TEST(TestingDeanary, test9) {
  Deanary deanary;
  deanary.createGroups();
  deanary.hireStudent();
  std::vector<Group*> v = deanary.getGroup();
  int i = 0;
  std::vector<Student*> st = v[i]->getStudentsInGroup();
  int size1 = st.size();
  deanary.fireStudent(0);
  int size2 = st.size();
  EXPECT_EQ(size1 - 1, size2);
}
TEST(TestingDeanary, test10) {
  Deanary deanary;
  deanary.createGroups();
  deanary.hireStudent();
  std::vector<Group*> v = deanary.getGroup();
  int i = 0;
  int p = 1;
  std::vector<Student*> st = v[p]->getStudentsInGroup();
  int size1 = st.size();
  deanary.moveStudent(i, p);
  int size2 = st.size();
  EXPECT_EQ(size2 - 1, size1);
}

