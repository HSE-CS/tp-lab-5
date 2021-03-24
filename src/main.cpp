#include <iostream>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"

int main() 
{
	Student s1 = Student(0, "Ivan Ivanov");
	Student s2 = Student(1, "Petr Petrov");
	Student s3 = Student(2, "Eric Ericov");
	Group g1 = Group("GR1", "SPEC");
	g1.addStudent(&s1);
	g1.addStudent(&s2);
	g1.addStudent(&s3);
	g1.removeStudent(&s1);
	g1.removeStudent(&s2);
	g1.removeStudent(&s3);
	std::cout << g1.isEmpty();

	Deanary d1;
	d1.createGroups(R"(C:\Users\user\source\repos\tp-lab-5\tp-lab-5\groups.txt)");
	d1.hireStudents(R"(C:\Users\user\source\repos\tp-lab-5\tp-lab-5\students.txt)");
	d1.initHeads();
	for (int i = 0; i < 3; i++)
		d1.addMarksToAll();
	d1.getStatistics();
	return 0;
}