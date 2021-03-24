// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include "Deanary.h"
#include <string>
TEST(Student_Test, test1) 
{
	Student student_1(5, "Сергей Кузнецов");
	EXPECT_EQ(5, student_1.get_id());
}
TEST(Student_Test, test2) 
{
	Student student_1(8, "Александра Денисова");
	EXPECT_EQ(8, student_1.get_id());
}
TEST(Student_Test, test3) 
{
	Student student_1(15, "Виктор Смирнов");
	EXPECT_EQ("Виктор Смирнов", student_1.get_name());
}
TEST(Student_Test, test4) 
{
	Student student_1(1, "Полина Гусева");
	double res = 0;
	EXPECT_EQ(res, student_1.average_mark());
}
TEST(Student_Test, test5) 
{
	Student student_1(1, "Виктор Смирнов");
	student_1.add_mark(9);
	student_1.add_mark(9);
	student_1.add_mark(9);
	double res = 9;
	EXPECT_EQ(res, student_1.average_mark());
}

TEST(Group_Test, test6) 
{
	Group group_1("ФИ2", "Филология");
	EXPECT_EQ("Филология", student_1.get_spec());
	EXPECT_EQ("Филология", group_1.get_spec());
}

TEST(Group_Test, test7) 
{
	Group group_1("ФИ2", "Филология");
	EXPECT_EQ("ФИ2", group_1.get_title());
}
TEST(Group_Test, test8) 
{
	Group group_1("Фи8", "Филология");
	double res = 0;
	EXPECT_EQ(res, student_1.average_mark());
	EXPECT_EQ(res, group_1.average_mark());
}

TEST(Deanary_Test, test9) 
{
	Deanary HSE;
	Student student_1(1, "Виктор Смирнов");
	student_1.add_mark(9);
	student_1.add_mark(9);
	student_1.add_mark(9);
	Group group_1("Ec", "Филология");
	HSE.add_group(group_1);
	HSE.add_student(&student_1, "Филология");
	double res = 9;
	EXPECT_EQ(res, HSE.get_statistic_students("Виктор Смирнов"));
}
TEST(Deanary_Test, test10) 
{
	Deanary HSE;
	Student student_1(1, "Виктор Смирнов");
	Student student_2(1, "Захар Потапов");
	student_1.add_mark(9);
	student_1.add_mark(9);
	student_1.add_mark(9);
	student_2.add_mark(5);
	student_2.add_mark(5);
	student_2.add_mark(5);
	Group Fil("Фил1", "Филология");
	HSE.add_group(Fil);
	HSE.add_student(&student_1, "Филология");
	HSE.add_student(&student_2, "Филология");
	double res = 7;
	EXPECT_EQ(res, HSE.get_statistic_groups("Филология"));
}