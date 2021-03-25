// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>

#include "Student.h"
#include "Group.h"

TEST(test, test1) {
    int id = 5;
    std::string fio = "Max Maximov";
    Student student(id, fio);
    EXPECT_EQ("Max Maximov", student.getFIO());
}

TEST(test, test2) {
    int id = 5;
    std::string fio = "Max Maximov";
    Student student(id, fio);
    EXPECT_EQ(5, student.getID());
}

