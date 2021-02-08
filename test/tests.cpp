// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include "Deanary.h"
#include <string>
#include <fstream>

TEST(Student_Test, test1) {
Student student_1(69, "Витя Кэнг");
EXPECT_EQ(69, student_1.get_id());
}

TEST(Student_Test, test2) {
Student student_1(228, "Игорь Тюлин");
EXPECT_EQ(228, student_1.get_id());
}

TEST(Student_Test, test3) {
Student student_1(322, "Никита Мушка");
EXPECT_EQ("Никита Мушка", student_1.get_fio());
}

TEST(Student_Test, test4) {
Student student_1(1, "Мияги Эндшпиль");
double res = 0;
EXPECT_EQ(res, student_1.get_average_mark());
}

TEST(Student_Test, test5) {
Student student_1(1, "Скриптонит Костин");
student_1.add_mark(9);
student_1.add_mark(8);
student_1.add_mark(7);
student_1.add_mark(6);
student_1.add_mark(5);
student_1.add_mark(4);
student_1.add_mark(3);
student_1.add_mark(2);
double res = 2;
EXPECT_EQ(res, student_1.get_average_mark());
}

TEST(Group_Test, test6) {
Group group_1("ПИ228", "прикладная математика и информатика");
EXPECT_EQ("прикладная математика и информатика", group_1.get_spec());
}

TEST(Group_Test, test7) {
Group group_1("БИ3", "прикладная математика и информатика");
EXPECT_EQ("БИ3", group_1.get_title());
}

TEST(Group_Test, test8) {
Group group_1("ПИ0", "прикладная математика и информатика");
double res = 0;
EXPECT_EQ(res, group_1.average_mark_group());
}

TEST(Deanary_Test, test9) {
Deanary HSE;

Student student_1(1, "Виктор КЭнг");
student_1.add_mark(9);

Group group_1("ПИДО", "прикладная математика и информатика");
HSE.add_group();
HSE.add_student(& student_1, "прикладная математика и информатика");

double res = 9;
EXPECT_EQ(res, HSE.get_statistic_students("Виктор КЭнг"));
}

TEST(Deanary_Test, test10) {
Deanary HSE;

Student student_1(1, "Гош аН");
Student student_2(1, "мУ Шка");
student_1.add_mark(9);

student_2.add_mark(5);

Group Fil("ПИ2", "тима кенгов");
const std::string groupsFilePath("./groups.txt");
std::ifstream groupsStream(groupsFilePath, std::ios::in);
HSE.add_group(groupsStream);
HSE.add_student(&student_1, "тима кенгов");
HSE.add_student(&student_2, "тима кенгов");

double res = 7;
EXPECT_EQ(res, HSE.get_statistic_groups("тима кенгов"));
}

