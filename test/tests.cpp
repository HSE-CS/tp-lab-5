// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Student.h"
#include "Group.h"

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
    EXPECT_EQ(4, static_cast<int>(student.getAveragemark()));
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


TEST(test, test9) {
    Group gr("title1", "spec");
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
    EXPECT_EQ("title1", gr.getSpec());
}

TEST(test, test10) {
    Group gr("title", "spec1");
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
    EXPECT_EQ("spec1", gr.getSpec());
}
