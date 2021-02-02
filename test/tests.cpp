// Copyright 2021 Kuznetsov Mikhail
#include <string>
#include "gtest/gtest.h"
#include "Group.h"
#include "Student.h"
#include "Deanary.h"

TEST(DeaneryDemoTest, test1) {
  unsigned int id = 2021;
  std::string fio = "Messi Lionel";
  Student student(id, fio);
  EXPECT_EQ("Messi Lionel", student.getFio());
}

TEST(DeaneryDemoTest, test2) {
  unsigned int id = 2020;
  std::string fio = "Lewandowski Robert";
  Student student(id, fio);
  EXPECT_EQ(2020, student.getId());
}

TEST(DeaneryDemoTest, test3) {
  unsigned int id = 2019;
  std::string fio = "Modric Luka";
  Student student(id, fio);
  student.addMark(3);
  ASSERT_NEAR(3.0, student.getAveragemark());
}

TEST(DeaneryDemoTest, test4) {
  unsigned int id = 2018;
  std::string fio = "Ronaldo Cristiano";
  Student student(id, fio);
  std::string spec = "Football";
  std::string title = "Juventus";
  Group group(title, spec);
  group.addStudent(&student);
  student.addToGroup(&group);
  EXPECT_EQ(&group, student.getGroup());
}

TEST(DeaneryDemoTest, test5) {
  unsigned int id = 2017;
  std::string fio = "Matic Nemanja";
  Student student1(id, fio);
  id = 2016;
  fio = "Mata Juan";
  Student student2(id, fio);
  std::string spec = "Football";
  std::string title = "Manchester Unaited";
  Group group(title, spec);
  group.addStudent(&student1);
  student1.addToGroup(&group);
  group.addStudent(&student2);
  student2.addToGroup(&group);
  student1.addMark(94);
  student2.addMark(96);
  ASSERT_NEAR(95.0, group.getAveragemark());
}

TEST(DeaneryDemoTest, test6) {
  unsigned int id = 2016;
  std::string fio = "Noier Manuel";
  Student student1(id, fio);
  id = 2015;
  fio = "Buffon Jiji";
  Student student2(id, fio);
  std::string spec = "Football";
  std::string title = "PSG";
  Group group(title, spec);
  group.addStudent(&student1);
  student1.addToGroup(&group);
  group.addStudent(&student2);
  student2.addToGroup(&group);
  EXPECT_EQ(&student1, group.getStudent(2016));
}

TEST(DeaneryDemoTest, test7) {
  unsigned int id = 2014;
  std::string fio = "Veratti Marko";
  Student student1(id, fio);
  std::string spec = "Football";
  std::string title = "PSG";
  Group group(title, spec);
  group.addStudent(&student1);
  student1.addToGroup(&group);
  EXPECT_EQ(&student1, group.getStudent(fio));
}

TEST(DeaneryDemoTest, test8) {
  unsigned int id = 2013;
  std::string fio = "Bale Gareth";
  Student student1(id, fio);
  std::string spec = "Football";
  std::string title = "Real Madrid";
  Group group(title, spec);
  group.addStudent(&student1);
  student1.addToGroup(&group);
  group.removeStudent(&student1);
  EXPECT_EQ(nullptr, group.getStudent(fio));
}

TEST(DeaneryDemoTest, test9) {
  std::string spec = "Football";
  std::string title = "Liverpool";
  Group group(title, spec);
  EXPECT_EQ("Football", group.getSpec());
}

TEST(DeaneryDemoTest, test10) {
  std::string spec = "Football";
  std::string title = "Chelsea";
  Group group(title, spec);
  EXPECT_EQ("Chelsea", group.getTitle());
}

TEST(DeaneryDemoTest, test11) {
  std::string spec = "Football";
  std::string title = "Arsenal";
  Group group(title, spec);
  EXPECT_EQ(true, group.isEmpty());
}

TEST(DeaneryDemoTest, test12) {
  unsigned int id = 2012;
  std::string fio = "Suarez Luiz";
  Student student1(id, fio);
  std::string spec = "Football";
  std::string title = "Atletico Madrid";
  Group group(title, spec);
  group.addStudent(&student1);
  EXPECT_EQ(false, group.isEmpty());
}
