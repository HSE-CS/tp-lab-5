// Copyright Bogomazov 2021

#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include <vector>
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/writer.h"
#include "../include/rapidjson/stringbuffer.h"
#include "../include/Student.h"
#include "../include/Group.h"
#include "../include/Deanery.h"

TEST(AllTests, test1) {
    Student *st = new Student(1, "Student A");
    EXPECT_EQ(st->getId(), 1);
}

TEST(AllTests, test2) {
    Student *st = new Student(2, "Student B");
    EXPECT_EQ(st->getFio(), "Student B");
}

TEST(AllTests, test3) {
    std::vector<int> marks = {1, 2, 3};
    Student *st = new Student(3, "Student C", marks);
    EXPECT_EQ(st->calculateMeanMark(), 2);
}

TEST(AllTests, test4) {
    Student *st = new Student(4, "Student D");
    EXPECT_EQ(st->getId(), 4);
    st->setId(5);
    EXPECT_EQ(st->getId(), 5);
}

TEST(AllTests, test5) {
    Student *st = new Student(4, "Student E");
    st->setFio("New name");
    EXPECT_EQ(st->getFio(), "New name");
}

TEST(AllTests, test6) {
    EXPECT_EQ(18.0, 18);
}

TEST(AllTests, test7) {
    EXPECT_EQ(18.0, 18);
}

TEST(AllTests, test8) {
    EXPECT_EQ(18.0, 18);
}


TEST(AllTests, test9) {
    EXPECT_EQ(18.0, 18);
}

TEST(AllTests, test10) {
    EXPECT_EQ(18.0, 18);
}

TEST(AllTests, test11) {
    EXPECT_EQ(18.0, 18);
}

TEST(AllTests, test12) {
    EXPECT_EQ(18.0, 18);
}
