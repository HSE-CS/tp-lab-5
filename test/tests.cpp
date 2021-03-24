// Copyright 2021 Tyulin Igor

#include <gtest/gtest.h>
#include <string>
#include "Deanary.h"

TEST(Student_Test, test1) {
Student student_1(11, "Max Has");
EXPECT_EQ(11, student_1.stud_id());
}

TEST(Student_Test, test2) {
Student student_1(5, "Igi Bugi");
EXPECT_EQ(5, student_1.stud_id());
}

TEST(Student_Test, test3) {
Student student_1(1, "Vasya Nia");
EXPECT_EQ("Vasya Nia", student_1.stud_fio());
}

TEST(Student_Test, test4) {
Student student_1(1, "Vasya Nia");
student_1.mark_add(6);
double res = 6;
EXPECT_EQ(res, student_1.average_mark());
}

TEST(Student_Test, test5) {
Group se("19pi-1", "software engineering");
EXPECT_EQ("software engineering", se.getspec());
}

TEST(Student_Test, test6) {
Group se("19pi-1", "software engineering");
EXPECT_EQ("19pi-1", se.getitle());
}

TEST(Student_Test, test7) {
Group se("19pi-1", "software engineering");
Student student_1(9, "Michail Volkov");
student_1.group_add(&se);
student_1.mark_add(6);
se.addstud(&student_1);
double res = 6;
EXPECT_EQ(res, se.studavermarks());
}

TEST(Student_Test, test8) {
Group se("19pi-1", "software engineering");
Student student_1(9, "Michail Volkov");
student_1.group_add(&se);
student_1.mark_add(6);
Student student_2(3, "Max Has");
student_2.group_add(&se);
student_2.mark_add(10);
se.addstud(&student_1);
se.addstud(&student_2);
double res = 8;
EXPECT_EQ(res, se.studavermarks());
}

TEST(Student_Test, test9) {
Group se("19pi-1", "software engineering");
Student student_1(9, "Michail Volkov");
student_1.mark_add(6);
se.addstud(&student_1);
se.sethead(&student_1);
EXPECT_EQ("Michail Volkov", se.gethead());
}

TEST(Student_Test, test10) {
Group se("19pi-1", "software engineering");
Student student_1(9, "Michail Volkov");
se.addstud(&student_1);
se.sethead(&student_1);
Student student_2(1, "MAX HAS");
se.addstud(&student_2);
se.sethead(&student_2);
EXPECT_EQ("MAX HAS", se.gethead());
}
