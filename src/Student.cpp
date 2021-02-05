#include "Student.h"
#include "Group.h"

void Student::addmark(int mark) {
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
	if (mount == 0) {
		return 0;
	}
	return sum / mount;
}
bool Student::isHeadOfGroup() {
	return this->isHead;
}

Student::Student(int num, std::string fi, Group* gr) {
	id = num;
	fio = fi;
	group = gr;
}

Student::Student(int num, std::string fi) {
	id = num;
	fio = fi;
}