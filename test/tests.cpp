// Copyright 2021 Bodrov Egor

#include <gtest/gtest.h>
#include <string>

#include "Student.h"
#include "Group.h"
#include "Deanary.h"

TEST(student_test, test1) {
    Student s {12, "Egor Bodrov"};
    EXPECT_EQ("Egor Bodrov", s.get_name());
}

TEST(student_test, test2) {
    Student s {12, "Egor Bodrov"};
    EXPECT_EQ(12, s.get_id());
}

TEST(student_test, test3) {
    Student s {12, "Egor Bodrov"};
    s.addmark(5);
    s.addmark(6);
    s.addmark(10);
    EXPECT_EQ(7.0, s.getAveragemark());
}

TEST(group_test, test4) {
    Group gr {"19SE-2", "SE"};
    EXPECT_EQ(true, gr.isEmpty());
}

TEST(group_test, test5) {
    Student s1 {12, "Egor Bodrov"};
    Student s2 {50, "Michele Bekuson"};
    Group gr {"19SE-2", "SE"};
    gr.addStudent(&s1);
    gr.addStudent(&s2);
    EXPECT_EQ("Egor Bodrov", gr.getStudent(12)->get_name());
}

TEST(group_test, test6) {
    Student s1 {12, "Egor Bodrov"};
    Student s2 {50, "Michele Bekuson"};
    Group gr {"19SE-2", "SE"};
    gr.addStudent(&s1);
    gr.addStudent(&s2);
    EXPECT_EQ(50, gr.getStudent("Michele Bekuson")->get_id());
}

TEST(student_test, test7) {
    Student s1 {12, "Egor Bodrov"};
    Group gr {"19SE-2", "SE"};
    gr.addStudent(&s1);
    gr.chooseHead(&s1);
    EXPECT_EQ(true, s1.isHeadOfGroup());
}

TEST(group_test, test8) {
    Student s1 {12, "Egor Bodrov"};
    Group gr {"19SE-2", "SE"};
    gr.addStudent(&s1);
    gr.chooseHead(&s1);
    gr.removeStudent(&s1);
    EXPECT_EQ(false, s1.isHeadOfGroup());
}

TEST(group_test, test9) {
    Student s1 {12, "Egor Bodrov"};
    Student s2 {50, "Michele Bekuson"};
    Group gr1 {"19SE-2", "SE"};
    gr1.addStudent(&s1);
    gr1.addStudent(&s2);
    s1.addmark(10);
    s1.addmark(10);
    s2.addmark(10);
    s2.addmark(10);
    EXPECT_EQ(10.0, gr1.getAveragemark());
}

TEST(group_test, test10) {
    Student s1 {12, "Egor Bodrov"};
    Student s2 {50, "Michele Bekuson"};
    Student s3 {11, "Bodrov Egor"};
    Student s4 {77, "Bekuson Michele"};
    Group gr1 {"19SE-2", "SE"};
    gr1.addStudent(&s1);
    gr1.addStudent(&s2);
    gr1.addStudent(&s3);
    gr1.addStudent(&s4);
    gr1.removeStudent(&s1);
    gr1.removeStudent(&s2);
    gr1.removeStudent(&s3);
    gr1.removeStudent(&s4);
    EXPECT_EQ(true, gr1.isEmpty());
}
