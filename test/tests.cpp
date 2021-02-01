// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <cstring>

#include "Student.h"
#include "Group.h"
#include "Deanary.h"

TEST(Student, test1) {
    Student *student = new Student(Student::getLastId(), "LolL");
    EXPECT_EQ(0, student->getId());
}

TEST(Student, test2) {
    Student *student = new Student("QwertyP");
    EXPECT_EQ(0, std::strcmp("QwertyP", student->getFio().c_str()));
}

TEST(Student, test3) {
    Group *group = new Group("PI");
    Student *student = new Student("Vargin");
    group->addStudent(student);
    EXPECT_EQ(0, std::strcmp("PI",
                 student->getGroup()->getTitle().c_str()));
}

TEST(Group, test4) {
    Group *group = new Group("PI");
    Student *student1 = new Student("Qwery");
    Student *student2 = new Student("Rewq");
    group->addStudent(student1);
    group->addStudent(student2);

}

TEST(Student, test5) {
    Student *student = new Student("Kamri3.5");
    student->addMark(6);
    student->addMark(8);
    EXPECT_EQ(7, student->getAveragemark())
}

TEST(, test6) {

}

TEST(, test7) {

}

TEST(, test8) {

}

TEST(, test9) {

}

TEST(, test10) {

}
