// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>

#include "Student.h"
#include "Group.h"

TEST(StudentTest, averageMarkTest) {
    Student st(1, "Test name");
    st.addMark(4);
    EXPECT_EQ(st.getAverageMark(), 4);
    st.addMark(3);
    EXPECT_EQ(st.getAverageMark(), 3.5);
    st.addMark(5);
    EXPECT_EQ(st.getAverageMark(), 4);
    st.addMark(3);
    EXPECT_EQ(st.getAverageMark(), 3.75);
}

TEST(GroupTest, isInitiallyEmpty) {
    Group g("Test group");
    EXPECT_TRUE(g.isEmpty);
}

TEST(InteractionTest, testAddStudent) {
    auto s = new Student(1, "Test name");
    Group g("Test group");
    EXPECT_FALSE(g.containsStudent(1));
    g.addStudent(s);
    EXPECT_TRUE(g.containsStudent(1));
}

TEST(InteractionTest, testSetHead) {
    auto s = new Student(1, "Test name");
    Group g("Test group");
    g.addStudent(s);
    g.chooseHead(1);
    EXPECT_TRUE(g.containsStudent(1));
    EXPECT_TRUE(s->isHeadOfGroup());
}

TEST(InteractionTest, testGroupAverage) {
    auto s1 = new Student(1, "Test name");
    s1.addMark(4);
    s1.addMark(3);
    s1.addMark(5);
    s1.addMark(3);
    auto s2 = new Student(2, "Another name");
    s2.addMark(2);
    s2.addMark(5);
    s2.addMark(4);
    s2.addMark(3);
    s2.addMark(4);
    Group g("Test group");
    g.addStudent(s1);
    g.addStudent(s2);
    EXPECT_EQ(g.getAverageMark(), 33/9.0);
}
