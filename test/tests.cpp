// Copyright 2021 GN
#include <gtest/gtest.h>
#include "Deanary.h"
#include <string>

TEST(StudentTest, test1) {
    std::string name = "Ivanov Ivan";
    Student test(1, name);
    EXPECT_EQ(1, test.getId());
}

TEST(StudentTest, test2) {
    std::string name = "Ivanov Ivan";
    Student test(1, name);
    EXPECT_EQ(name, test.getName());
}

TEST(StudentTest, test3) {
    std::string name = "Ivanov Ivan";
    Student test(1, name);
    double res = 0;
    EXPECT_EQ(res, test.avMark());
}

TEST(GroupTest, test4) {
    std::string title = "Applied Mathematics and Informatics";
    std::string spec = "AMI";
    Group test(title, spec);
    EXPECT_EQ(title, test.getName());
}

TEST(GroupTest, test5) {
    std::string title = "Applied Mathematics and Informatics";
    std::string spec = "AMI";
    Group test(title, spec);
    EXPECT_EQ(spec, test.getSpec());
}

TEST(GroupTest, test6) {
    std::string title = "Applied Mathematics and Informatics";
    std::string spec = "AMI";
    Group test_gr(title, spec);
    std::string name = "Ivanov Ivan";
    Student test_st(1, name);
    test_gr.addStudent(&test_st);
    test_gr.initHead();
    EXPECT_EQ(name, test_gr.getHead().getName());
}

TEST(StudentTest, test7) {
    Student test_st(41, "Perov I.I.");
    test_st.addMark(7);
    test_st.addMark(4);
    test_st.addMark(3);
    test_st.addMark(0);
    EXPECT_EQ(3.5, test_st.avMark());
}

TEST(GroupTest, test8) {
    std::string title = "Applied Mathematics and Informatics";
    std::string spec = "AMI";
    Group test_gr(title, spec);
    std::string name = "Ivanov Ivan";
    Student test_st(101, name);
    test_gr.addStudent(&test_st);
    EXPECT_EQ(name, test_gr.getStudent(101).getName());
}

TEST(DeanaryTest, test9) {
    std::string title = "Applied Mathematics and Informatics";
    std::string spec = "AMI";
    Group test_gr(title, spec);
    std::string name = "Ivanov Ivan";
    Student test_st(101, name);
    test_st.addMark(7);
    test_st.addMark(4);
    test_st.addMark(3);
    test_st.addMark(0);
    test_gr.addStudent(&test_st);
    Deanary test_dr;
    test_dr.addGroup(test_gr);
    EXPECT_EQ(3.5, test_dr.getStatisticByStudents(name));
}

TEST(DeanaryTest, test10) {
    std::string title = "Applied Mathematics and Informatics";
    std::string spec = "AMI";
    Group test_gr(title, spec);
    std::string name = "Ivanov Ivan";
    Student test_st(101, name);
    test_st.addMark(7);
    test_st.addMark(4);
    test_st.addMark(3);
    test_st.addMark(0);
    test_gr.addStudent(&test_st);
    Deanary test_dr;
    test_dr.addGroup(test_gr);
    EXPECT_EQ(3.5, test_dr.getStatisticByGroups(spec));
}
