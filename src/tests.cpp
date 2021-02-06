// Copyright 2021 Dmitry Malinin
#include <string>
#include "gtest/gtest.h"
#include "Student.h"
#include "Group.h"
TEST(MyDeaneryTest, test1) {
    unsigned int id = 11;
    std::string fio = "Ddsa Sfdsfsdf";
    Student student1(id, fio);
    EXPECT_EQ("Ddsa Sfdsfsdf", student1.getFio());
}

TEST(MyDeaneryTest, test2) {
    unsigned int id = 11;
    std::string fio = "Ddsa Sfdsfsdf";
    Student student1(id, fio);
    EXPECT_EQ(11, student1.getId());
}

TEST(MyDeaneryTest, test3) {
    unsigned int id = 11;
    std::string fio = "Ddsa Sfdsfsdf";
    Student student(id, fio);
    student.addMark(1);
    student.addMark(2);
    student.addMark(3);
    student.addMark(4);
    EXPECT_EQ(2.5, student.getAveragemark());
}

TEST(MyDeaneryTest, test4) {
    unsigned int id = 1;
    std::string fio = "Ddsa Sfdsfsdf";
    Student student(id, fio);
    unsigned int id2 = 2;
    std::string fio2 = "Ddsa Sfdsfsdf44";
    Student student2(id2, fio2);
    std::string title = "Group1";
    std::string spec = "AMI";
    Group group(title, spec);
    group.addStudent(&student);
    group.addStudent(&student2);

    EXPECT_EQ(false, group.isEmpty());
}

TEST(MyDeaneryTest, test5) {
    unsigned int id = 1;
    std::string fio = "Ddsa Sfdsfsdf";
    Student student(id, fio);
    unsigned int id2 = 2;
    std::string fio2 = "Ddsa Sfdsfsdf44";
    Student student2(id2, fio2);
    std::string title = "Group1";
    std::string spec = "AMI";
    Group group(title, spec);
    group.addStudent(&student);
    group.addStudent(&student2);
    EXPECT_EQ(&group, student.getGroup());
}

TEST(MyDeaneryTest, test6) {
    unsigned int id = 1;
    std::string fio = "Ddsa Sfdsfsdf";
    Student student(id, fio);
    student.addMark(5);
    unsigned int id2 = 2;
    std::string fio2 = "Ddsa Sfdsfsdf44";
    Student student2(id2, fio2);
    student2.addMark(3);
    std::string title = "Group1";
    std::string spec = "AMI";
    Group group(title, spec);
    group.addStudent(&student);
    group.addStudent(&student2);
    EXPECT_EQ(4, group.getAverageMark());
}

TEST(MyDeaneryTest, test7) {
    unsigned int id = 1;
    std::string fio = "Ddsa Sfdsfsdf";
    Student student(id, fio);
    student.addMark(5);
    unsigned int id2 = 2;
    std::string fio2 = "Ddsa Sfdsfsdf44";
    Student student2(id2, fio2);
    student2.addMark(3);
    std::string title = "Group1";
    std::string spec = "AMI";
    Group group(title, spec);
    group.addStudent(&student);
    group.addStudent(&student2);

    group.removeStudent(&student);
    EXPECT_EQ(nullptr, group.containsStudent(id));
}

TEST(MyDeaneryTest, test8) {
    unsigned int id = 1;
    std::string fio = "Ddsa Sfdsfsdf";
    Student student(id, fio);
    student.addMark(5);
    unsigned int id2 = 2;
    std::string fio2 = "Ddsa Sfdsfsdf44";
    Student student2(id2, fio2);
    student2.addMark(3);
    std::string title = "Group1";
    std::string spec = "AMI";
    Group group(title, spec);
    group.addStudent(&student);
    group.addStudent(&student2);

    group.removeStudent(&student);
    EXPECT_EQ(&student2, group.containsStudent(fio2));
}

TEST(MyDeaneryTest, test9) {
    unsigned int id = 1;
    std::string fio = "Ddsa Sfdsfsdf";
    Student student(id, fio);
    student.addMark(5);
    unsigned int id2 = 2;
    std::string fio2 = "Ddsa Sfdsfsdf44";
    Student student2(id2, fio2);
    student2.addMark(3);
    std::string title = "Group1";
    std::string spec = "AMI";
    Group group(title, spec);
    group.addStudent(&student);
    group.addStudent(&student2);

    EXPECT_EQ("Group1", group.getTitle());
}

TEST(MyDeaneryTest, test10) {
    unsigned int id = 1;
    std::string fio = "Ddsa Sfdsfsdf";
    Student student(id, fio);
    student.addMark(5);
    unsigned int id2 = 2;
    std::string fio2 = "Ddsa Sfdsfsdf44";
    Student student2(id2, fio2);
    student2.addMark(3);
    std::string title = "Group1";
    std::string spec = "AMI";
    Group group(title, spec);
    group.addStudent(&student);
    group.addStudent(&student2);

    EXPECT_EQ("AMI", group.getSpec());
}

TEST(MyDeaneryTest, test11) {
    unsigned int id = 1;
    std::string fio = "Ddsa Sfdsfsdf";
    Student student(id, fio);
    unsigned int id2 = 2;
    std::string fio2 = "Ddsa Sfdsfsdf44";
    Student student2(id2, fio2);
    std::string title = "Group1";
    std::string spec = "AMI";
    Group group(title, spec);

    EXPECT_EQ(true, group.isEmpty());
}


