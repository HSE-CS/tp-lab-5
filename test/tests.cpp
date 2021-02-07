// Copyright 2021 Nikolaev Ivan
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"


TEST(Deanary, test1) {
    std::vector<int> vec = { 5, 5, 5, 5 };
    Student stud1(1, "Nikolaev I A", vec);
    EXPECT_EQ(5, stud1.getAveragemark());
}

TEST(Deanary, test2) {
    std::vector<int> vec = { 5, 5, 5, 5 };
    Student stud1(1, "Nikolaev I A", vec);
    EXPECT_EQ(1, stud1.getId());
}

TEST(Deanary, test3) {
    std::vector<int> vec = { 5, 5, 5, 5 };
    Student stud1(1, "Nikolaev I A", vec);
    EXPECT_EQ("Nikolaev I A", stud1.getFio());
}

TEST(Deanary, test4) {
    std::vector<int> vec = { 5, 5, 5, 5 };
    Student stud1(1, "Nikolaev I A", vec);
    Deanary deanary;
    deanary.createGroups("19PI2", "SE");
    EXPECT_EQ(false, deanary.findGroup("19PI2")->containsStudent("Nikolaev I A"));
}

TEST(Deanary, test5) {
    std::vector<int> vec = { 5, 5, 5, 5 };
    Student stud1(1, "Nikolaev I A", vec);
    Deanary deanary;
    deanary.createGroups("19PI2", "SE");
    EXPECT_EQ(false, deanary.findGroup("19PI2")->containsStudent("Abcdefdh"));
}

TEST(Deanary, test6) {
    std::vector<int> vec = { 5, 5, 5, 5 };
    Student stud1(1, "Nikolaev I A", vec);
    Deanary deanary;
    deanary.createGroups("19PI2", "SE");
    EXPECT_EQ(true, deanary.findGroup("19PI2")->isEmpty());
}

TEST(Deanary, test7) {
    std::vector<int> vec = { 5, 5, 5, 5 };
    Student stud1(1, "Nikolaev I A", vec);
    Deanary deanary;
    deanary.createGroups("19PI2", "SE");
    deanary.hireStudents("19PI2", stud1);
    EXPECT_EQ(true, deanary.findGroup("19PI2")->containsStudent("Nikolaev I A"));
}

TEST(Deanary, test8) {
    std::vector<int> vec = { 5, 5, 5, 5 };
    Student stud1(1, "Nikolaev I A", vec);
    Deanary deanary;
    deanary.createGroups("19PI2", "SE");
    deanary.hireStudents("19PI2", stud1);
    EXPECT_EQ(false, deanary.findGroup("19PI2")->containsStudent("Abcdefd"));
}

TEST(Deanary, test9) {
    std::vector<int> vec = { 5, 5, 5, 5 };
    Student stud1(1, "Nikolaev I A", vec);
    Deanary deanary;
    deanary.createGroups("19PI2", "SE");
    deanary.hireStudents("19PI2", stud1);
    EXPECT_EQ(false, deanary.findGroup("19PI2")->isEmpty());
}

TEST(Deanary, test10) {
    std::vector<int> vec = { 5, 5, 5, 5 };
    Student stud1(1, "Nikolaev I A", vec);
    Deanary deanary;
    deanary.createGroups("19PI2", "SE");
    deanary.hireStudents("19PI2", stud1);
    EXPECT_EQ(5, deanary.findGroup("19PI2")->getAveragemark());
}

TEST(Deanary, test11) {
    std::vector<int> vec = { 5, 5, 5, 5 };
    Student stud1(1, "Nikolaev I A", vec);
    Deanary deanary;
    deanary.createGroups("19PI2", "SE");
    deanary.hireStudents("19PI2", stud1);
    deanary.initHeads();
    EXPECT_EQ(true, deanary.findGroup("19PI2")->getStudent("Nikolaev I A")->isHeadOfGroup());
}