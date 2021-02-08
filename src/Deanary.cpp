// Copyright 2021 kostinandrey

#include "Deanary.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <numeric>
#include <random>
#include <sstream>

Group *Deanary::find_group(std::string title) {
    for (auto g : groups) {
        if (g->title == title) {
            return g;
        }
    }
    return nullptr;
}

Student *Deanary::find_student(unsigned int id) {
    for (auto g : groups) {
        for (auto s : g->students) {
            if (s->id == id) {
                return s;
            }
        }
    }
    return nullptr;
}

void Deanary::add_student(std::ifstream& students_stream) {
    std::string line;
    while (std::getline(students_stream, line)) {
        int id;
        std::stringstream ss(line);
        ss >> id;

        std::list<std::string> data;
        std::string chunk;
        while (ss >> chunk) {
            data.push_back(std::move(chunk));
        }
        const std::string groupName = data.back();
        data.pop_back();

        std::string name;
        for (const auto& el : data) {
            name += el;
            name += " ";
        }
        name.pop_back();

        Student* student = new Student(id, name);
        find_group(groupName)->add_student(student);

        int mark;
        while (ss >> mark) {
            student->add_mark(mark);
        }
    }
}

void Deanary::add_group(std::ifstream& groupsStream) {
    std::string title;
    std::string spec;
    while(!groupsStream.eof()) {
        std::getline(groupsStream, title, ' ');
        std::getline(groupsStream, spec, ' ');
        Group *group = new Group(title, spec);
        groups.push_back(new Group(title,spec));
    }
}

void Deanary::add_random_marks() {
    for (auto & group : groups) {
        for (auto & student : group->students) {
            for (int i = 0; i < 15; i++)
                student->add_mark(std::rand() % 10 + 1);
        }
    }
}

double Deanary::get_statistic_students(const std::string& fio) {
    for (auto & group : groups) {
        for (auto & student : group->students) {
            if (student->get_fio() == fio)
                return student->get_average_mark();
        }
    }
}

double Deanary::get_statistic_groups(const std::string& spec) {
    for (auto & group : groups) {
        if (group->get_spec() == spec)
            return group->average_mark_group();
    }
}

void Deanary::move_student(const std::string& fio, const std::string& spec) {
    for (auto & pre_group : groups) {
        for (auto & student : pre_group->students) {
            if (student->get_fio() == fio) {
                for (auto & new_group : groups) {
                    if (new_group->get_spec() == spec) {
                        new_group->add_student(student);
                        pre_group->remove_student(student);
                    }
                }
            }
        }
    }
}

void Deanary::fire_students(const std::vector<Student *> &students) {
    for (Student *student : students) {
        student->group->remove_student(student);
    }
}

void Deanary::choice_head() {
    for (auto & group : groups)
        group->choose_head();
}

void Deanary::print() {
    for (auto & group : groups) {
        std::cout << "*************************************************" << std::endl;
        std::cout << "*************************************************" << std::endl;
        std::cout << "*************************************************" << std::endl;
        std::cout << "Специальность группы: " << group->get_spec() << std::endl;
        std::cout << "*************************************************" << std::endl;
        std::cout << "Название группы: " << group->get_title() << std::endl;
        std::cout << "*************************************************" << std::endl;
        std::cout << "Староста: " << group->head->get_fio() << std::endl;
        std::cout << "*************************************************" << std::endl;
        std::cout << "Список студентов: " << std::endl;
        for (auto & student : group->students) {
            std::cout << "  * " << student->get_fio() << std::endl;
        }
        std::cout << "*************************************************" << std::endl;
        std::cout << "*************************************************" << std::endl;
        std::cout << "*************************************************" << std::endl;
    }
}

void Deanary::save_staff(std::string path) {
    std::ofstream file(path);
    for (auto & group : groups) {
        file << "Group title: " << group->get_title()
             << " Specialization: " << group->get_spec() << '\n';
        if (group->head) {
            file << "Head: " << group->head->fio << '\n';
        }

        for (Student *student : group->students) {
            file << student->id << ' ' << student->fio << ' ';
            for (int i = 0; i < student->marks.size(); i++) {
                file << student->marks[i];
            }
            file << '\n';
        }
        file << '\n';
    }
    file.close();
}

void Deanary::students_from_file(std::string path) {
    std::string name;
    std::ifstream file(path);
    int id = 0;
    while (getline(file, name)) {
        id++;
        Student student_new(id, name);
        Students.push_back(student_new);
    }
}
void Deanary::groups_from_file(std::string path) {
    std::string spec;
    std::string title;
    std::ifstream file(path);
    while (getline(file, spec)) {
        getline(file, title);
        Group *group = new Group(title, spec);
        groups.push_back(new Group(title,spec));
    }
}























