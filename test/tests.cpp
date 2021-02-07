// Copyright 2021 Kartseva Masha
#include <gtest/gtest.h>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"
TEST(lab5, task1)
{
    Student* st = new Student("Ivanov Petr", 1);
    st->addMark(7);
    st->addMark(5);
    st->addMark(3);
    unsigned int res = st->AverageMark();
    EXPECT_EQ(5.0, res);
}

TEST(lab5, task2)
{
    Student* st = new Student("Ivanov Petr", 1);
    Group* gr = new Group("19FM-1", "Fund Maths");
    st->setGroup(gr);
    EXPECT_EQ("19FM-1", st->getGroup());
}

TEST(lab5, task3)
{
    Student* st1 = new Student("Ivanov Petr", 1);
    Student* st2 = new Student("Petrov Ivan", 2);
    st1->addMark(5);
    st1->addMark(7);
    st2->addMark(3);
    st2->addMark(5);
    Group* gr = new Group("19FM-1", "Fund Maths");
    gr->addStudent(st1);
    gr->addStudent(st2);
    EXPECT_EQ(5, gr->AverageMarkofGroup());
    EXPECT_EQ(2, gr->getStudents().size());
}

TEST(lab5, task4)
{
    Student* st1 = new Student("Ivanov Petr", 1);
    Student* st2 = new Student("Petrov Ivan", 2);
    Group* gr1 = new Group("19FM-1", "Fund Maths");
    Group* gr2 = new Group("20SE-1", "Software Eng");
    gr1->addStudent(st1);
    gr2->addStudent(st2);
    gr1->chooseHead();
    gr2->chooseHead();
    EXPECT_EQ("Ivanov Petr", gr1->getHeadName());
    EXPECT_EQ("Petrov Ivan", gr2->getHeadName());
}


