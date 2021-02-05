

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
	gr.addStudent(student);
	EXPECT_EQ("Ivanov Ivan Ivanovich", gr.students[0]->fio);
}

TEST(Group, TEST5) {
	Group gr;
	auto* student = new Student(1, "Ivanov Ivan Ivanovich");
	gr.addStudent(student);
	gr.chooseHead(0);
	EXPECT_EQ(true, gr.students[0]->isHead);
}

TEST(Group, TEST6) {
	Group gr;
	auto* student = new Student(1, "Ivanov Ivan Ivanovich");
	gr.addStudent(student);
	gr.chooseHead(0);
	EXPECT_EQ("Ivanov Ivan Ivanovich", gr.head->fio);
}

TEST(Group, TEST7) {
	Group gr;
	auto* student = new Student(1, "Ivanov Ivan Ivanovich");
	auto* student2 = new Student(2, "Petrov Petr Petrovich");
	gr.addStudent(student);
	gr.addStudent(student2);
	EXPECT_EQ(0, gr.getAveragemark());
}

TEST(Group, TEST8) {
	Group gr;
	auto* student = new Student(1, "Ivanov Ivan Ivanovich");
	auto* student2 = new Student(2, "Petrov Petr Petrovich");
	gr.addStudent(student);
	gr.addStudent(student2);
	gr.students[0]->addmark(1);
	gr.students[0]->addmark(3);
	gr.students[0]->addmark(5);
	gr.students[1]->addmark(1);
	gr.students[1]->addmark(3);
	gr.students[1]->addmark(5);
	EXPECT_EQ(3, gr.getAveragemark());
}

TEST(Group, TEST9) {
	Group gr;
	auto* student = new Student(1, "Ivanov Ivan Ivanovich");
	gr.addStudent(student);
	gr.removeStudent(student);
	EXPECT_EQ(NULL, student);
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
	EXPECT_EQ("Ivanov Ivan Ivanovich", a.students[0]->fio);
}

TEST(Student, TEST12) {
	Deanary dec;
	dec.createGroups("Groups.txt");
	dec.hireStudents("Students.txt");
	Group* gr = dec.getGroup(0);
	gr.students[0]->addmark(1);
	gr.students[0]->addmark(3);
	gr.students[0]->addmark(5);
	gr.students[1]->addmark(1);
	gr.students[1]->addmark(3);
	gr.students[1]->addmark(5);
	EXPECT_EQ(3, dec.getStatistics());
}