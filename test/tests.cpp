// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "../include/Deanary.h"

TEST(Student, test1) {
Student student(1123, "Максимов Максим Максимович");
EXPECT_EQ(1123, student.GetId());
}

TEST(Student, test2) {
Student student(1123, "Максимов Максим Максимович");
EXPECT_EQ("Максимов Максим Максимович", student.GetFio());
}

TEST(Student, test3) {
Student student(1123, "Максимов Максим Максимович");
EXPECT_EQ(0, student.CountAvgMark());
}

TEST(Deanary, test4) {
Deanary deanary;
deanary.CreateGroup("123","123");
deanary.CreateStudent(1,"1 2 3", deanary.GroupByTitle("123"));
EXPECT_EQ(0, deanary.GroupByTitle("19PI")->IsEmpty());
}

TEST(Deanary, test5) {
Deanary deanary;
deanary.CreateGroup("123","123");
deanary.CreateStudent(1,"1 2 3", deanary.GroupByTitle("123"));
EXPECT_EQ(0, deanary.GroupByTitle("123")->CountAvgMark());
}