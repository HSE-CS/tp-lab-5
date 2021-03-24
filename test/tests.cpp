// Copyright 2021 Tyulin Igor

#include <gtest/gtest.h>
#include <string>
#include "Deanary.h"

TEST(Student_Test, test1) {
Student student_1(11, "Max Has");
EXPECT_EQ(11, student_1.get_id());
}

TEST(Student_Test, test2) {
Student student_1(5, "Igi Bugi");
EXPECT_EQ(5, student_1.get_id());
}

TEST(Student_Test, test3) {
Student student_1(1, "Vasya Nia");
EXPECT_EQ("Vasya Nia", student_1.get_fio());
}

TEST(Student_Test, test4) {
Student student_1(1, "Vasya Nia");
student_1.mark_add(6);
EXPECT_EQ(6, student_1.get_average_mark());
}

TEST(Student_Test, test5) {
Group se("19pi-1", "software engineering");
EXPECT_EQ("software engineering", se.getspec());
}

TEST(Student_Test, test6) {
Group se("19pi-1", "software engineering");
EXPECT_EQ("software engineering", se.getitle());
}

TEST(Student_Test, test7) {
Group se("19pi-1", "software engineering");
Student student_1(9, "Michail Volkov");
student_1.group_add(&se);
student_1.mark_add(6);
EXPECT_EQ(6, se.studavermarks());
}

TEST(Student_Test, test8) {
Group se("19pi-1", "software engineering");
Student student_1(9, "Michail Volkov");
student_1.group_add(&se);
student_1.mark_add(6);
Student student_2(3, "Max Has");
student_2.group_add(&se);
student_2.mark_add(10);
EXPECT_EQ(8, se.studavermarks());
}

TEST(Student_Test, test9) {
Deanary club;
Group se("19pi-1", "software engineering");
Student student_1(9, "Michail Volkov");
student_1.mark_add(6);
club.createGroups(se);
club.hireStudents(&student_1,"software engineering");
EXPECT_EQ("Group 19pi-1 statistics: 6\nStudent Michail Volkov statistics: 6", se.studavermarks());
}

TEST(Student_Test, test10) {
Deanary club;
Group se("19pi-1", "software engineering");
Student student_1(9, "Michail Volkov");
student_1.mark_add(6);
club.createGroups(se);
club.hireStudents(&student_1,"software engineering");
Student student_2(2, "Ya Zdes");
student_2.group_add(&se);
student_2.mark_add(1);
club.hireStudents(&student_2,"software engineering");
EXPECT_EQ("Group 19pi-1 statistics: 3.5\nStudent Michail Volkov statistics: 6\nStudent Ya Zdes statistics: 1", se.studavermarks());
}