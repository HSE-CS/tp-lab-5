// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include "Deanary.h"
#include <string>

TEST(Student_Test, test1) {
Student student_1(6, "Вася Пупкин1");
EXPECT_EQ(6, student_1.get_id());
}

TEST(Student_Test, test2) {
Student student_1(7, "Вася Пупкин2");
EXPECT_EQ(7, student_1.get_id());
}

TEST(Student_Test, test3) {
Student student_1(15, "Вася Пупкин3");
EXPECT_EQ("Вася Пупкин 1", student_1.get_name());
}

TEST(Student_Test, test4) {
Student student_1(1, "Вася Пупкин4");
double res = 0;
EXPECT_EQ(res, student_1.average_mark());
}

TEST(Student_Test, test5) {
Student student_1(1, "Вася Пупкин5");
student_1.add_mark(9);
student_1.add_mark(9);
student_1.add_mark(9);
double res = 9;
EXPECT_EQ(res, student_1.average_mark());
}

TEST(Group_Test, test6) {
Group group_1("ПМИ6", "прикл. мат. и инф.");
EXPECT_EQ("прикл. мат. и инф.", group_1.get_spec());
}

TEST(Group_Test, test7) {
Group group_1("ПМИ7", "прикл. мат. и инф.");
EXPECT_EQ("ПМИ7", group_1.get_title());
}

TEST(Group_Test, test8) {
Group group_1("ПМИ8", "прикл. мат. и инф.");
double res = 0;
EXPECT_EQ(res, group_1.average_mark());
}

TEST(Deanary_Test, test9) {
Deanary HSE;

Student student_1(1, "Вася Пупкин9");
student_1.add_mark(9);
student_1.add_mark(9);
student_1.add_mark(9);

Group group_1("пими", "прикл. мат. и инф.");
HSE.add_group(group_1);
HSE.add_student(& student_1, "прикл. мат. и инф.");

double res = 9;
EXPECT_EQ(res, HSE.get_statistic_students("Вася Пупкин9"));
}

TEST(Deanary_Test, test10) {
Deanary HSE;

Student student_1(1, "Вася Пупкин10");
Student student_2(1, "Вася Пупкин10доп");
student_1.add_mark(9);
student_1.add_mark(9);
student_1.add_mark(9);

student_2.add_mark(5);
student_2.add_mark(5);
student_2.add_mark(5);

Group Fil("МПИ1", "прикл. мат. и инф.");
HSE.add_group(Fil);
HSE.add_student(&student_1, "Фприкл. мат. и инф.");
HSE.add_student(&student_2, "прикл. мат. и инф.");

double res = 7;
EXPECT_EQ(res, HSE.get_statistic_groups("прикл. мат. и инф."));
}