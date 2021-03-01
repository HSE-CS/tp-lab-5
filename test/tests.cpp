// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include "Deanery.h"
#include <string>

TEST(Student_Test, test1) {
    Student student = Student(0, "");
    EXPECT_EQ(0, student.getId());
}

TEST(Student_Test, test2) {
    Student student = Student(0, "abcd");
    EXPECT_EQ("abcd", student.getFio());
}

TEST(Student_Test, test3) {
    Student student = Student(0, "abcd");
    Group group = Group("test");
    student.AddGroup(&group);
    EXPECT_EQ("test", student.getGroup()->getTitle());
}

TEST(Student_Test, test4) {
    Student student = Student(0, "abcd");
    student.AddMark(5);
    EXPECT_EQ(5, student.getMarks().back());
}

TEST(Student_Test, test5) {
    Student student = Student(0, "abcd");
    student.AddMark(10);
    student.AddMark(5);
    EXPECT_DOUBLE_EQ(7.5, student.CalcAverageMark());
}

TEST(Student_Test, test6) {
    Student student = Student(0, "abcd");
    student.AddMark(5);
    EXPECT_EQ(5, student.getMarks().back());
}

TEST(Group_Test, test1) {
    Group group = Group("Test");
    EXPECT_EQ("Test", group.getTitle());
}

TEST(Group_Test, test2) {
    Group group = Group("Test");
    Student student = Student(0, "abcd");
    group.AddStudent(student);
    EXPECT_EQ("abcd", group.getStudents()->back().getFio());
}

TEST(Group_Test, test3) {
    Group group = Group("Test");
    Student student = Student(0, "abcd");
    group.AddStudent(student);
    EXPECT_EQ("abcd", group.FindStudent(0)->getFio());
}

TEST(Group_Test, test4) {
    Group group = Group("Test");
    Student student = Student(0, "abcd");
    group.AddStudent(student);
    EXPECT_EQ(0, group.FindStudent("abcd")->getId());
}

TEST(Group_Test, test5) {
    Group group = Group("Test");
    Student student1 = Student(0, "abcd");
    student1.AddMark(5);
    Student student2 = Student(1, "efgh");
    student2.AddMark(10);
    group.AddStudent(student1);
    group.AddStudent(student2);
    EXPECT_DOUBLE_EQ(7.5, group.CalcAverageMarkInGroup());
}

TEST(Group_Test, test6) {
    Group group = Group("Test");
    Student student1 = Student(0, "abcd");
    student1.AddMark(5);
    Student student2 = Student(1, "efgh");
    student2.AddMark(10);
    group.AddStudent(student1);
    group.AddStudent(student2);
    group.KickStudent(&student2);
    EXPECT_DOUBLE_EQ(5, group.CalcAverageMarkInGroup());
}
