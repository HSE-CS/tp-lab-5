#include "Student.h"
#include "Group.h"

void Student::addmark(int mark) {
	if (mark < 4 and intel == "high") {
			mark += 6;
	}
	else if (mark >= 5 and intel == "low") {
		mark -= 4;
	}
	marks.push_back(mark);
}

void Student::addToGroup(Group& A) {
	*group = A;
}

double Student::getAvearagemark() {
	double sum = 0;
	int mount = this->marks.size();
	for (int i = 0; i < mount; ++i) {
		sum += this->marks[i];
	}
	return sum / mount;
}
bool Student::isHeadOfGroup() {
	return this->isHead;
}

Student::Student(int num, std::string fi, Group* gr, int intellegence) {
	switch (intellegence) {
	case (1):
		intel = "low";
		break;
	case(2,3):
		intel = "average";
		break;
	case(4):
		intel = "high";
		break;
	}
	id = num;
	fio = fi;
	group = gr;
}

Student::Student(int num, std::string fi) {
	id = num;
	fio = fi;
}