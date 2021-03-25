// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"

TEST(test, test1) {
    int id = 5;
    std::string fio = "Max Maximov";
    Student student(id, fio);
    EXPECT_EQ("Max Maximov", student.getFIO());
}

TEST(test, test2) {
    int id = 5;
    std::string fio = "Max Maximov";
    Student student(id, fio);
    EXPECT_EQ(5, student.getID());
}

TEST(test, test3) {
    int id = 5;
    std::string fio = "Max Maximov";
    Student student(id, fio);
    student.addmark(5);
    student.addmark(3);
    EXPECT_EQ(4, int(student.getAveragemark()));
}

TEST(test, test4) {
    int id = 5;
    std::string fio = "Max Maximov";
    Student student(id, fio);
    EXPECT_EQ(5, student.getID());
}

TEST(test, test5) {
    int id = 5;
    std::string fio = "Max Maximov";
    Student student(id, fio);
    EXPECT_EQ(5, student.getID());
}

TEST(test, test6) {
    Group gr("title", "spec");
    EXPECT_EQ("title", gr.getTitle());
}

TEST(test, test7) {
    Group gr("title", "spec");
    EXPECT_EQ("spec", gr.getSpec());
}

TEST(test, test8) {
    Group gr("title", "spec");
    Student s1(1, "max");
    s1.addmark(3);
    s1.addmark(5);
    s1.addmark(5);
    Student s2(2, "ma2x");
    s2.addmark(4);
    s2.addmark(4);
    s2.addmark(4);
    gr.addStudent(&s1);
    gr.addStudent(&s2);
    gr.chooseHead(0);
    EXPECT_EQ("max", gr.getHead()->getFIO());
}

TEST(test, test9) {
    Group gr("title", "spec");
    Student s1(1, "max");
    s1.addmark(3);
    s1.addmark(5);
    s1.addmark(5);
    Student s2(2, "max2");
    s2.addmark(4);
    s2.addmark(4);
    s2.addmark(4);
    gr.addStudent(&s1);
    gr.addStudent(&s2);
    gr.chooseHead(1);
    EXPECT_EQ("max2", gr.getHead()->getFIO());
}

TEST(test, test10) {
    Group gr("title", "spec");
    Student s1(1, "max");
    s1.addmark(3);
    s1.addmark(5);
    s1.addmark(5);
    Student s2(2, "max2");
    s2.addmark(4);
    s2.addmark(4);
    s2.addmark(4);
    gr.addStudent(&s1);
    gr.addStudent(&s2);
    gr.chooseHead(1);
    EXPECT_EQ(41, int(gr.getAveragemark() * 10));
}
