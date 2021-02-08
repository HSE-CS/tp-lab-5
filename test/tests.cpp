// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>

#include "Student.h"
#include "Deanary.h"
#include "Group.h"

TEST(Test, test1) {
  Student student(1, "Lukicheva Polina Aleksandrovna");
  EXPECT_EQ(student.getFio(), "Lukicheva Polina Aleksandrovna");
}

TEST(Test, test2) {
  Student* st1 = new Student(1, "Lukicheva Polina Aleksandrovna");
  Group* gr = new Group("SoftwareEngineering", "19SE1");
  gr->addStudent(st1);
  EXPECT_EQ(gr->containsStudent(st1), true);
}

TEST(Test, test3) {
  Student* student = new Student(1, "Lukicheva Polina Aleksandrovna");
  Group* gr = new Group("SoftwareEngineering", "19SE1");
  gr->addStudent(&student);
  EXPECT_EQ(gr->getStudent(1), "Lukicheva Polina Aleksandrovna");
}

TEST(Test, test4) {
  Student* student = new Student(1, "Lukicheva Polina Aleksandrovna");
  student->addmark(7);
  EXPECT_EQ(student->averageMark(), 7);
}

TEST(Test, test5) {
  Student* student = new Student(1, "Lukicheva Polina Aleksandrovna");
  student->addmark(7);
  Student* student2 = new Sudent(2, "Katanova Evgeniya Ilinichna");
  student->addmark(7);
  Group* gr = new Group("SoftwareEngineering", "19SE1");
  gr->addStudent(student1);
  gr->addStudent(student2);
  EXPECT_EQ(gr->getAverageMark(), 7);
}

TEST(Test, test6) {
  Group* gr = new Group("SoftwareEngineering", "19SE1");
  EXPECT_EQ(gr->isEmpty(), true);
}

TEST(Test, test7) {
  Student* student = new Student(1, "Lukicheva Polina Aleksandrovna");
  Group* gr = new Group("SoftwareEngineering", "19SE1");
  gr->addStudent(student);
  EXPECT_EQ(gr->isEmpty, false);
}

TEST(Test, test8) {
  Deanary deanary;
  Student* student = new Student(1, "Lukicheva Polina Aleksandrovna");
  Group* gr = new Group("SoftwareEngineering", "19SE1");
  gr.addStudent(student);
  deanary.addGroup(gr);
  EXPECT_EQ(deanary.getGroup("19SE1")->isEmpty(), false);
}

TEST(Test, test9) {
  Deanary deanary;
  Group* gr = new Group("SoftwareEngineering", "19SE1");
  deanary.addGroup(&gr);
  EXPECT_EQ(deanary.getGroup("19SE1")->isEmpty(), true);
}

TEST(Test, test10) {
  Student* student = new Student(1, "Lukicheva Polina Aleksandrovna");
  student->addmark(7);
  student->addmark(8);
  EXPECT_EQ(student->averageMark(), 7.5);
}
