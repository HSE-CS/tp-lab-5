// Copyright 2021 FOM

#include <gtest/gtest.h>
#include <string>
#include "Deanary.h"

TEST(Deanary_Test, test_1) {
	Student student_test_1(3, "Pogodin Kim Matveevich");
	EXPECT_EQ(3, student_test_1.student_ID());
}

TEST(Deanary_Test, test_2) {
	Student student_test_2(453, "Khromov Lavrenty Adrianovich");
	EXPECT_EQ(453, student_test_2.student_ID());
}

TEST(Deanary_Test, test_3) {
	Student student_test_3(8, "Pichushkin Radion Vsevolodovich");
	EXPECT_EQ("Pichushkin Radion Vsevolodovich", student_test_3.student_FIO());
}

TEST(Deanary_Test, test_4) {
	Student student_test_4(67, "Zestakova Antip Filippovich");
	EXPECT_EQ("Zestakova Antip Filippovich", student_test_4.student_FIO());
}

TEST(Deanary_Test, test_5) {
	Student student_test_5(5, "Vetochkin Izyaslav Samsonovich");
	EXPECT_EQ(0, student_test_5.student_mark_avarage());
}

TEST(Deanary_Test, test_6) {
	Student student_test_6(5, "Onegin Kondraty Kondratovich");
	student_test_6.add_mark(7);
	EXPECT_EQ(7, student_test_6.student_mark_avarage());
}

TEST(Deanary_Test, test_7) {
	Student student_test_7(5, "Zholdin Yulian Cheslavovich");
	student_test_7.add_mark(8);
	student_test_7.add_mark(8);
	student_test_7.add_mark(8);
	student_test_7.add_mark(8);
	EXPECT_EQ(8, student_test_7.student_mark_avarage());
}

TEST(Deanary_Test, test_8) {
	Group test_8("19PMI-1", "PMI");
	EXPECT_EQ("19PMI-1", test_8.get_title());
}

TEST(Deanary_Test, test_9) {
	Group test_9("19PI-2", "PI");
	EXPECT_EQ("19PI-2", test_9.get_title());
}

TEST(Deanary_Test, test_10) {
	Group test_10("19Math-3", "Math");
	EXPECT_EQ("19Math-3", test_10.get_title());
}

TEST(Deanary_Test, test_11) {
	Group test_11("19PMI-1", "PMI");
	EXPECT_EQ("PMI", test_11.get_spec());
}

TEST(Deanary_Test, test_12) {
	Group test_12("19PI-2", "PI");
	EXPECT_EQ("PI", test_12.get_spec());
}

TEST(Deanary_Test, test_13) {
	Group test_13("19Math-3", "Math");
	EXPECT_EQ("Math", test_13.get_spec());
}

TEST(Deanary_Test, test_14) {
	Student student_test_14_1(35, "Begichev Timur Feoktistovich");
	Student student_test_14_2(25, "Vodopyanov Luka Ostapovich");
	Student student_test_14_3(6, "Yarema Kasyan Semenovich");

	student_test_14_1.add_mark(3);
	student_test_14_1.add_mark(4);
	student_test_14_1.add_mark(2);
	student_test_14_1.add_mark(6);

	student_test_14_2.add_mark(6);
	student_test_14_2.add_mark(6);
	student_test_14_2.add_mark(7);
	student_test_14_2.add_mark(7);

	student_test_14_3.add_mark(8);
	student_test_14_3.add_mark(9);
	student_test_14_3.add_mark(10);
	student_test_14_3.add_mark(9);

	Group test_14("19PMI-1", "PMI");
	Deanary FIMIKN_1;
	FIMIKN_1.group_adding(test_14);
	FIMIKN_1.student_hire(&student_test_14_1, "PMI");
	FIMIKN_1.student_hire(&student_test_14_2, "PMI");
	FIMIKN_1.student_hire(&student_test_14_3, "PMI");
	EXPECT_EQ(3, FIMIKN_1.student_statistic("Begichev Timur Feoktistovich"));
}

TEST(Deanary_Test, test_15) {
	Student student_test_15_1(35, "Begichev Timur Feoktistovich");
	Student student_test_15_2(25, "Vodopyanov Luka Ostapovich");
	Student student_test_15_3(6, "Yarema Kasyan Semenovich");

	student_test_15_1.add_mark(3);
	student_test_15_1.add_mark(4);
	student_test_15_1.add_mark(2);
	student_test_15_1.add_mark(6);

	student_test_15_2.add_mark(6);
	student_test_15_2.add_mark(6);
	student_test_15_2.add_mark(7);
	student_test_15_2.add_mark(7);

	student_test_15_3.add_mark(8);
	student_test_15_3.add_mark(9);
	student_test_15_3.add_mark(10);
	student_test_15_3.add_mark(9);

	Group test_15("19PMI-1", "PMI");
	Deanary FIMIKN_2;
	FIMIKN_2.group_adding(test_15);
	FIMIKN_2.student_hire(&student_test_15_1, "PMI");
	FIMIKN_2.student_hire(&student_test_15_2, "PMI");
	FIMIKN_2.student_hire(&student_test_15_3, "PMI");
	EXPECT_EQ(6, FIMIKN_2.student_statistic("Vodopyanov Luka Ostapovich"));
}

TEST(Deanary_Test, test_16) {
	Student student_test_16_1(35, "Begichev Timur Feoktistovich");
	Student student_test_16_2(25, "Vodopyanov Luka Ostapovich");
	Student student_test_16_3(6, "Yarema Kasyan Semenovich");

	student_test_16_1.add_mark(3);
	student_test_16_1.add_mark(4);
	student_test_16_1.add_mark(2);
	student_test_16_1.add_mark(6);

	student_test_16_2.add_mark(6);
	student_test_16_2.add_mark(6);
	student_test_16_2.add_mark(7);
	student_test_16_2.add_mark(7);

	student_test_16_3.add_mark(8);
	student_test_16_3.add_mark(9);
	student_test_16_3.add_mark(10);
	student_test_16_3.add_mark(9);

	Group test_16("19PMI-1", "PMI");
	Deanary FIMIKN_3;
	FIMIKN_3.group_adding(test_16);
	FIMIKN_3.student_hire(&student_test_16_1, "PMI");
	FIMIKN_3.student_hire(&student_test_16_2, "PMI");
	FIMIKN_3.student_hire(&student_test_16_3, "PMI");
	EXPECT_EQ(9, FIMIKN_3.student_statistic("Yarema Kasyan Semenovich"));
}

TEST(Deanary_Test, test_17) {
	Student student_test_17_1(35, "Begichev Timur Feoktistovich");
	Student student_test_17_2(25, "Vodopyanov Luka Ostapovich");
	Student student_test_17_3(6, "Yarema Kasyan Semenovich");

	student_test_17_1.add_mark(3);
	student_test_17_1.add_mark(4);
	student_test_17_1.add_mark(2);
	student_test_17_1.add_mark(6);

	student_test_17_2.add_mark(6);
	student_test_17_2.add_mark(6);
	student_test_17_2.add_mark(7);
	student_test_17_2.add_mark(7);

	student_test_17_3.add_mark(8);
	student_test_17_3.add_mark(9);
	student_test_17_3.add_mark(10);
	student_test_17_3.add_mark(9);

	Group test_17("19PMI-1", "PMI");
	Deanary FIMIKN_4;
	FIMIKN_4.group_adding(test_17);
	FIMIKN_4.student_hire(&student_test_17_1, "PMI");
	FIMIKN_4.student_hire(&student_test_17_2, "PMI");
	FIMIKN_4.student_hire(&student_test_17_3, "PMI");
	EXPECT_EQ(6, FIMIKN_4.group_statistic("PMI"));
}
