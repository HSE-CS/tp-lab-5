// Copyright 2021 Nikita Naumov

#include <gtest/gtest.h>
#include <string>
#include "Deanary.h"
#include "Student.h"
#include "Group.h"

TEST(Student_test, test1) {
  Student StudentObj(0, "Name Surname");
  EXPECT_EQ(0, StudentObj.getId());
}
TEST(Student_test, test2) {
  Student StudentObj(0, "Name Surname");
  EXPECT_EQ(-1, StudentObj.getAverageMark());
}
TEST(Student_test, test3) {
  Student StudentObj(0, "Name Surname");
  StudentObj.addMarkToStudent(5);
  StudentObj.addMarkToStudent(10);
  StudentObj.addMarkToStudent(9);
  EXPECT_EQ(8, StudentObj.getAverageMark());
}
TEST(Student_test, test4) {
  Student StudentObj(0, "Name Surname");
  StudentObj.makeHead();
  EXPECT_EQ(true, StudentObj.isTheyHead());
}
TEST(Group_test, test5) {
  Student StudentObj(0, "Name Surname");
  Group GroupObj((std::string) "19AMI");
  EXPECT_EQ(false, GroupObj.findStudentByID(0));
}
TEST(Group_test, test6) {
  Student StudentObj(0, "Name Surname");
  Group GroupObj((std::string) "19AMI");
  EXPECT_EQ(false, GroupObj.findStudentByFIO((std::string)"Name Surname"));
}
TEST(Group_test, test7) {
  Student StudentObj(0, "Name Surname");
  Group GroupObj((std::string) "19AMI");
  GroupObj.addStudentToGroup(&StudentObj);
  EXPECT_EQ(true, GroupObj.findStudentByID(0));
}
TEST(Group_test, test8) {
  Student StudentObj(0, "Name Surname");
  Group GroupObj((std::string) "19AMI");
  GroupObj.addStudentToGroup(&StudentObj);
  EXPECT_EQ(true, GroupObj.findStudentByFIO((std::string) "Name Surname"));
}
TEST(Group_test, test9) {
  Student StudentObj(0, "Name Surname");
  Group GroupObj((std::string) "19AMI");
  GroupObj.addStudentToGroup(&StudentObj);
  EXPECT_EQ((std::string)"19AMI", GroupObj.getTitle());
}
TEST(Group_test, test10) {
  Student StudentObj(0, "Name Surname");
  StudentObj.addMarkToStudent(5);
  StudentObj.addMarkToStudent(10);
  StudentObj.addMarkToStudent(9);
  Student StudentObj1(1, "Nam Surname");
  StudentObj.addMarkToStudent(10);
  StudentObj.addMarkToStudent(10);
  StudentObj.addMarkToStudent(10);
  Group GroupObj((std::string)"19AMI");
  GroupObj.addStudentToGroup(&StudentObj);
  GroupObj.addStudentToGroup(&StudentObj1);
  EXPECT_EQ(9, GroupObj.getAverageGroupMark());
}
TEST(Deanary_test, test11) {
  Deanary DeanaryObj;
  Student StudentObj(0, "Name Surname");
  Student StudentObj1(1, "Nam Surname");
  Group GroupObj((std::string) "19AMI");
  DeanaryObj.addGroup(&GroupObj);
  DeanaryObj.addStudent(&StudentObj);
  DeanaryObj.addStudent(&StudentObj1);
  DeanaryObj.addStudentToGroup(&StudentObj, &GroupObj);
  DeanaryObj.addStudentToGroup(&StudentObj1, &GroupObj);
  EXPECT_EQ(2, DeanaryObj.getCurrentAmountOfStudents());
}
