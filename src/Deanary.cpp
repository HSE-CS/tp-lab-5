// Copyright 2021 Stolbov Yaroslav

#include "Deanary.h"

void Deanary::createStudents(std::fstream &studentsStream) {
    std::string str;
    while (std::getline(studentsStream, str)) {
        int spaceCounter = 0;
        int indexThirdSpace;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                spaceCounter++;
                if (spaceCounter == 3) indexThirdSpace = i;
            }
        }
        Student student = Student(str.substr(0, indexThirdSpace));
        std::string number = str.substr(indexThirdSpace + 1,
                                        str.size() - indexThirdSpace - 3);
        std::string special = str.substr(str.size() - 1,
                                         str.size() - 1);
        bool flagFindGroup = false;
        for (Group gr : groups) {

            if (gr.getGroupName() == number + " " + special) {
                flagFindGroup = true;
            }
        }

        if (!flagFindGroup) {
            Group group = Group(number, special);
            group.addStudent(student);
            this->groups.push_back(group);
        } else {
            for (int i = 0; i < groups.size(); i++) {
                //std::cout << "kek ";
                if (groups[i].getGroupName() == number + " " + special) {
                    groups[i].addStudent(student);
                }
            }
        }
    }
}

void Deanary::addRandomMarks() {
    for (int i = 0; i < groups.size(); i++) {
        for (int j = 0; j < groups[i].students.size(); j++) {
            for (int k = 0; k < 10; k++)
                groups[i].students[j].addMark(rand() % 10 + 1);
        }
    }
}

void Deanary::getStatistic() {
    for (auto gr : groups) {
        std::cout << "Group " << gr.getGroupName()
        << " statistics: " << gr.groupMiddleMark() << "\n";
        for (auto st : gr.students) {
            std::cout << "Student " << st.getFio()
            << " statistics: " << st.getMiddleMark() << "\n";
        }
    }

}

void Deanary::swapGroup(Student student, Group groupTo) {
    student.group->removeStudent(student.getFio());
    student.addGroup(groupTo);


}

const std::vector<Group> &Deanary::getGroups() const {
    return groups;
}

void Deanary::studentExpulsion(std::fstream &studentsStream) {
    for (int i = 0; i < groups.size(); i++) {
        for (int j = 0; j < groups[i].students.size(); j++) {
            if (groups[i].students[j].getMiddleMark() < 3.5) {
                groups[i].removeStudent(groups[i].students[j].getFio());
                std::string str;
                while (std::getline(studentsStream, str)) {
                    if (str.find(groups[i].students[j].getFio()) != -1) str.clear();
                }
            }
        }
    }
}

void Deanary::initHeads() {
    for (int i = 0; i < groups.size(); i++) {
        int randomHead = rand() % groups[i].students.size() + 1;
        groups[i].chooseHead(groups[i].students[randomHead]);
        heads.push_back(groups[i].students[randomHead]);
        //std::cout << heads[i].getFio() << "\n";
    }
}

void Deanary::printInformation() {
    for (int i = 0; i < groups.size(); i++) {
        std::cout << "Group: " << groups[i].getGroupName() << "\n";
        std::cout << "Head: " << groups[i].head << "\n";
        std::cout << "Students: " << groups[i].head << "\n";
        for (int j = 0; j < groups[i].students.size(); j++) {
            std::cout << groups[i].students[j].fio << "\n";
        }
    }
}

