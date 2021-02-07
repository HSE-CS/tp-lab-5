// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Group.h"

TEST(testStudent, getFIO) {
    Student student(0, "Richard Hall");
    EXPECT_EQ("Richard Hall", student.getFIO());
}

TEST(testStudent, getID) {
    Student student(0, "Richard Hall");
    EXPECT_EQ(0, student.getID());
}

TEST(testStudent, addMark) {
    Student student(0, "Richard Hall");
    student.addmark(4);
    EXPECT_EQ(4, student.calcAv());
}

TEST(testStudent, addToGroup) {
    Student student(0, "Richard Hall");
    Group* group = new Group("group1", "group5");
    student.addToGroup(group);
    EXPECT_EQ(group, student.getGroup());
}

TEST(testGroup, getTitle) {
    Student* student = new Student(0, "Richard Hall");
    Group* group = new Group("group1", "group5");
    student->addToGroup(group);
    EXPECT_EQ("group1", group->getTitle());
}

TEST(testGroup, addStudent) {
    Student* student = new Student(0, "Richard Hall");
    Group* group = new Group("group1", "group5");
    student->addToGroup(group);
    group->addStudent(student);
    EXPECT_EQ("Richard Hall", group->getStudent()[0]->getFIO());
}
