// Copyright 2021 ArinaMonicheva
#include "Deanary.h"
#include <gtest/gtest.h>

TEST(quickTests, test1) {
  Student* newStudent = new Student(123456, "Monicheva Arina Aleksandrovna");

  newStudent->addMark(7);
  newStudent->addMark(8);
  newStudent->addMark(9);

  double averageMark = newStudent->getAverageMark();

  EXPECT_DOUBLE_EQ(8.0, averageMark);
}

TEST(quickTests, test2) {
  Student* newStudent = new Student(123456, "Monicheva Arina Aleksandrovna");
  Group* newGroup = new Group("19PI-2");

  newGroup->addStudent(newStudent);
  newGroup->chooseHead(newStudent);

  bool isHead = newStudent->isHeadOfGroup();

  EXPECT_EQ(true, isHead);
}

TEST(quickTests, test3) {
  Student* newStudent = new Student(123456, "Monicheva Arina Aleksandrovna");
  Group* newGroup = new Group("19PI-2");

  newGroup->addStudent(newStudent);

  int itMust = newGroup->containsStudent("Monicheva Arina Aleksandrovna");

  EXPECT_EQ(0, itMust);
}

TEST(quickTests, test4) {
  Student* newStudent = new Student(123456, "Monicheva Arina Aleksandrovna");
  Student* newStudent2 = new Student(123457, "Monichev Alex Borisovich");
  Group* newGroup = new Group("19PI-2");

  newGroup->addStudent(newStudent);

  int itMustnt = newGroup->containsStudent(123457);

  EXPECT_EQ(-1, itMustnt);
}

TEST(quickTests, test5) {
  Student* newStudent = new Student(123456, "Monicheva Arina Aleksandrovna");
  Group* newGroup = new Group("19PI-2");

  newGroup->addStudent(newStudent);
  newGroup->removeStudent(newStudent);

  int itMustnt = newGroup->containsStudent(123456);

  EXPECT_EQ(-1, itMustnt);
}

TEST(quickTests, test6) {
  Student* newStudent = new Student(123456, "Monicheva Arina Aleksandrovna");
  Group* newGroup = new Group("19PI-2");

  newGroup->addStudent(newStudent);
  newGroup->chooseHead(newStudent);

  newGroup->removeStudent(newStudent);

  bool isHead = newStudent->isHeadOfGroup();

  EXPECT_EQ(false, isHead);
}

TEST(quickTests, test7) {
  Student* newStudent = new Student(123456, "Monicheva Arina Aleksandrovna");
  Group* newGroup = new Group("19PI-2");
  Group* newGroup2 = new Group("19PI-1");
  Deanery newDeanary;

  newDeanary.addNewGroup(newGroup);
  newDeanary.addNewGroup(newGroup2);

  newGroup->addStudent(newStudent);

  newDeanary.moveStudents(newStudent, newGroup2);

  int itMustnt = newGroup->containsStudent("Monicheva Arina Aleksandrovna");

  EXPECT_EQ(-1, itMustnt);
}

TEST(quickTests, test8) {
  Student* newStudent = new Student(123456, "Monicheva Arina Aleksandrovna");
  Group* newGroup = new Group("19PI-2");
  Group* newGroup2 = new Group("19PI-1");
  Deanery newDeanary;

  newDeanary.addNewGroup(newGroup);
  newDeanary.addNewGroup(newGroup2);

  newGroup->addStudent(newStudent);

  newDeanary.moveStudents(newStudent, newGroup2);

  int itMust = newGroup2->containsStudent(123456);

  EXPECT_EQ(0, itMust);
}

TEST(quickTests, test9) {
  Student* newStudent = new Student(123456, "Monicheva Arina Aleksandrovna");
  Group* newGroup = new Group("19PI-2");
  Deanery newDeanary;

  newStudent->addMark(2);
  newStudent->addMark(3);
  newStudent->addMark(4);

  newDeanary.addNewGroup(newGroup);

  newGroup->addStudent(newStudent);

  newDeanary.fireStudents();

  int itMustnt = newGroup->containsStudent(123456);
  EXPECT_EQ(-1, itMustnt);
}

TEST(quickTests, test10) {
  Student* newStudent = new Student(123456, "Monicheva Arina Aleksandrovna");
  Student* newStudent1 = new Student(123457, "Monichev Alex Borisovich");
  Group* newGroup = new Group("19PI-2");
  Deanery newDeanary;

  newStudent->addMark(8);
  newStudent->addMark(7);
  newStudent->addMark(8);

  newStudent1->addMark(6);
  newStudent1->addMark(7);
  newStudent1->addMark(6);

  newDeanary.addNewGroup(newGroup);

  newGroup->addStudent(newStudent);
  newGroup->addStudent(newStudent1);

  newDeanary.initHeads(newGroup);

  bool isHead = newStudent->isHeadOfGroup();

  EXPECT_EQ(true, isHead);
}
