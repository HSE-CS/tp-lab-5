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
    Group group;
    Student student1("19E_3_00001", "Miles Smith", &group);
    Student student2("19E_3_00002", "Silvester Rogers", &group);
    Student student3("19E_3_00003", "Irma Wright", &group);
    group.addStudent(&student1);
    group.addStudent(&student2);
    group.addStudent(&student3);
    EXPECT_EQ("Silvester Rogers",
        group.getStudent("19E_3_00002")->getFio());
}

TEST(TestDeanary, Test5) {
    Group group;
    Student student1("19E_3_00001", "Miles Smith", &group);
    Student student2("19E_3_00002", "Silvester Rogers", &group);
    Student student3("19E_3_00003", "Irma Wright", &group);
    group.addStudent(&student1);
    group.addStudent(&student2);
    group.addStudent(&student3);
    EXPECT_EQ(false, group.containsStudent("20E_2_00220"));
}

TEST(TestDeanary, Test6) {
    Group group;
    Student student1("19E_3_00001", "Miles Smith", &group);
    Student student2("19E_3_00002", "Silvester Rogers", &group);
    Student student3("19E_3_00003", "Irma Wright", &group);
    group.addStudent(&student1);
    group.addStudent(&student2);
    group.addStudent(&student3);
    EXPECT_EQ(true, group.containsStudent("Miles Smith"));
}

TEST(TestDeanary, Test7) {
    Group group;
    Student student1("19E_3_00001", "Miles Smith", &group);
    Student student2("19E_3_00002", "Silvester Rogers", &group);
    Student student3("19E_3_00003", "Irma Wright", &group);
    group.addStudent(&student1);
    group.addStudent(&student2);
    group.addStudent(&student3);
    group.removeStudent("19E_3_00003");
    EXPECT_EQ(false, group.containsStudent("Irma Wright"));
}

TEST(TestDeanary, Test8) {
    Group group("18E_2", "Economy");
    EXPECT_EQ("18E_2", group.getTitle());
}

TEST(TestDeanary, Test9) {
    Group group;
    Student student1("19E_3_00001", "Miles Smith", &group);
    Student student2("19E_3_00002", "Silvester Rogers", &group);
    Student student3("19E_3_00003", "Irma Wright", &group);
    group.addStudent(&student1);
    group.addStudent(&student2);
    group.addStudent(&student3);
    EXPECT_EQ(false, student2.isHeadOfGroup());
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
