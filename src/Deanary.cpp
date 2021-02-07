// Copyright 2021 Tatsenko Ilya
#include<fstream>
#include<ctime>
#include<clocale>
#include<Windows.h>
#include"Deanary.h"
#include"Group.h"
#include"Student.h"

void Deanary::create_students_from_file(std::string filen) {
    std::srand(time(0));
    std::ifstream file(filen);
    std::string str;
    int ind;
    while (file >> ind) {
        std::getline(file, str);
        str = str.substr(1);
        Student* student = new Student(ind, str);
        this->students.push_back(student);
        student->add_to_group(this->groups[std::rand() % groups.size()]);
    }
    file.close();
}

void Deanary::creative_groups_from_file(std::string file_name) {
    std::ifstream file(file_name);
    std::string str;
    std::string spec;

    while (file >> str) {
        std::getline(file, spec);
        Group* g = new Group(str, spec);
        this->groups.push_back(g);
    }
    file.close();
}

void Deanary::add_marks_to_all() {
    std::srand(time(0));

    for (auto& x : students) {
        for (int i = 0; i < 9; i++) {
            x->add_mark(std::rand() % 10 + 1);
        }
    }
}


void Deanary::init_heads() {
    srand(time(0));
    for (auto& x : groups) {
        x->choose_header(x->students[rand() % x->students.size()]);
    }
}

void Deanary::move_students(std::string student , std::string group) {
    Student* stud = nullptr;
    for (int i = 0; i < this->students.size(); i++) {
        if (student == students[i]->fio) {
            stud = students[i];
            break;
        }
    }

    Group* grup = nullptr;
    for (int i = 0; i < this->groups.size(); i++) {
        if (groups[i]->title == group) {
            grup = groups[i];
            break;
        }
    }
    stud->group->remove_student(stud);
    grup->add_student(stud);
    stud->group = grup;
}

void Deanary::fire_student(std::string student) {
    Student* stud = nullptr;
    for (int i = 0; i < this->students.size(); i++) {
        if (student == students[i]->fio) {
            stud = students[i];
            break;
        }
    }
    stud->group->remove_student(stud);
    for (int i = 0; i < this->students.size(); i++) {
        if (students[i] == stud) {
            students.erase(students.begin() + i);
        }
    }
    free(stud);
}



void Deanary::get_statistic() {
    setlocale(LC_ALL, "rus");
    std::cout << "Statistic " << std::endl << std::endl;

    std::cout << "Groups :" << std::endl;

    for (auto& x : groups) {
        std::cout << x->title << " " << x->spec << " ";
        std::cout << x->calculate_of_avarage_mark() << std::endl;
        std::cout << x->head->fio << std::endl;
        std::cout << "Students :" << std::endl;
            for (auto& student : x->students) {
                std::cout << student->id << " " << student->fio << " ";
                std::cout << student->get_avarage_mark() << std::endl;
            }
        std::cout << std::endl << std::endl << std::endl;
    }
}

void Deanary::save_data_in_file(std::string file1, std::string file2) {
    std::ofstream f1;
    std::ofstream f2;
    f1.open(file1, std::ofstream::out | std::ofstream::trunc);
    f2.open(file2, std::ofstream::out | std::ofstream::trunc);

    for (auto& x : students) {
        f1 << x->id << " " << x->fio << std::endl;
    }
    for (auto& group : groups) {
        f2 << group->title << " " << group->spec << std::endl;
    }
    f1.close();
    f2.close();
}
