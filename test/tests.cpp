// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include "Deanary.h"
#include <string>

TEST(Student_Test, test1) {
Student student1 = Student("Алексей Алексеев");
EXPECT_EQ(1, student1.getId());
}

TEST(Student_Test, test2) {
Student student1 = Student("Игорь Тюлин");
Student student2 = Student("Кто-то какой-то");
EXPECT_EQ("Кто-то какой-то", student2.getFio());
}

TEST(Student_Test, test3) {
Student student1("Ivan Ivanov");
EXPECT_EQ("Ivan Ivanov", student1.getFio());
}

TEST(Student_Test, test4) {
Student student1 = Student("Shrek 2");
student1.addMark(1);
student1.addMark(2);
double res = 1.5;
EXPECT_EQ(res, student1.getMiddleMark());
}

TEST(Student_Test, test5) {
Student student1("Sasha Grey");
student1.addMark(9);
student1.addMark(8);
student1.addMark(7);
student1.addMark(6);
student1.addMark(5);
student1.addMark(4);
student1.addMark(3);
student1.addMark(2);
double res = 5.5;
EXPECT_EQ(res, student1.getMiddleMark());
}

TEST(Group_Test, test6) {
Group group1("19PI", "2");
EXPECT_EQ("19PI 2", group1.getGroupName());
}

TEST(Group_Test, test7) {
Group group1 = Group("QWE", "7");
Student student1 = Student("qwe");
student1.addMark(5);
Student student2 = Student("qwe");
student2.addMark(3);
group1.addStudent(student1);
group1.addStudent(student2);
double res = 4;
EXPECT_EQ(res, group1.groupMiddleMark());
}

TEST(Group_Test, test8) {
Group group1 = Group("qwe", "124");
Student student = Student("Igor 228 322");
group1.addStudent(student);
EXPECT_EQ(9, group1.search_student("Igor 228 322").getId());
}

TEST(Group_Test, test9) {
Student student = Student("Kek");
student.addMark(10);
Student student2 = Student("Pek");
student2.addMark(5);
Group group = Group("hse", "000");
group.addStudent(student);
group.addStudent(student2);
double res = 7.5;
EXPECT_EQ(res, group.groupMiddleMark());
}



