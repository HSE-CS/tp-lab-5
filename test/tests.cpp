// Copyright 2020 GHA Test Team
// #include "pch.h"
#include "gtest/gtest.h"
// #include "../Lab-5-source/DataReader.cpp"
// #include "../Lab-5-source/Deanary.cpp"
// #include "../Lab-5-source/Group.cpp"
// #include "../Lab-5-source/Student.cpp"
#include "DataReader.h"
#include "Student.h"
#include "Group.h"
#include "Deanary.h"


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
  Deanary deanary(3, "students.txt", "groups.txt", false);
  EXPECT_EQ(3, deanary.getNumberOfGroups());
}

TEST(DeanaryTest, TestFunc1) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "students.txt",
    "groups.txt", false);
  std::string str1 = "Lisov Savely Kirillovich";
  EXPECT_EQ(str1, deanary->findStudentByFio(str1)->getFio());
}

TEST(DeanaryTest, TestFunc2) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "students.txt",
    "groups.txt", false);
  std::string str1 = "Karieva Anastasia Vladilenovna";
  EXPECT_EQ(str1, deanary->findBestStudents(deanary->
    findGroupByTittle("Group1"))[0]->getFio());
}

TEST(DeanaryTest, TestFunc3) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "students.txt",
    "groups.txt", false);
  EXPECT_EQ(false, deanary->fireStudents());
}

TEST(DeanaryTest, TestFunc4) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "students.txt",
    "groups.txt", false);
  std::string str1 = "Leshev Ivan Brockovich";
  EXPECT_EQ(str1, deanary->findWorstStudents(deanary->
    findGroupByTittle("Group1"))[1]->getFio());
}

TEST(DeanaryTest, TestFunc5) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "students.txt",
    "groups.txt", false);
  Student* st = deanary->findGroupByTittle("Group1")->
    getStudentByFio("Karieva Anastasia Vladilenovna");
  deanary->moveStudents("Karieva Anastasia Vladilenovna", "Group3");
  EXPECT_EQ(false, deanary->findGroupByTittle("Group1")->containsStudent(st));
}

TEST(DeanaryTest, TestFunc6) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "students.txt",
    "groups.txt", false);
  deanary->moveStudents("Karieva Anastasia Vladilenovna", "Group3");
  EXPECT_EQ("Karieva Anastasia Vladilenovna",
    deanary->findGroupByTittle("Group3")->getStudentByFio(
      "Karieva Anastasia Vladilenovna")->getFio());
}

TEST(GroupTest, TestFunc1) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "students.txt",
   "groups.txt", false);
  EXPECT_EQ("Group1", deanary->findGroupByTittle("Group1")->getTitle());
}

TEST(GroupTest, TestFunc2) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "students.txt",
    "groups.txt", false);
  EXPECT_EQ("Karieva Anastasia Vladilenovna",
    deanary->findGroupByTittle("Group1")->getHead()->getFio());
}

TEST(GroupTest, TestFunc3) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "students.txt",
    "groups.txt", false);
  EXPECT_FLOAT_EQ(5.0f, deanary->findGroupByTittle(
    "Group1")->getAvarageMark());
}

TEST(GroupTest, TestFunc4) {
  setlocale(LC_ALL, "Russian");
  Deanary* deanary = new Deanary(3, "students.txt",
   "groups.txt", false);
  Student* st = deanary->findGroupByTittle("Group1")->
    getStudentByFio("Karieva Anastasia Vladilenovna");
  EXPECT_EQ(true, deanary->findGroupByTittle("Group1")->containsStudent(st));
}
