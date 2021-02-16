// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>

#include "Student.h"
#include "Group.h"
#include "Deanary.h"

TEST(deanary_test, test1) {
	Student s(0, "Ivan Ivanov");
	EXPECT_EQ("Ivan Ivanov", s.getName());
}

TEST(deanary_test, test2) {
	Student s(23, "Ivan Ivanov");
	EXPECT_EQ(23, s.getId());
}

TEST(deanary_test, test3) {
	Student s(1, "Ivan Ivanov");
	s.addmark(6);
	s.addmark(4);
	EXPECT_EQ(5.0, s.getAveragemark());
}

TEST(deanary_test, test4) {
	Group g("19PI", "PI");
	Student s(1, "Ivan Ivanov");
	g.addStudent(&s);
	EXPECT_EQ(false, g.isEmpty());
}

TEST(deanary_test, test5) {
	Student s1(1, "Ivan Ivanov");
	Student s2(2, "Petr Petrov");
	Group g("19PI", "PI");
	g.addStudent(&s1);
	g.addStudent(&s2);
	EXPECT_EQ(1, g.getStudent("Ivan Ivanov")->getId());
}

TEST(deanary_test, test6) {
	Student s1(1, "Ivan Ivanov");
	Student s2(2, "Petr Petrov");
	Group g("19PI", "PI");
	g.addStudent(&s1);
	g.addStudent(&s2);
	EXPECT_EQ("Petr Petrov", g.getStudent(2)->getName());
}

TEST(deanary_test, test7) {
	Student s1(1, "Ivan Ivanov");
	Group g("19PI", "PI");
	g.addStudent(&s1);
	EXPECT_EQ(false, s1.isHeadOfGroup());
}

TEST(deanary_test, test8) {
	Student s1(1, "Ivan Ivanov");
	Group g("19PI", "PI");
	g.addStudent(&s1);
	g.chooseHead(&s1);
	EXPECT_EQ(true, s1.isHeadOfGroup());
}

TEST(deanary_test, test9) {
	Student s1(0, "Ivan Ivanov");
	Student s2(1, "Petr Petrov");
	Student s3(2, "Eric Ericov");
	Group g("19PI", "PI");
	g.addStudent(&s1);
	g.addStudent(&s2);
	g.addStudent(&s3);
	g.removeStudent(&s1);
	g.removeStudent(&s2);
	g.removeStudent(&s3);
	EXPECT_EQ(true, g.isEmpty());
}

TEST(deanary_test, test10) {
	Student s1(1, "Ivan Ivanov");
	Student s2(2, "Petr Petrov");
	Group g("19PI", "PI");
	g.addStudent(&s1);
	g.addStudent(&s2);
	s1.addmark(8);
	s1.addmark(8);
	s2.addmark(8);
	s2.addmark(8);
	EXPECT_EQ(8.0, g.getAveragemark());
}
