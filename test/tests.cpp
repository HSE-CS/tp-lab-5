

#include <gtest/gtest.h>
#include <string>
#include "../include/Student.h"
#include "../include/Group.h"

TEST(Student, TEST1) {
	Student student(1, "Ivanov Ivan Ivanovich");
	EXPECT_EQ(1, student.getId());
}

TEST(Student, TEST2) {
	Student student(1, "Ivanov Ivan Ivanovich");
	EXPECT_EQ(false, student.isHeadOfGroup());
}

TEST(Student, TEST3) {
	Student student(1, "Ivanov Ivan Ivanovich");
	student.addmark(5);
	student.addmark(7);
	EXPECT_EQ(6, student.getAvearagemark());
}

TEST(Group, TEST4) {
	Group gr;
	auto* student = new Student(1, "Ivanov Ivan Ivanovich");
	gr.AddStudent(student);
	EXPECT_EQ("Ivanov Ivan Ivanovich", gr.getStudent("1")->getFio());
}

TEST(Group, TEST5) {
	Group gr;
	auto* student = new Student(1, "Ivanov Ivan Ivanovich");
	gr.AddStudent(student);
	gr.chooseHeadTest(0);
	EXPECT_EQ(true, gr.getStudent("1")->isHeadOfGroup());
}

TEST(Group, TEST6) {
	Group gr;
	auto* student = new Student(1, "Ivanov Ivan Ivanovich");
	gr.AddStudent(student);
	gr.chooseHeadTest(0);
	EXPECT_EQ("Ivanov Ivan Ivanovich", gr.getHead()->getFio());
}

TEST(Group, TEST7) {
	Group gr;
	auto* student = new Student(1, "Ivanov Ivan Ivanovich");
	auto* student2 = new Student(2, "Petrov Petr Petrovich");
	gr.AddStudent(student);
	gr.AddStudent(student2);
	EXPECT_EQ(0, gr.getAveragemark());
}

TEST(Group, TEST8) {
	Group gr;
	auto* student = new Student(1, "Ivanov Ivan Ivanovich");
	auto* student2 = new Student(2, "Petrov Petr Petrovich");
	gr.AddStudent(student);
	gr.AddStudent(student2);
	gr.getStudent("1")->addmark(1);
	gr.getStudent("1")->addmark(3);
	gr.getStudent("1")->addmark(5);
	gr.getStudent("2")->addmark(1);
	gr.getStudent("2")->addmark(3);
	gr.getStudent("2")->addmark(5);
	EXPECT_EQ(3, gr.getAveragemark());
}


TEST(Student, TEST10) {
	Deanary dec;
	dec.createGroups("Groups.txt");
	dec.hireStudents("Students.txt");
	EXPECT_EQ(0, dec.getStatistics());
}

TEST(Student, TEST11) {
	Deanary dec;
	dec.createGroups("Groups.txt");
	dec.hireStudents("Students.txt");
	Group* a = dec.getGroup(0);
	EXPECT_EQ("Owen Joseph Charles", a.getStudent("1")->getFio());
}

TEST(Student, TEST12) {
	Deanary dec;
	dec.createGroups("Groups.txt");
	dec.hireStudents("Students.txt");
	Group* gr = dec.getGroup(0);
	gr.getStudent("1")->addmark(1);
	gr.getStudent("1")->addmark(3);
	gr.getStudent("1")->addmark(5);
	gr.getStudent("2")->addmark(1);
	gr.getStudent("2")->addmark(3);
	gr.getStudent("2")->addmark(5);
	EXPECT_EQ(3, dec.getStatistics());
}
