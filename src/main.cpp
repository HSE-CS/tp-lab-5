// Copyright dash 2021
#include "Student.h"
#include "Group.h"
#include "Deanary.h"
#include <string>

int main() {
	Student n1(1, "Anna Kuznecova");
	Student n2(2, "Roman Zaycev");
	n1.get_fio();
	n2.get_id();

	Student n3(3, "Maria Ivanova");
	n3.add_mark(10);
	n3.add_mark(6);
	n3.add_mark(6);
	n3.average_mark();

	Group m("SE", "Software Engineering");
	Student n5(9, "Ivan Vasilyev");
	m.add_student(&n5);
	m.findStudent("Ivan Vasilyev").get_id();

	Deanary a;
	a.add_st_file();
	a.add_gr_file();
	a.output();
	return 0;
}
