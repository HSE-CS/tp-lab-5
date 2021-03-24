#include <iostream>

#include "Deanary.h"
#include "Group.h"
#include "Student.h"

int main() 
{
	Deanary HSE;

	Student student_2(98, "������ ��������");
	Student student_3(97, "������ ��������");


	Student student_1(99, "������ ������");

	student_1.add_mark(5);
	student_1.add_mark(7);
	student_1.add_mark(9);
	std::cout << student_1.average_mark() << std::endl;

	Group Fil("���1", "���������");
	Fil.add_student(&student_1);
	Fil.choose_headman();
	std::cout << Fil.average_mark() << std::endl;

	HSE.add_group(Fil);
	std::cout << HSE.get_statistic_groups("���������") << std::endl;

	HSE.print();


	return 0;
}