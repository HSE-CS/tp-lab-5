// Copyright 2021 Shatilov Victor
#include <iostream>
#include <cstring>
#include "Deanary.h"

void Deanary::createGroup(std::string title, std::string spec) {
    groups.push_back(new Group(title, spec));
}

void Deanary::createStudent(std::string fio, Group* group) {
    group->addStudent(new Student(studentsId, fio));
    studentsId++;
}

Group* Deanary::getGroupByTitle(const std::string& groupName) {
    for (Group* g : groups) {
        if (g->title == groupName)
            return g;
    }
    return nullptr;
}


bool Deanary::createGroupsFromFile(const std::string& path) {
    std::ifstream file(path);
    if (!file) {
        std::cerr << "Error: " << strerror(errno);
        return EXIT_FAILURE;
    }
    std::string s;

    while (std::getline(file, s)) {
        int pos = s.find(' ');
        createGroup(s.substr(0, pos), s.substr(pos + 1));
    }

    file.close();
    return EXIT_SUCCESS;
}


bool Deanary::createStudentsFromFile(std::string path) {
    std::ifstream file(path);
    if (!file) {
        std::cerr << "Error: " << strerror(errno);
        return EXIT_FAILURE;
    }
    std::string s;

    while (std::getline(file, s)) {
        int pos = s.rfind(' ');
        std::string fio = s.substr(0, pos);
        std::string groupTitle = s.substr(pos + 1);
        std::cout << fio << ":" << groupTitle << std::endl;
        Group* g = getGroupByTitle(groupTitle);
        if (g) {
            createStudent(fio, g);
        }
        else {
            std::cout << groupTitle;
            return EXIT_FAILURE;
        }
    }
    file.close();
    return EXIT_SUCCESS;
}

void Deanary::addRandomMarks() {
    std::srand(static_cast<unsigned int>(time(nullptr)));
    for (Group *group : groups) {
        for (Student *student : group->students) {
            for (int i = 0; i < 10; i++) {
                student->rate(std::rand() % 5 + 1);
            }
        }
    }
}

std::string Deanary::getStatistics() {
    std::string s;
    for (Group *group : groups) {
        s += "Группа: " + group->title + " Специализация: "
                + group->spec + '\n';
        if (group->head)
            s += "Староста: " + group->head->fio + '\n';
        s += "Средняя оценка в группе: "
                + std::to_string(group->getAverageMark()) + '\n';
        for (Student *student : group->students)
            s += student->fio + " - "
                    + std::to_string(student->getAverageMark()) + '\n';
    }
    return s;
}

void Deanary::moveStudent(Student* student, Group* group) {
    student->group->kickStudent(student);
    group->addStudent(student);
}

bool Deanary::saveToFile(std::string path) {
    std::ofstream file(path);
    if (!file) {
        std::cerr << "Error: " << strerror(errno);
        return EXIT_FAILURE;
    }

    for (Group *group : groups) {
        file << "Группа: " << group->title
             << " Специализация: " << group->spec << '\n';
        if (group->head) {
            file << "Староста: " << group->head->fio << '\n';
        }

        for (Student *student : group->students) {
            file << student->id << ' ' << student->fio << ' ';
            for (int mark : student->marks) {
                file << mark;
            }
            file << '\n';
        }
        file << '\n';
    }
    file.close();
    return EXIT_SUCCESS;
}

void Deanary::initHeads() {
    for (Group *group : groups) {
        if (!group->isEmpty()) {
            Student *newHead = group->students[0];
            for (Student *student : group->students) {
                if (student->getAverageMark() > newHead->getAverageMark())
                    newHead = student;
            }
            group->chooseHead(newHead);
        }
    }
}

void Deanary::kickStudentsForBadMarks(float BadMark) {
    for (Group *group : groups) {
        for (Student *student : group->students) {
            if (student->getAverageMark() < BadMark)
                student->group->kickStudent(student);
        }
    }
}
