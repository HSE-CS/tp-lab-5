// Copyright 2021 Schenikova

#include <string>
#include "Group.h"
#include "Student.h"
#include "Deanary.h"
#include "gtest/gtest.h"

TEST(StudentTest, test1) {
  unsigned int id = 12345678;
  std::string Fio = "Veselov Ignatiy Lvovich";
  Student student(id, Fio);
  EXPECT_EQ(12345678, student.getId());
}

TEST(StudentTest, test2) {
  unsigned int id = 98765432;
  std::string Fio = "Naumov Velor Iosifovich";
  Student student(id, Fio);
  student.addMark(10);
  EXPECT_EQ(10.0, student.getAveragemark());
}

TEST(GroupTest, test3) {
  unsigned int id = 98765432;
  std::string Fio = "Artemiev Frol Alekseevich";
  Student student(id, Fio);
  std::string spec = "PI";
  std::string title = "19PI-1";
  Group group(title, spec);
  student.addMark(10);
  group.addStudent(&student);
  student.addToGroup(&group);
  EXPECT_EQ(&student, group.getStudentById(98765432));
}

TEST(GroupTest, test4) {
  unsigned int id = 98765432;
  std::string Fio = "Naumov Velor Iosifovich";
  Student student(id, Fio);
  std::string spec = "PI";
  std::string title = "19PI-1";
  Group group(title, spec);
  student.addMark(10);
  group.addStudent(&student);
  student.addToGroup(&group);
  EXPECT_EQ(&group, student.getGroup());
}

TEST(GroupTest, test5) {
  unsigned int id = 93649276;
  std::string Fio = "Naumov Arkhip Arsenievich";
  Student student(id, Fio);
  std::string spec = "PI";
  std::string title = "19PI-1";
  Group group(title, spec);
  student.addMark(10);
  student.addMark(10);
  student.addMark(10);
  student.addMark(10);
  group.addStudent(&student);
  student.addToGroup(&group);
  student.getAveragemark();
  EXPECT_EQ(10.0, group.getAveragemark());
}

TEST(GroupTest, test6) {
  unsigned int id = 12345678;
  std::string Fio = "Naumov Arkhip Arsenievich";
  Student student(id, Fio);
  std::string spec = "PI";
  std::string title = "19PI-1";
  Group group(title, spec);
  student.addMark(9);
  student.addMark(8);
  student.addMark(10);
  student.addMark(0);
  group.addStudent(&student);
  student.addToGroup(&group);
  student.getAveragemark();
  group.chooseHead();
  EXPECT_EQ(true, student.isHeadOfGroup());
}

TEST(GroupTest, test7) {
  unsigned int id = 09876543;
  std::string Fio = "Tarasov Kazimir Mikhailovich";
  Student student(id, Fio);
  std::string spec = "PI";
  std::string title = "19PI-1";
  Group group(title, spec);
  group.addStudent(&student);
  student.addToGroup(&group);
  student.getAveragemark();
  group.chooseHead();
  EXPECT_EQ(false, group.isEmpty());
}

TEST(GroupTest, test8) {
  unsigned int id = 13547569;
  std::string Fio = "Voronov Akim Arkadievich";
  Student student(id, Fio);
  std::string spec = "PI";
  std::string title = "19PI-1";
  Group group(title, spec);
  EXPECT_EQ(true, group.isEmpty());
}

TEST(DeaneryTest, test9) {
  unsigned int id = 12345678;
  std::string Fio = "Morozov Innokenty Sergeevich";
  Student student1(id, Fio);
  std::string spec = "PI";
  std::string title = "19PI-1";
  Group group(title, spec);
  group.addStudent(&student1);
  student1.addToGroup(&group);
  group.removeStudent(&student1);
  EXPECT_EQ(nullptr, group.getStudent(Fio));
}

TEST(DeaneryTest, test10) {
  unsigned int id = 12345678;
  std::string Fio = "Morozov Innokenty Sergeevich";
  Student student1(id, Fio);
  std::string spec = "PI";
  std::string title = "19PI-1";
  Group group(title, spec);
  group.addStudent(&student1);
  student1.addToGroup(&group);
  EXPECT_EQ(&student, group.getStudent(Fio));
}


