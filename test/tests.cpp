// Copyright [2020] <Olesya Nikolaeva>

#include <gtest/gtest.h>
#include <string>

#include "Student.h"
#include "Deanary.h"
#include "Group.h"

TEST(Test, test1) {
    Student A("002", "Pavlov I. V.");
    A.addMark(10);
    A.addMark(9);
    EXPECT_EQ(A.averageMark(), 10);
}

TEST(Test, test2) {
    Deanary newDea;
    Student A("002", "Pavlov I. V.");
    newDea.addGroup(new Group("19SE", "Software Engineering"));
    A.groupIs(newDea.findGroup("19SE"));
    EXPECT_EQ(A.getGroup(), "19SE");
}

TEST(Test, test3) {
    Deanary newDea;
    Student A("002", "Pavlov I. V.");
    newDea.addGroup(new Group("19SE", "Software Engineering"));
    A.groupIs(newDea.findGroup("19SE"));
    newDea.addGroup(new Group("20SE", "Software Engineering"));
    EXPECT_EQ(newDea.getStudentsNumber("19SE"), 1);
}

TEST(Test, test4) {
    Deanary newDea;
    Student A("002", "Pavlov I. V.");
    newDea.addGroup(new Group("19SE", "Software Engineering"));
    A.groupIs(newDea.findGroup("19SE"));
    newDea.addGroup(new Group("20SE", "Software Engineering"));
    newDea.moveStudents(&A, "20SE");
    EXPECT_EQ(newDea.getStudentsNumber("19SE"), 0);
}

TEST(Test, test5) {
    Deanary newDea;
    Student A("002", "Pavlov I. V.");
    Student B("001", "Kotova A. G.");
    newDea.addGroup(new Group("19SE", "Software Engineering"));
    A.groupIs(newDea.findGroup("19SE"));
    newDea.addGroup(new Group("20SE", "Software Engineering"));
    newDea.moveStudents(&A, "20SE");
    B.groupIs(newDea.findGroup("20SE"));
    EXPECT_EQ(newDea.getStudentsNumber("20SE"), 2);
}

TEST(Test, test6) {
    Deanary newDea;
    Student A("002", "Pavlov I. V.");
    Student B("001", "Kotova A. G.");
    newDea.addGroup(new Group("19SE", "Software Engineering"));
    A.groupIs(newDea.findGroup("19SE"));
    newDea.addGroup(new Group("20SE", "Software Engineering"));
    newDea.moveStudents(&A, "20SE");
    B.groupIs(newDea.findGroup("20SE"));
    newDea.fireStudents(newDea.findStudent("Pavlov I. V."));
    EXPECT_EQ(newDea.getStudentsNumber("20SE"), 1);
}

TEST(Test, test7) {
    Deanary newDea;
    Student A("002", "Pavlov I. V.");
    newDea.addGroup(new Group("19SE", "Software Engineering"));
    A.groupIs(newDea.findGroup("19SE"));
    EXPECT_EQ(newDea.findStudent("Pavlov I. V."), &A);
}

TEST(Test, test8) {
    Deanary newDea;
    Student A("002", "Pavlov I. V.");
    newDea.addGroup(new Group("19SE", "Software Engineering"));
    A.groupIs(newDea.findGroup("19SE"));
    newDea.addGroup(new Group("20SE", "Software Engineering"));
    newDea.moveStudents(&A, "20SE");
    EXPECT_EQ(A.getGroup(), "20SE");
}

TEST(Test, test9) {
    Deanary newDea;
    Student A("002", "Pavlov I. V.");
    newDea.addGroup(new Group("19SE", "Software Engineering"));
    A.groupIs(newDea.findGroup("19SE"));
    A.addMark(8);
    EXPECT_EQ(A.averageMark(), 8);
}

TEST(Test, test10) {
    Group SE("20SE", "SE");
    Student A("002", "Pavlov I. V.");
    SE.addStudent(&A);
    EXPECT_EQ(A.getGroup(), "20SE");
}
