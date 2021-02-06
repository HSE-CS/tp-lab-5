// Copyright 2020 Khoroshavina Ekaterina
#include "Student.h"
#include "Group.h"
#include "Deanary.h"

#include <gtest/gtest.h>
#include <string>

TEST(DeanaryTest, Test1) {
    Group group("19SE-1", "SE");
    EXPECT_EQ("19SE-1", group.getTitle());
}

TEST(DeanaryTest, Test2) {
    Student student(1, "Ivanov Ivan Sergeevich");
    EXPECT_EQ(1, student.getId());
}

TEST(DeanaryTest, Test3) {
    Student student(1, "Ivanov Ivan Sergeevich");
    EXPECT_EQ("Ivanov Ivan Sergeevich", student.getFIO());
}

TEST(DeanaryTest, Test4) {
    Group group("19SE-1", "SE");
    Student student(1, "Ivanov Ivan Sergeevich");
    student.addToGroup(&group);
    EXPECT_EQ("Ivanov Ivan Sergeevich", group.getStudent(1)->getFIO());
}

TEST(DeanaryTest, Test5) {
    Group group("19SE-1", "SE");
    Student student(1, "Ivanov Ivan Sergeevich");
    student.addToGroup(&group);
    EXPECT_EQ(0, group.containsStudent(2));
}

TEST(DeanaryTest, Test6) {
    Group group("19SE-1", "SE");
    Student student(1, "Ivanov Ivan Sergeevich");
    student.addToGroup(&group);
    EXPECT_EQ(1, group.containsStudent(1));
}

TEST(DeanaryTest, Test7) {
    Student student(1, "Ivanov Ivan Sergeevich");
    student.addMark(10);
    student.addMark(9);
    EXPECT_EQ(9.5, student.getAverageMark());
}

TEST(DeanaryTest, Test8) {
    Group group("19SE-1", "SE");
    Student student(1, "Ivanov Ivan Sergeevich");
    student.addToGroup(&group);
    Deanary deanary;
    deanary.addGroup(&group);
    EXPECT_EQ("19SE-1", deanary.getGroups()[0]->getTitle());
}

TEST(DeanaryTest, Test9) {
    Group group("19SE-1", "SE");
    Student student(1, "Ivanov Ivan Sergeevich");
    student.addToGroup(&group);
    Deanary deanary;
    deanary.addGroup(&group);
    deanary.addMarksToAll(10);
    deanary.addMarksToAll(9);
    deanary.addMarksToAll(8);
    EXPECT_EQ(9, group.getStudent(1)->getAverageMark());
}

TEST(DeanaryTest, Test10) {
    Group group("19SE-1", "SE");
    Student student(1, "Ivanov Ivan Sergeevich");
    student.addToGroup(&group);
    Deanary deanary;
    deanary.addGroup(&group);
    deanary.initHeads();
    EXPECT_EQ(1, group.getStudent(1)->isHeadOfGroup());
}
