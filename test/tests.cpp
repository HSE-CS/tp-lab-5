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
    bool ex1 = group->getStudents()[0]->getId() == 0;
    bool ex2 = group->getStudents()[0]->getId() == 0;
    EXPECT_TRUE(((ex1) && (ex2)));
}

TEST(Student, test5) {
    Student *student = new Student("Kamri3.5");
    student->addMark(6);
    student->addMark(8);
    EXPECT_EQ(7, std::round(student->getAveragemark()));
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
}

TEST(Deanery, test7) {
    Deanery *deanery = new Deanery();
    Deanery::path_to_data = "../../../data"
    deanery->createGroups("groupInput.txt");
    EXPECT_EQ(3, deanery->getGroups().size());
}

TEST(Deanery, test8) {
    Deanery *deanery = new Deanery();
    Deanery::path_to_data = "../../../data"
    deanery->hireStudents("studInput.txt");
    EXPECT_EQ(56, Student::getLastId());
}

TEST(Deanery, test9) {
    Deanery *deanery = new Deanery();
    Deanery::path_to_data = "../../../data"
    deanery->hireStudents("studInput.txt");
    deanery->addMarksToAll(5);
    int a = deanery->getGroups()[0]->
            getStudents()[0]->getMarks().size();
    EXPECT_EQ(5, a);
}

TEST(Deanery, test10) {
    Deanery *deanery = new Deanery();
    Deanery::path_to_data = "../../../data"
    deanery->hireStudents("studInput.txt");
    Group *new_group = deanery->getGroups()[0];
    Student *me = deanery->getGroups()[1]->getStudent(30);
    deanery->moveStudents(me, new_group);
}
