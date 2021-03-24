#include <iostream>

#include "Deanary.h"
#include "Group.h"
#include "Student.h"

int main() 
{
	Deanary HSE;

	Student student_2(98, "Ксения Тарасова");
	Student student_3(97, "Эмилия Троицкая");


	Student student_1(99, "Михаил Петров");

	student_1.add_mark(5);
	student_1.add_mark(7);
	student_1.add_mark(9);
	std::cout << student_1.average_mark() << std::endl;

	Group Fil("Фил1", "Филология");
	Fil.add_student(&student_1);
	Fil.choose_headman();
	std::cout << Fil.average_mark() << std::endl;

	HSE.add_group(Fil);
	std::cout << HSE.get_statistic_groups("Филология") << std::endl;

	HSE.print();


	return 0;
}