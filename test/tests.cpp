// Copyright 2020 GHA Test Team
//#include "pch.h"
#include "gtest/gtest.h"
// #include "../Lab-5-source/DataReader.cpp"
// #include "../Lab-5-source/Deanary.cpp"
// #include "../Lab-5-source/Group.cpp"
// #include "../Lab-5-source/Student.cpp"
#include "DataReader.h"
#include "Student.h"
#include "Group.h"
#include "Deanary.h"


std::string dataDir = "src";
//std::string dataDir = "Lab-5-source";


TEST(StudentTest, TestInit1) {
  Student st;
  EXPECT_EQ(0, st.getId());
}

TEST(StudentTest, TestInit2) {
  Student st(5, "Ivanov Ivan Ivanych");
  EXPECT_EQ("Ivanov Ivan Ivanych", st.getFio());
  EXPECT_EQ(5, st.getId());
}

TEST(GroupTest, TestInit1) {
  Group group;
  EXPECT_EQ("", group.getTitle());
}

TEST(GroupTest, TestInit2) {
  Group group("Group1", "PI");
  EXPECT_EQ("Group1", group.getTitle());
}

TEST(DeanaryTest, TestInit1) {
  Deanary deanary;
  EXPECT_EQ(0, deanary.getNumberOfGroups());
}

TEST(DeanaryTest, TestInit2) {
  Deanary deanary(3, "../" + dataDir + "/students.txt", "../" + dataDir + "/groups.txt", false);
  EXPECT_EQ(3, deanary.getNumberOfGroups());
}

TEST(DeanaryTest, TestFunc1) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "../" + dataDir + "/students.txt", "../" + dataDir + "/groups.txt", false);
  std::string str1 = "Лисов Савелий Кириллович";
  EXPECT_EQ(str1, deanary->findStudentByFio(str1)->getFio());
}

TEST(DeanaryTest, TestFunc2) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "../" + dataDir + "/students.txt", "../" + dataDir + "/groups.txt", false);
  std::string str1 = "Кариева Анастасия Владиленовна";
  EXPECT_EQ(str1, deanary->findBestStudents(deanary->findGroupByTittle("Группа1"))[0]->getFio());
}

TEST(DeanaryTest, TestFunc3) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "../" + dataDir + "/students.txt", "../" + dataDir + "/groups.txt", false);
  EXPECT_EQ(false, deanary->fireStudents());
}

TEST(DeanaryTest, TestFunc4) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "../" + dataDir + "/students.txt", "../" + dataDir + "/groups.txt", false);
  std::string str1 = "Лешев Иван Проклович";
  EXPECT_EQ(str1, deanary->findWorstStudents(deanary->findGroupByTittle("Группа1"))[1]->getFio());
}

TEST(DeanaryTest, TestFunc5) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "../" + dataDir + "/students.txt", "../" + dataDir + "/groups.txt", false);
  Student* st = deanary->findGroupByTittle("Группа1")->getStudentByFio("Кариева Анастасия Владиленовна");
  deanary->moveStudents("Кариева Анастасия Владиленовна", "Группа2");
  EXPECT_EQ(false, deanary->findGroupByTittle("Группа1")->containsStudent(st));
}

TEST(DeanaryTest, TestFunc6) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "../" + dataDir + "/students.txt", "../" + dataDir + "/groups.txt", false);
  deanary->moveStudents("Кариева Анастасия Владиленовна", "Группа3");
  EXPECT_EQ("Кариева Анастасия Владиленовна", deanary->findGroupByTittle("Группа3")->getStudentByFio("Кариева Анастасия Владиленовна")->getFio());
}

TEST(GroupTest, TestFunc1) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "../" + dataDir + "/students.txt", "../" + dataDir + "/groups.txt", false);
  EXPECT_EQ("Группа1", deanary->findGroupByTittle("Группа1")->getTitle());
}

TEST(GroupTest, TestFunc2) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "../" + dataDir + "/students.txt", "../" + dataDir + "/groups.txt", false);
  EXPECT_EQ("Кариева Анастасия Владиленовна", deanary->findGroupByTittle("Группа1")->getHead()->getFio());
}

TEST(GroupTest, TestFunc3) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "../" + dataDir + "/students.txt", "../" + dataDir + "/groups.txt", false);
  EXPECT_FLOAT_EQ(5.0f, deanary->findGroupByTittle("Группа1")->getAvarageMark());
}

TEST(GroupTest, TestFunc4) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "../" + dataDir + "/students.txt", "../" + dataDir + "/groups.txt", false);
  Student* st = deanary->findGroupByTittle("Группа1")->getStudentByFio("Кариева Анастасия Владиленовна");
  EXPECT_EQ(true, deanary->findGroupByTittle("Группа1")->containsStudent(st));
}
