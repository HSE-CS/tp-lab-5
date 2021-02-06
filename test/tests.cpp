// Copyright 2021 Dev-will-work

#include <gtest/gtest.h>
#include <string>
#include <cstdlib>
#include "Deanary.h"
#include "Group.h"
#include "Student.h"

TEST(DeanaryTest, CreateGroupsTest) {
  Deanary d;
  d.createGroups(3);
  EXPECT_EQ(3, d.size());
}

TEST(DeanaryTest, HireStudentsTest) {
  Deanary d;
  size_t size = 0;
  d.createGroups(3);
  d.hireStudents(10);
  for (size_t i = 0; i < d.size(); i++) {
    size += d[i]->size();
  }
  EXPECT_EQ(30, size);
}

TEST(DeanaryTest, BadCreateGroups) {
  Deanary d;
  d.createGroups(-5);
  EXPECT_EQ(0, d.size());
}

TEST(DeanaryTest, BadHireStudents) {
  Deanary d;
  size_t size = 0;
  d.createGroups(3);
  d.hireStudents(-10);
  for (size_t i = 0; i < d.size(); i++) {
    size += d[i]->size();
  }
  EXPECT_EQ(0, size);
}

TEST(DeanaryTest, AddMarksTest) {
  Deanary d;
  d.createGroups(3);
  d.hireStudents(10);
  d.addMarksToAll(5);
  for (size_t i = 0; i < d.size(); i++) {
    for (size_t j = 0; j < d[i]->size(); j++) {
      EXPECT_EQ(5, (*d[i])[j]->size());
    }
  }
}

TEST(DeanaryTest, BadAddMarks) {
  Deanary d;
  d.createGroups(3);
  d.hireStudents(10);
  d.addMarksToAll(-1);
  for (size_t i = 0; i < d.size(); i++) {
    for (size_t j = 0; j < d[i]->size(); j++) {
      EXPECT_EQ(0, (*d[i])[j]->size());
    }
  }
}

TEST(DeanaryTest, InitHeadsTest) {
  Deanary d;
  d.createGroups(3);
  d.hireStudents(10);
  d.initHeads();
  EXPECT_TRUE(d[1]->getHead());
}

TEST(DeanaryTest, MoveStudentsTest) {
  Deanary d;
  d.createGroups(3);
  d.hireStudents(10);
  d.moveStudents(0, 1);
  EXPECT_EQ(20, d[1]->size());
  EXPECT_EQ(0, d[0]->size());
}

TEST(DeanaryTest, BadMoveStudents) {
  Deanary d;
  d.createGroups(3);
  d.hireStudents(10);
  d.moveStudents(0, -5);
  EXPECT_EQ(10, d[0]->size());
}

TEST(DeanaryTest, BadFireStudents) {
  Deanary d;
  size_t students_count = 0;
  d.createGroups(3);
  d.hireStudents(10);
  d.fireStudents(-7);
  for (size_t i = 0; i < d.size(); i++) {
    students_count += d[i]->size();
  }
  EXPECT_EQ(30, students_count);
}

TEST(DeanaryTest, FireStudentsTest) {
  Deanary d;
  size_t students_count = 0;
  d.createGroups(3);
  d.hireStudents(10);
  d.fireStudents(2);
  for (size_t i = 0; i < d.size(); i++) {
    students_count += d[i]->size();
  }
  EXPECT_EQ(28, students_count);
}
