// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>

#include "Student.h"
#include "Deanary.h"
#include "Group.h"

TEST(Test, test1) {
  Group group;
  EXPECT_EQ(true, group.isEmpty());
}

TEST(Test, test2) {
  Student* student = new Student(1, "Lukicheva Polina Aleksandrovna");
  Group* gr = new Group("SoftwareEngineering", "19SE1");
  gr->addStudent(student);
  EXPECT_EQ(student, gr->getStudent(1));
}

TEST(Test, test3) {
  Student* student = new Student(1, "Lukicheva Polina Aleksandrovna");
  Group* gr = new Group("SoftwareEngineering", "19SE1");
  gr->addStudent(student);
  EXPECT_EQ(gr->isEmpty(), false);
}

TEST(Test, test4) {
  Student* student = new Student(1, "Lukicheva POlina Aleksandrovna");
  Group* gr = new Group("SoftwareEngineering", "19SE1");
  gr->addStudent(student);
  EXPECT_EQ(gr->containsStudent(student), true);
}

TEST(Test, test5) {
  Group* gr = new Group("SoftwareEngineering", "19SE1");
  EXPECT_EQ(gr->getHead(), nullptr);
}

TEST(Test, test6) {
  Group* gr = new Group("SoftwareEngineering", "19SE1");
  EXPECT_EQ(gr->getHead(), nullptr);
}

TEST(Test, test7) {
  Student* student = new Student(1, "Lukicheva Polina Aleksandrovna");
  EXPECT_EQ(student->getId(), 1);
}

TEST(Test, test8) {
  Student* student1 = new Student(1, "Lukicheva Polina Aleksandrovna");
  Student* student2 = new Student(2, "Uskova Elena Maksimovna");
  EXPECT_EQ(student2->getFio(), "Uskova Elena Maksimovna");
}
