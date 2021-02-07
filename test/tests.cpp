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
#include "../include/Deanary.h"

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
    Group *gr = new Group("19PMI-1", "Computer Science");
    EXPECT_EQ(gr->getTitle(), "19PMI-1");
    EXPECT_EQ(gr->getSpec(), "Computer Science");
}

TEST(AllTests, test7) {
    Group *gr = new Group("19PMI-1", "Computer Science");
    EXPECT_EQ(gr->isEmpty(), 1);
}

TEST(AllTests, test8) {
    Student *st = new Student(1, "Student A");
    Group *gr = new Group("19PMI-1", "Computer Science");
    gr->addStudentToGroup(st);
    std::string fio = "Student A";
    EXPECT_EQ(gr->findStudent(fio), st);
}

TEST(AllTests, test9) {
    Student *st = new Student(1, "Student A");
    Student *sf = new Student(2, "Student B");
    st->addMark(2);
    sf->addMark(10);
    Group *gr = new Group("19PMI-1", "Computer Science");
    gr->addStudentToGroup(st);
    gr->addStudentToGroup(sf);
    EXPECT_EQ(gr->calculateMeanMark(), 6);
}

TEST(AllTests, test10) {
    Deanery dn = Deanery();
    Student *st = new Student(1, "Student A");
    Student *sf = new Student(2, "Student B");
    st->addMark(2);
    sf->addMark(10);
    Group *gr = new Group("19PMI-1", "Computer Science");
    gr->addStudentToGroup(st);
    gr->addStudentToGroup(sf);
    std::vector<Group*> groups;
    groups.push_back(gr);
    dn.setGroups(groups);
    std::vector<float> stats = dn.getStatistics();
    EXPECT_EQ(stats[0], 6);
}

TEST(AllTests, test11) {
    Deanery dn = Deanery();
    std::vector<Group*> groups = dn.createGroupsFromFile("../src/input.json");
    EXPECT_EQ(groups[0]->getStudents()[0]->getFio(), "Marcia Herring");
}

