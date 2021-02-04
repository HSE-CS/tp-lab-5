// Copyright 2021 GN
#include "Student.h"
#include "Group.h"
#include "Deanary.h"
#include <string>
int main() {
	Student st1(21, "Petrov I.I.");
	double d = st1.avMark();
	printf("av_mark=%f\n", d);
	Student st2(54, "Petrova I.I.");
	st2.addMark(10);
	st2.addMark(9);
	st2.addMark(6);
	st2.addMark(5);
	// double d = st1.avMark();
	// printf("av_mark=%f\n", d);
	int id = st1.getId();
	printf("%d\n", id);
	std::string name = st1.getName();
	std::cout << name << std::endl;
	// printf("%s\n", name);
	Group gr1("Applied Mathematics and Informatics","AMI");
	gr1.addStudent(&st1);
	// gr1.addStudent(&st2);
	// st1=gr1.getStudent(21);
	// std::cout << st1.getName() << std::endl;
	Student st3(41, "Perov I.I.");
	// gr1.addStudent(&st3);
	st3.addMark(7);
	st3.addMark(4);
	st3.addMark(3);
	st3.addMark(0);
	double d3 = st3.avMark();
	printf("av_mark_of_st3= %f\n", d3);
	Student st4(41, "Perfov I.I.");
	// gr1.addStudent(&st4);
	st4.addMark(0);
	st4.addMark(9);
	st4.addMark(0);
	st4.addMark(0);
	/* Student st5(41, "Perffov I.I.");
	gr1.addStudent(&st5);
	Student st6(41, "Perfffov I.I.");
	gr1.addStudent(&st6); */
	gr1.initHead();
	// st3 = gr1.getHead();
	std::cout << "head is " <<gr1.getHead().getName() << std::endl;
	double rrr = gr1.av_mark();
	std::cout << rrr << std::endl;
	gr1.delStudent(&st4);
	Deanary dr;
	dr.addGroup(gr1);
	// dr.acceptStudents();
	// dr.createGroups();
	// dr.studentRegistration();
	dr.addMarks();
	std::cout << dr.getStatisticByGroups("AMI") << std::endl;
	std::cout << dr.getStatisticByStudents("Debbie Bowen") << std::endl;
	// dr.transferStudent("Debbie Bowen", "AMI");
	dr.initOfHeadElection();
	std::cout << "---------------------------------------------" << std::endl;
	dr.printAllInfo();
	// dr.initOfHeadElection();
	// dr.initOfHeadElection();
	std::cout << "---------------------------------------------" << std::endl;
	// dr.printAllInfo();
	// dr.addStudent(&st1, "PH");
	// std::cout << "---------------------------------------------" << std::endl;
	// dr.printAllInfo();
	// dr.hireStudent("Petrov I.I.");
	// std::cout << "---------------------------------------------" << std::endl;
	// dr.printAllInfo();
	dr.saveToFiles();
}
