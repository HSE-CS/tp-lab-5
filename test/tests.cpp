// Copyright 2021 GHA Test Team

#include "gtest/gtest.h"

#include "Student.h"
#include "Group.h"
#include "Deanary.h"

TEST(TestDeanary, Test1) {
    Group group("18E_2", "Economy");
    Student student("345", "Ivan Ivanov", &group);
    int marks[9] = { 6, 6, 8, 9, 6, 7, 6, 7, 8 };
    for (int mark : marks) {
        student.addmark(mark);
    }
    EXPECT_EQ(7, student.getAveragemark());
}

TEST(TestDeanary, Test2) {
    Group group("18E_2", "Economy");
    Student student("345", "Ivan Ivanov", &group);
    EXPECT_EQ("Ivan Ivanov", student.getFio());
}

TEST(TestDeanary, Test3) {
    Group group("18E_2", "Economy");
    EXPECT_TRUE(group.isEmpty());
}

TEST(TestDeanary, Test4) {
    Deanary groups;
    groups.createGroup();
    groups.hireStudents();
    groups.addMarksToAll();
    groups.initHeads();
    EXPECT_EQ("Silvester Rogers",
        groups.getgroups()[1]->getStudent("19E_3_00002")->getFio());
}

TEST(TestDeanary, Test5) {
    Deanary groups;
    groups.createGroup();
    groups.hireStudents();
    groups.addMarksToAll();
    groups.initHeads();
    EXPECT_EQ(false, groups.getgroups()[1]->containsStudent("20E_2_00220"));
}

TEST(TestDeanary, Test6) {
    Deanary groups;
    groups.createGroup();
    groups.hireStudents();
    groups.addMarksToAll();
    groups.initHeads();
    EXPECT_EQ(true,
        groups.getgroups()[3]->containsStudent("Elvin Gibson"));
}

TEST(TestDeanary, Test7) {
    groups.createGroup();
    groups.hireStudents();
    groups.addMarksToAll();
    groups.initHeads();
    groups.getgroups()[2]->removeStudent("19E_3_00003");
    EXPECT_EQ(false,
        groups.getgroups()[3]->containsStudent("Irma Wright"));
}

TEST(TestDeanary, Test8) {
    Deanary groups;
    groups.createGroup();
    groups.hireStudents();
    groups.addMarksToAll();
    groups.initHeads();
    EXPECT_EQ("19E_3", groups.getgroups()[3]->getTitle());
}

TEST(TestDeanary, Test9) {
    Deanary groups;
    groups.createGroup();
    groups.hireStudents();
    groups.addMarksToAll();
    groups.initHeads();
    groups.getStatistics();
    Student student("345", "Ivan Ivanov", groups.getgroups()[0]);
    groups.getgroups()[0]->addStudent(&student);
    EXPECT_EQ(false, student.isHeadOfGroup());
}

TEST(TestDeanary, Test10) {
    Group group("18E_2", "Economy");
    Student student("345", "Ivan Ivanov", &group);
    int marks[10] = { 4, 6, 5, 7, 6, 5, 4, 6, 3, 4 };
    for (int mark : marks) {
        student.addmark(mark);
    }
    EXPECT_EQ(5, student.getAveragemark());
}
