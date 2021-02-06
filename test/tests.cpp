// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "../include/Student.h"
#include "../include/Group.h"
#include "../include/Deanary.h"


TEST(Deanary, test1) {
    Student st("00000", "Donald Trump");
    EXPECT_EQ("William Garcia", st.getFIO());
}

TEST(Deanary, test2) {
    Student st("00000", "Donald Trump");
    EXPECT_EQ("00000", st.getId());
}

TEST(Deanary, test3) {
    Student st("00000", "Donald Trump");
    st.addMark(5);
    EXPECT_EQ(5.0, st.getAverageMark());
}

TEST(Deanary, test4) {
    Student st("00000", "Donald Trump");
    Group gr("PI", "hardware engineering");
    st.addToGroup(&gr);
    gr.getStudents()[0]->addMark(5);
    EXPECT_EQ(5.0, gr.getStudents()[0]->getAverageMark());
}

TEST(Deanary, test5) {
    Student st("00000", "Donald Trump");
    Group gr("PI", "hardware engineering");
    gr.addStudent(&st);
    gr.chooseHead(&st);
    EXPECT_EQ("00000", gr.getHead()->getId());
}

TEST(Deanary, test6) {
    Student st("00000", "Donald Trump");
    Group gr("PI", "hardware engineering");
    gr.addStudent(&st);
    EXPECT_EQ(true, gr.containsStudent(&st));
}

TEST(Deanary, test7) {
    Group gr("PI", "hardware engineering");
    Student st("00000", "Donald Trump");
    gr.addStudent(&st);
    EXPECT_EQ(false, gr.isEmpty());
}

TEST(Deanary, test8) {
    Group gr("PI", "hardware engineering");
    Student st("00000", "Donald Trump");
    gr.addStudent(&st);
    gr.removeStudent(&st);
    EXPECT_EQ(true, gr.isEmpty());
}

TEST(Deanary, test9) {
    Student st("00000", "Donald Trump");
    st.setFIO("Donald Mcduck");
    EXPECT_EQ("Donald Mcduck", st.getFIO());
}

TEST(Deanary, test10) {
    Group gr("PI", "hardware engineering");
    Student st("00000", "Donald Trump");
    gr.addStudent(&st);
    EXPECT_EQ("hardware engineering", st.getGr()->getSpec());
}
