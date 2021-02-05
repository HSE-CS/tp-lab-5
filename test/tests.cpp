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

TEST(StudentTest, test3) {
Student *student = new Student(0, "Ksuvot");
EXPECT_EQ(true, student->GetMarks().empty());
delete student;
}

TEST(StudentTest, test4) {
Student *student = new Student(0, "Ksuvot");
student->setMark(0);
student->setMark(1);
EXPECT_EQ(0, student->GetMarks()[1]);
delete student;
}

TEST(GroupTest, test5) {
Group *group = new Group("title", "spec");
EXPECT_EQ("spec", group->GetSpec());
delete group;
}

TEST(GroupTest, test6) {
Group *group = new Group("title", "spec");
EXPECT_EQ("title", group->GetTitle());
delete group;
}

TEST(GroupTest, test7) {
Group *group = new Group("title", "spec");
Student *student = new Student(1, "name");
group->setStudent(student);
group->chooseHeadmen();
EXPECT_EQ("name", group->GetHead()->GetFio());
delete group;
delete student;
}

TEST(GroupTest, test8) {
Group *group = new Group("title", "spec");
Student *student = new Student(1, "name");
group->setStudent(student);
EXPECT_EQ("name", group->getStudent(1)->GetFio());
delete group;
delete student;
}

/*TEST(StudentTest, test8) {
Student *student = new Student(1, "name");
student->setMark(10);
student->setMark(9);
student->setMark(6);
student->setMark(7);
EXPECT_EQ(8, student->getAverageMark());
delete student;
}

TEST(DeanaryTest, test9) {
Group *group = new Group("title", "spec");
Student *student = new Student(1, "name");
student->setMark(10);
student->setMark(9);
student->setMark(8);
student->setMark(7);
group->setStudent(student);
Deanary *deanary = new Deanary();
deanary->createGroups();
EXPECT_EQ(8.5, deanary->getStatistics());
delete group;
delete student;
delete deanary;
}*/

TEST(GroupTest, test10) {
Group *group = new Group("title", "spec");
EXPECT_EQ(0, 0+group->isEmpty());
delete group;
}
