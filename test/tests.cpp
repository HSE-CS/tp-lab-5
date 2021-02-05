//  Copyright © 2021 Ksuvot. All rights reserved.

#include <gtest/gtest.h>
#include <string>
#include <cstring>

#include "Group.h"
#include "Student.h"
#include "Deanary.h"

TEST(StudentTest, test1) {
Student *student = new Student(0, "Ksuvot");
EXPECT_EQ(0, student->GetId());
delete student;
}

TEST(StudentTest, test2) {
Student *student = new Student(0, "Ksuvot");
EXPECT_EQ("Ksuvot", student->GetFio());
delete student;
}

/*TEST(StudentTest, test3) {
Student student(1, "Ksuvot");
EXPECT_EQ(0, student.GetMarks());
}

TEST(GroupTest, test4) {
Group group("title", "spec");
EXPECT_EQ("spec", group.GetSpec());
}

TEST(GroupTest, test5) {
Group group("title", "spec");
EXPECT_EQ("title", group.GetTitle());
}

TEST(GroupTest, test6) {
Group group1("title", "spec");
Student student1(11, "name");
group1.setStudent(&student1);
group1.chooseHeadmen();
EXPECT_EQ("name", group1.GetHead()->GetFio());
}

TEST(GroupTest, test7) {
Group group2("title", "spec");
Student student3(1, "name");
group2.setStudent(&student3);
EXPECT_EQ("name", group2.getStudent(1)->GetFio());
}

TEST(StudentTest, test8) {
Student student2(121, "name");
student2.setMark(10);
student2.setMark(9);
student2.setMark(8);
student2.setMark(7);
EXPECT_EQ(8.5, student2.getAverageMark());
}*/

/*TEST(DeanaryTest, test9) {
Group group3("title", "spec");
Student student4(8, "name");
student4.setMark(10);
student4.setMark(9);
student4.setMark(8);
student4.setMark(7);
group3.setStudent(&student4);
Deanary deanary;
deanary.createGroups();
EXPECT_EQ(8.5, deanary.getStatistics());
}

TEST(DeanaryTest, test10) {
Group group4("title", "spec");
Student student5(101, "name");
student5.setMark(10);
student5.setMark(9);
student5.setMark(8);
student5.setMark(7);
group4.setStudent(&student5);
Deanary denary1;
denary1.createGroups();
EXPECT_EQ(8.5, denary1.getStatistics());
}*/
