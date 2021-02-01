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
    delete student;
}

TEST(Student, test2) {
    Student *student = new Student("QwertyP");
    EXPECT_EQ(0, std::strcmp("QwertyP", student->getFio().c_str()));
    delete student;
}

TEST(Student, test3) {
    Group *group = new Group("PI");
    Student *student = new Student("Vargin");
    group->addStudent(student);
    EXPECT_EQ(0, std::strcmp("PI",
                 student->getGroup()->getTitle().c_str()));
    delete group;
    delete student;
}

TEST(Group, test4) {
    Group *group = new Group("PI");
    Student *student1 = new Student("Qwery");
    group->addStudent(student1);
    group->chooseHead(student1);
    EXPECT_EQ(0, group->getHead()->getId());
    delete group;
    delete student1;
}

TEST(Student, test5) {
    Student *student = new Student("Kamri3.5");
    student->addMark(6);
    student->addMark(8);
    EXPECT_EQ(7, std::round(student->getAveragemark()));
    delete student;
}

TEST(Group, test6) {
    Group *group = new Group("Inglourious Basterds");
    Student *student1 = new Student("Antonio Margaretti");
    student1->addMark(2);
    student1->addMark(4);
    Student *student2 = new Student("Quentin Tarantino");
    student2->addMark(6);
    student2->addMark(8);
    group->addStudent(student1);
    group->addStudent(student2);
    EXPECT_EQ(5, std::round(group->getAveragemark()));
    delete group;
    delete student1;
    delete student2;
}

TEST(Deanery, test7) {
    Group *group = new Group("WOOOORK PEASE!!!");
    EXPECT_EQ(1, 0+group->isEmpty());
}

TEST(Deanery, test8) {
    Group *group = new Group("I WANNA SLEEP!!!");
    Student *student1 = new Student("kek");
    Student *student2 = new Student("lol");
    group->addStudent(student1);
    group->addStudent(student2);
    EXPECT_EQ(1, 0 + group->containsStudent(student2));
}

TEST(Deanery, test9) {
    Group *group = new Group("I LIKE KITTIES");
    Student *student1 = new Student("mem");
    Student *student2 = new Student("zuz");
    group->addStudent(student1);
    group->addStudent(student2);
    group->chooseHead(student2);
    EXPECT_EQ(1, student2->isHeadOfGroup());
}

TEST(Deanery, test10) {
    Group *group = new Group("AND PUPPIES");
    for (int i = 0; i < 10; ++i) {
        std::string name = "student" + std::to_string(i);
        Student *student1 = new Student(name);
    }
    EXPECT_EQ(10, group.ge)
}
