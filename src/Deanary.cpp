// Copyright by JMax 2020

#include "Deanary.h"
#include <fstream>
#include <sstream>
#include <iostream>

Deanary::Deanary() {
    groups = std::vector<Group*>();
}

bool Deanary::isIdUnique(unsigned int id, std::vector<Student*> *studentsVec) {
    if (studentsVec == nullptr) {
        for (auto group : groups) {
            for (auto student : group->students) {
                if (student->getId() == id) {
                    return false;
                }
            }
        }
    } else {
        for (auto student : *studentsVec) {
            if (student->getId() == id) {
                return false;
            }
        }
    }
    return true;
}

Student *Deanary::createStudent(const std::string &fio,
                                std::vector<Student*> *studentsVec) {
    srand(time(0));

    unsigned int id;

    do {
        id = rand();
    } while (!isIdUnique(id, studentsVec));

    return new Student(id, fio);
}

static std::vector <std::string> split(const std::string& line, char delim) {
    std::stringstream ss(line);
    std::string item;
    std::vector<std::string> elems;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

void Deanary::createGroups(const std::string &fileName) {
    std::ifstream groupFile(fileName);
    std::string line;
    if (groupFile) {
        while (std::getline(groupFile, line)) {
            auto elems = split(line, '/');
            addGroup(elems[0], elems[1]);
        }
        groupFile.close();
    }
}

void Deanary::addGroup(Group *group) {
    groups.push_back(group);
}

void Deanary::hireStudents(const std::string &fileName) {
    std::fstream studentsFile;
    std::string line;
    std::vector<Student*> students;
    studentsFile.open(fileName);
    if (studentsFile.is_open()) {
        while (std::getline(studentsFile, line)) {
            students.push_back(createStudent(line, &students));
        }

        int j = 0;
        for (auto group : groups) {
            for (int i = 0; i < students.size() / numOfGroups(); i++) {
                addStudent(students[j++], group);
            }
        }

        while (j != students.size() - 1) {
            addStudent(students[j++], groups[0]);
        }

        studentsFile.close();
    }
}

unsigned int Deanary::numOfGroups() const {
    return groups.size();
}

bool Deanary::containsGroup(const std::string &title) const {
    return groupIndex(title) != -1;
}

Group *Deanary::getGroup(const std::string &title) const {
    if (containsGroup(title)) {
        return groups[groupIndex(title)];
    }
    throw "No group found";
}

std::string Deanary::generateStatistics() {
    std::stringbuf stats;
    std::ostream stream(&stats);
    stream << "-----Statistics-----" << std::endl;
    for (auto group : groups) {
        stream << "Group: " << group->title << " " << group->spec << std::endl;
        if (group->getHead() != nullptr) {
            stream << "Head of group: " << group->head->getFio()
            << "\t(id: " << group->head->getId() << ")" << std::endl;
        }
        stream << "Average mark of group: "
        << group->getAverageMark() << std::endl;

        stream << "Average marks: " << std::endl;
        for (auto student : group->students) {
            stream << student->getFio() << "\t(id: "
            << student->getId() << "):\t"
            << student->getAverageMark() << std::endl;
        }
        stream << "---------" << std::endl;
    }
    stream << "-----End of Statistics-----" << std::endl;
    return stats.str();
}

void Deanary::addMarksToAll() {
    srand(12);
    for (auto group : groups) {
        for (auto student : group->students) {
            for (int i = 0; i < 10; i++) {
                student->addMark(4 + rand() % 8 - 2 * (rand() % 4));
            }
        }
    }
}

void Deanary::getStatistics() {
    std::cout << generateStatistics();
}

void Deanary::moveStudent(const std::string &fio,
                          const std::string& from, const std::string& to) {
    if (containsGroup(from)) {
        auto groupFrom = getGroup(from);

        if (groupFrom->containsStudent(fio)) {
            moveStudent(groupFrom->getStudent(fio)->getId(), from, to);
        }
    }
}

void Deanary::moveStudent(const unsigned int id,
                          const std::string &from, const std::string &to) {
    if (containsGroup(from) && containsGroup(to)) {
        auto groupFrom = getGroup(from);
        auto groupTo = getGroup(to);

        if (groupFrom->containsStudent(id)) {
            auto student = groupFrom->getStudent(id);

            student->group = groupTo;
            groupFrom->removeStudent(student);
            groupTo->addStudent(student);
        }
    }
}

void Deanary::saveStaff(const std::string &fileName) {
    std::ofstream outFile;
    outFile.open(fileName);
    if (outFile.is_open()) {
        outFile << generateStatistics();
        outFile.close();
    }
}

void Deanary::addStudent(Student *student, Group *group) {
    group->addStudent(student);
}

void Deanary::addGroup(const std::string &title, const std::string &spec) {
    if (!containsGroup(title)) {
        addGroup(new Group(title, spec));
    }
}

void Deanary::addStudent(const std::string &fio,
                         const std::string &groupTitle) {
    if (containsGroup(groupTitle)) {
        addStudent(createStudent(fio), getGroup(groupTitle));
    }
}

void Deanary::initHeads() {
    for (auto group : groups) {
        group->chooseHead();
    }
}

void Deanary::fireStudents() {
    for (auto group : groups) {
        for (auto student : group->students) {
            if (student->getAverageMark() < 3.5) {
                group->removeStudent(student);
            }
        }
    }
}

Deanary::~Deanary() {
    for (auto group : groups) {
        delete group;
    }
}

int Deanary::groupIndex(const std::string &title) const {
    for (int i = 0; i < numOfGroups(); i++) {
        if (groups[i]->title == title) {
            return i;
        }
    }
    return -1;
}
