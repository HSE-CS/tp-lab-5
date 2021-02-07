// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"

TEST(Test, test1) {
  unsigned int id = 1;
  std::string fio = "Kolya Klimov";
  Student student(id, fio);
  EXPECT_EQ("Kolya Klimov", student.getFio());
}

TEST(Test, test2) {
  unsigned int id1 = 1;
  std::string fio1 = "Kolya Klimov";
  Student student1(id1, fio1);
  student1.addMark(5);
  EXPECT_EQ(5, student1.getAveragemark());
}

TEST(Test, test3) {
  unsigned int id1 = 1;
  std::string fio1 = "Kolya Klimov";
  Student student1(id1, fio1);
  student1.addMark(5);
  student1.addMark(1);
  EXPECT_EQ(3, student1.getAveragemark());
}

TEST(Test, test4) {
  unsigned int id1 = 1, id2 = 2;
  std::string fio1 = "Kolya Klimov", fio2 = "Vova Val";
  Student student1(id1, fio1), student2(id2, fio2);
  EXPECT_EQ(2, student2.getId());
}

TEST(Test, test5) {
  unsigned int id1 = 1;
  std::string fio1 = "Kolya Klimov";
  std::string title = "IMIKN", spec = "PMI";
  Student student1(id1, fio1);
  Group group(title, spec);
  group.addStudent(&student1);
  student1.addToGroup(&group);
  EXPECT_EQ(&group, student1.getGroup());
}

TEST(Test, test6) {
  unsigned int id1 = 10;
  std::string fio1 = "Kolya Klimov";
  std::string title = "IMIKN", spec1 = "PMI";
  Student student1(id1, fio1);
  Group group1(title, spec1);
  group1.addStudent(&student1);
  student1.addToGroup(&group1);
  EXPECT_EQ(&student1, group1.getStudent("Kolya Klimov"));
}

TEST(Test, test7) {
  unsigned int id1 = 1, id2 = 2;
  std::string fio1 = "Kolya Klimov", fio2 = "Vova Val";
  std::string title = "IMIKN", spec1 = "PMI", spec2 = "BI";
  Student student1(id1, fio1), student2(id2, fio2);
  Group group1(title, spec1);
  Group group2(title, spec2);
  group1.addStudent(&student1);
  student1.addToGroup(&group1);
  group2.addStudent(&student2);
  student2.addToGroup(&group2);
  EXPECT_EQ(&group2, student2.getGroup());
}

TEST(Test, test8) {
  unsigned int id1 = 1, id2 = 2;
  std::string fio1 = "Kolya Klimov", fio2 = "Vova Val";
  std::string title = "IMIKN", spec1 = "PMI";
  Student student1(id1, fio1), student2(id2, fio2);
  Group group1(title, spec1);
  group1.addStudent(&student1);
  student1.addToGroup(&group1);
  group1.addStudent(&student2);
  student2.addToGroup(&group1);
  student1.addMark(1);
  student2.addMark(3);
  EXPECT_EQ(2, group1.getAveragemark());
}

TEST(Test, test9) {
  unsigned int id1 = 1, id2 = 2;
  std::string fio1 = "Kolya Klimov", fio2 = "Vova Val";
  std::string title = "IMIKN", spec1 = "PMI";
  Student student1(id1, fio1), student2(id2, fio2);
  Group group1(title, spec1);
  group1.addStudent(&student1);
  student1.addToGroup(&group1);
  group1.addStudent(&student2);
  student2.addToGroup(&group1);
  EXPECT_EQ(false, group1.isEmpty());
}

TEST(Test, test10) {
  std::string title = "IMIKN", spec1 = "PMI";
  Group group1(title, spec1);
  EXPECT_EQ(true, group1.isEmpty());
}

TEST(Test, test11) {
  std::string title = "IMIKN", spec1 = "PMI";
  Group group1(title, spec1);
  EXPECT_EQ("IMIKN", group1.getTitle());
}
