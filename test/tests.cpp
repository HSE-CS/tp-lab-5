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
