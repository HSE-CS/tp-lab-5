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
    student.setName("Alex A.E.");
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

TEST(GroupTest, test6) {
    Group group("19PI", "PI");
    EXPECT_EQ("19PI", group.getTitle());
}

TEST(GroupTest, test7) {
    Group group("19PI", "PI");
    EXPECT_EQ("PI", group.getSpec());
}

TEST(GroupTest, test8) {
    Student a(2312, "Grachev A.E.");
    Student b(1111, "Ivanov I.I.");
    Group group("19PI", "PI");
    group.addStudent(a);
    group.addStudent(b);
    group.chooseLeader(a);
    EXPECT_EQ("Grachev Alexander", group.getLeader());
}

//std::cout << gA.searchStudent(1111).getName() << std::endl;
//std::cout << gA.searchStudent("Ivanov I.I.").getId() << std::endl;

TEST(GroupTest, test9) {
    Student a(2312, "Grachev A.E.");
    Student b(1111, "Ivanov I.I.");
    Group group("19PI", "PI");
    group.addStudent(a);
    group.addStudent(b);
    EXPECT_EQ("Ivanov I.I.", group.searchStudent(1111));
}

TEST(GroupTest, test10) {
    Student a(2312, "Grachev A.E.");
    Student b(1111, "Ivanov I.I.");
    Group group("19PI", "PI");
    group.addStudent(a);
    group.addStudent(b);
    EXPECT_EQ("Grachev A.E.", group.searchStudent(2312));
}

TEST(GroupTest, test11) {
    Student a(2312, "Grachev A.E.");
    Student b(1111, "Ivanov I.I.");
    Group group("19PI", "PI");
    group.addStudent(a);
    group.addStudent(b);
    EXPECT_EQ(1111, group.searchStudent("Ivanov I.I."));
}





