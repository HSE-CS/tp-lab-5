// Copyright 2021 Bodrov Egor

#include "Deanary.h"

void Deanary::hireStudents(const std::string& filename) {
    std::ifstream file(filename);
    std::string name;
    int id;

    while (file >> id) {
        std::getline(file, name);
        Student* st = new Student(id, name);
        students.push_back(st);
        chooseGroup(st);
    }
    file.close();
}

void Deanary::createGroups(const std::string& filename) {
    std::ifstream file(filename);
    std::string title_;
    std::string spec_;

    while (file >> title_) {
        std::getline(file, spec_);
        Group* gr = new Group {title_, spec_};
        groups.push_back(gr);
    }
    file.close();
}

void Deanary::addMarksToAll() {
    std::srand(time(0));
    for (auto student : students) {
        student->addmark(std::rand() % 10 + 1);
    }
}

void Deanary::getStatistics(const std::string& output) {
    std::ofstream file(output);
    file << "Statistics:\n";
    for (auto gr : groups) {
        file << gr->title << " " << gr->spec << ":\n";
        file << "Average mark: " << gr->getAveragemark() << "\n";
        file << "Number of students: " << gr->students.size() << "\n";
        file << "Head: " << gr->head << "\n";
        for (auto st : gr->students) {
            file << st->get_id() << " " << st->get_name() << " "
            << ", average mark: " << st->getAveragemark() << "\n";
        }
        file << "\n";
    }
    file.close();
}

void Deanary::moveStudents(Student* student,
const std::string& title) {
    Group* gr {nullptr};
    Student* st {nullptr};

    for (auto group : groups) {
        if (group->title == title) {
            gr = group;
            break;
        }
    }

    for (auto stud : students) {
        if (stud == student) {
            st = stud;
            break;
        }
    }

    if (gr != nullptr && st != nullptr) {
        student->addToGroup(gr);
        student->group->removeStudent(student);
        gr->addStudent(student);
    }
}

void Deanary::saveStaff(const std::string& students_file, 
const std::string& groups_file) {
    std::ofstream file1(students_file);
    std::ofstream file2(groups_file);

    for (auto st : students) {
        file1 << st->get_id() << " " << st->get_name() << '\n';
    }

    for (auto gr : groups) {
        file2 << gr->title << " " << gr->spec << ":\n";
        for (auto st : gr->students) {
            file2 << st->get_id() << " " << st->get_name() << '\n';
        }
    }
    file1.close();
    file2.close();
}

void Deanary::initHeads() {
    std::srand(time(0));
    for (auto gr : groups) {
        gr->chooseHead(students[std::rand() % students.size()]);
    }
}

void Deanary::fireStudents() {
    for (auto student : students) {
        if (student->getAveragemark() < 3.5) {
            student->group->removeStudent(student);
        }
    }
}

void Deanary::chooseGroup(Student* student) {
    if (groups.size() < 1)
        return;

    unsigned int min {51};
    int index {0};
    for (int i = 1; i < groups.size(); i++) {
        if (groups[i]->students.size() < min) {
            min = groups[i]->students.size();
            index = i;
        }
    }
    groups[index]->addStudent(student);
}
