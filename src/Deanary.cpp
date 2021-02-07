// Copyright 2021 Kartseva Masha
#include "Deanary.h"

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> words;
    std::string word;
    std::istringstream wordStream(s);
    while (getline(wordStream, word, delimiter))
	    words.push_back(word);
    return words;
}

Deanary::Deanary() {
    dean_id = 0;
    std::vector<Group*> groups;
}

void Deanary::addGroups(std::string names_input, std::string groups_input) {
    std::ifstream file;
    file.open(groups_input, std::ios::in);
    system("chcp 65001");
    std::string buf;
    std::vector <std::string> current_str;
    while (getline(file, buf)) {
	    current_str = split(buf, ':');
	    groups.push_back(new Group(current_str[0], current_str[1]));
    }
    file.close();
    file.open(names_input, std::ios::in);
    while (getline(file, buf)) {
	    current_str = split(buf, ':');
	    Student* student = new Student(current_str[0], dean_id);
	    bool is_constructed = 0;
	    int group_num = -1;
	    for (unsigned int i = 0; i < groups.size(); i++) {
		    if (groups[i]->getTitle() == current_str[1]) {
			    is_constructed = 1;
		        group_num = i;
		    }
	    }
	    if (!is_constructed) {
		    Group* group = new Group(current_str[1], "");
		    groups.push_back(group);
		    group_num = groups.size() - 1;
	    }
	    groups[group_num]->addStudent(student);
        student->setGroup(groups[group_num]);
        dean_id++;
    }
    file.close();
}

void Deanary::set_random_marks(unsigned int number) {
    for (Group* group : this->groups){
        for (Student* student : group->getStudents()){
            for (unsigned int i = 0; i < number; i++) {
                student->addMark(rand() % 10 + 1);
		    }
        }
    }
}

void Deanary::getStatistics() const {
    for (Group* group : groups) {
	    group->AverageMarkofGroup();
	    std::vector<Student*> students = group->getStudents();
	    unsigned int best_mark = 0;
	    unsigned int index;
	    for (unsigned int i = 0; i < students.size(); i++) {
		    if ((students[i]->AverageMark()) > best_mark) {
			    index = i;
		    }
	    }
	    std::cout << "Best student : " << students[index]->getName() << std::endl;
    }
}

void Deanary::changeGroup(std::string name, std::string oldGroup, std::string newGroup) {
    Group* group1 = nullptr;
    Group* group2 = nullptr;
    for (Group* group : groups) {
	    if (group->getTitle() == oldGroup) group1 = group;
	    if (group->getTitle() == newGroup) group2 = group;
    }
    Student* student = group1->findbyName(name);
	if ((group1 == nullptr) || (group2 == nullptr)) {
	    std::cout << "Error. Try again" << std::endl;
	    return;
    } else {
	    group1->expelStudent(student);
	    group2->addStudent(student);
    }
}

void Deanary::expelStudents() {
	for (Group* group : groups) {
	    for (Student* student : group->getStudents()) {
		    if (student->AverageMark() < 4) {
				group->expelStudent(student);
		    }
	    }
    }
}

void Deanary::rewriteData(std::string names_output, std::string groups_output) const {
    std::ofstream file;
    file.open(names_output, std::ios::out);
    if (file.is_open()) {
	    for (Group* group : groups) {
		    for (Student* student : group->getStudents()) {
			    std::cout << student->getName() << " : " << group->getTitle() << std::endl;
		    }
	    }
    } else std::cout << "File can't be opened" << std::endl;
    file.close();
    file.open(groups_output, std::ios::out);
    if (file.is_open()) {
	    for (Group* group : groups) {
		    std::cout << group->getTitle() << " : " << group->getSpec() << std::endl;
	    }
    } else std::cout << "File can't be opened" << std:: endl;
    file.close();
}

void Deanary::chooseHeads() {
    for (Group* group : groups) {
	    group->chooseHead();
    }
}
