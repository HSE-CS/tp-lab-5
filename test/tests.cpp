// Copyright 7.02.2021 Golovanov

#include <gtest/gtest.h>
#include <string>
#include "../include/Student.h"
#include "../include/Group.h"
#include "../include/Deanary.h"

TEST(PostfixTest, test1) {
    Student student("1", "Golovanov Denis Maximovich");
    std::string id = student.getId();
    EXPECT_EQ("1", id);
}

TEST(PostfixTest, test2) {
    Student student("1", "Golovanov Denis Maximovich");
    std::string fio = student.getFio();
    EXPECT_EQ("Golovanov Denis Maximovich", fio);
}


TEST(PostfixTest, test3) {
    Student student("1", "Golovanov Denis Maximovich");
    Group group1("19PMI-1", "PMI");
    student.addToGroup(&group1);
    EXPECT_EQ("19PMI-1", student.getGroup()->GetTitle());
}

TEST(PostfixTest, test4) {
    Student student("1", "Golovanov Denis Maximovich");
    Group group1("19PMI-1", "PMI");
    student.addToGroup(&group1);
    EXPECT_EQ("Golovanov Denis Maximovich", group1.getStudents()[0]->getFio());
}

TEST(PostfixTest, test5) {
    Student student("1", "Golovanov Denis Maximovich");
    Group group1("19PMI-1", "PMI");
    group1.addStudent(&student);
    EXPECT_EQ("19PMI-1", student.getGroup()->GetTitle());
}

TEST(PostfixTest, test6) {
    Student student("1", "Golovanov Denis Maximovich");
    Group group1("19PMI-1", "PMI");
    group1.addStudent(&student);
    EXPECT_EQ("Golovanov Denis Maximovich", group1.getStudents()[0]->getFio());
}

TEST(PostfixTest, test7) {
    Student student("1", "Golovanov Denis Maximovich");
    student.addMark(10);
    EXPECT_EQ(10, student.getMarks()[0]);
}

TEST(PostfixTest, test8) {
    Student student("1", "Golovanov Denis Maximovich");
    Group group1("19PMI-1", "PMI");
    group1.addStudent(&student);
    group1.chooseHead(&student);
    EXPECT_EQ("Golovanov Denis Maximovich", group1.getHead()->getFio());
}

TEST(PostfixTest, test9) {
    Student student("1", "Golovanov Denis Maximovich");
    student.addMark(10);
    EXPECT_EQ(10, student.calculateAverageMark());
}

TEST(PostfixTest, test10) {
    Student student("1", "Golovanov Denis Maximovich");
    student.addMark(10);
    student.addMark(9);
    EXPECT_EQ(9.5, student.calculateAverageMark());
}
