// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "../include/Student.h"
#include "../include/Deanary.h"

TEST(Student, test1) {
    Student student(1123, "Максимов Максим Максимович");
    EXPECT_EQ(1123, student.getId());
}

TEST(Student, test2) {
    Student student(1123, "Максимов Максим Максимович");
    EXPECT_EQ("Максимов Максим Максимович", student.getFio());
}

TEST(Student, test3) {
    Student student(1123, "Максимов Максим Максимович");
    EXPECT_EQ(0, student.getAverageMark());
}

TEST(Deanary, test1) {
    Deanary deanary;
    deanary.addGroup("19PI", "SE");
    EXPECT_EQ(1, deanary.getGroup("19PI")->isEmpty());
}

TEST(Deanary, test2) {
    Deanary deanary;
    deanary.addGroup("19PI", "SE");
    deanary.addStudent("Максимов Максим Максимович", "19PI");
    EXPECT_EQ(0, deanary.getGroup("19PI")->isEmpty());
}

TEST(Deanary, test3) {
    Deanary deanary;
    deanary.addGroup("19PI", "SE");
    deanary.addStudent("Максимов Максим Максимович", "19PI");
    EXPECT_EQ(0, deanary.getGroup("19PI")->getAverageMark());
}

TEST(Deanary, test4) {
    Deanary deanary;
    deanary.addGroup("19PI", "SE");
    deanary.addGroup("18PI", "SE");
    deanary.addStudent("Максимов Максим Максимович", "19PI");
    deanary.moveStudent("Максимов Максим Максимович", "19PI", "18PI");
    EXPECT_EQ(0, deanary.getGroup("19PI")
    ->containsStudent("Максимов Максим Максимович"));
    EXPECT_EQ(1, deanary.getGroup("18PI")
    ->containsStudent("Максимов Максим Максимович"));
}

TEST(Deanary, test5) {
    Deanary deanary;
    deanary.addGroup("19PI", "SE");
    deanary.addGroup("18PI", "SE");
    deanary.addStudent("Максимов Максим Максимович", "19PI");
    deanary.addStudent("Бычков Илья Сергеевич", "18PI");
    deanary.initHeads();
    EXPECT_EQ(1, deanary.getGroup("19PI")
    ->getStudent("Максимов Максим Максимович")->isHeadOfGroup());
    EXPECT_EQ(1, deanary.getGroup("18PI")
    ->getStudent("Бычков Илья Сергеевич")->isHeadOfGroup());
}

TEST(Deanary, test6) {
    Deanary deanary;
    deanary.addGroup("19PI", "SE");
    deanary.addGroup("18PI", "SE");
    deanary.addStudent("Максимов Максим Максимович", "19PI");
    deanary.addStudent("Бычков Илья Сергеевич", "18PI");
    deanary.initHeads();
    deanary.fireStudents();
    EXPECT_EQ(1, deanary.getGroup("19PI")->isEmpty());
    EXPECT_EQ(1, deanary.getGroup("18PI")->isEmpty());
}

TEST(Deanary, test7) {
    Deanary deanary;
    deanary.addGroup("19PI", "SE");
    deanary.addGroup("18PI", "SE");
    deanary.addStudent("Максимов Максим Максимович", "19PI");
    deanary.addStudent("Бычков Илья Сергеевич", "18PI");
    deanary.initHeads();
    deanary.addMarksToAll();
    deanary.fireStudents();
    EXPECT_EQ(0, deanary.getGroup("19PI")->isEmpty());
    EXPECT_EQ(0, deanary.getGroup("18PI")->isEmpty());
}
