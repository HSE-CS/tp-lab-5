// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>

#include "../include/Deanary.h"
#include "../include/Group.h"
#include "../include/Student.h"

TEST(StudentTest, test1) {
    Student student(2311, "Alex B.B.");
    EXPECT_EQ(2311, student.getId());
}

TEST(StudentTest, test2) {
    Student student(2311, "Alex B.B.");
    EXPECT_EQ("Alex B.B.", student.getName());
}

TEST(StudentTest, test3) {
    Student student(2311, "Alex B.B.");
    student.setId(3212);
    EXPECT_EQ(3212, student.getId());
}

TEST(StudentTest, test4) {
    Student student(2311, "Alex B.B.");
    student.setName("Alex A.E.")
    EXPECT_EQ("Alex A.E.", student.getName());
}

TEST(StudentTest, test5) {
    Student student(2311, "Alex B.B.");
    student.addMark(10);
    student.addMark(9);
    student.addMark(5);
    student.addMark(8);
    EXPECT_EQ(8, student.getMidMark());
}





