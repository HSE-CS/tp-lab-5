// Copyright 2020 GHA Test Team
// #include "pch.h"
#include "gtest/gtest.h"
// #include "../Students/Data.cpp"
// #include "../Students/Deanary.cpp"
// #include "../Students/Group.cpp"
// #include "../Students/Student.cpp"
#include "DataReader.h"
#include "Student.h"
#include "Group.h"
#include "Deanary.h"

TEST(TestDeanary, Test1) {
    Student st;
    EXPECT_EQ(0, st.getId());
}

TEST(TestDeanary, Test2) {
    Student st(203, "Igumnova Natasha", nullptr, {5, 3, 4});
    EXPECT_EQ(4.0, st.getAveragemark());
}

TEST(TestDeanary, Test3) {
    Group gr("19PI-1", "Software engineering");
    EXPECT_EQ(true, gr.isEmpty());
}

TEST(TestDeanary, Test4) {
    Deanary dr(3, "../Students/data.txt");
    EXPECT_EQ("Oleg Komarov", dr.findSudentId(201)->getFio());
}

TEST(TestDeanary, Test5) {
    Deanary dr(3, "../Students/data.txt");
    Student* st = dr.findGroupTitle("19_1")->getStudent(108);
    dr.moveStudents(108, "19_3");
    EXPECT_EQ(false, dr.findGroupTitle("19_1")->containsStudents(st));
}

TEST(TestDeanary, Test6) {
    Deanary dr(3, "../Students/data.txt");
    Student* st = dr.findGroupTitle("19_1")->getStudent(108);
    dr.moveStudents(108, "19_3");
    EXPECT_EQ(true, dr.findGroupTitle("19_3")->containsStudents(st));
}

TEST(TestDeanary, Test7) {
	Deanary dr(3, "../Students/data.txt");
	EXPECT_EQ(5.0, dr.findSudentId(201)->getAveragemark());
}

TEST(TestDeanary, Test8) {
    Deanary dr(3, "../Students/data.txt");
    EXPECT_EQ(false, dr.findGroupTitle("19_1")->isEmpty());
}

TEST(TestDeanary, Test9) {
	Student st(203, "Igumnova Natasha", nullptr, { 5, 3, 4 });
	EXPECT_EQ(false, st.isHeadOfGroup());
}

TEST(TestDeanary, Test10) {
    Student st;
    EXPECT_EQ(0.0, st.getAveragemark());
}
