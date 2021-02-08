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

}

TEST(Test, test3) {
  Student* student = new Student(1, "Lukicheva Polina Aleksandrovna");
  Group* gr = new Group("SoftwareEngineering", "19SE1");
  gr->addStudent(student);
  EXPECT_EQ(gr->getStudent(1), "Lukicheva Polina Aleksandrovna");
}
