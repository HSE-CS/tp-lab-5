// Copyright dash 2021
#include <Deanary.h>

#include <string>
#include <iostream>
#include <fstream>



void Deanary::add_st_file() {
    std::ifstream file("Students.txt");
    std::string fio;
    int id = 1;
    while (getline(file, fio)) {
        Student newstud(id, fio);
        students.push_back(newstud);
        id = id + 1;
    }
}

void Deanary::add_gr_file() {
    std::ifstream file("Groups.txt");
    std::string title;
    std::string spec;
    while (getline(file, spec)) {
        getline(file, title);
        Group newgroup(title, spec);
        groups.push_back(newgroup);
    }
}


void Deanary::add_marks() {
    int num_gr;
    int num_stud;
    int size_gr = groups.size();
    int mark;
    for (num_gr = 0; num_gr < size_gr; num_gr++) {
        for (num_stud = 0; num_stud < groups[num_gr].students.size(); num_stud++) {
            for (int i = 0; i < 10; i++) {
                mark = std::rand() % 10 + 1;
                groups[num_gr].students[num_stud]->add_mark(mark);
            }
        }
    }
}

double Deanary::stat_st(std::string fio) {
    int num_gr;
    int num_stud;
    for (num_gr = 0; num_gr < groups.size(); num_gr++) {
        for (int num_stud = 0; num_stud < groups[num_gr].students.size(); num_stud++) {
            if (fio == groups[num_gr].students[num_stud]->get_fio()) {
                return groups[num_gr].students[num_stud]->average_mark();
            }
        }
    }
}

double Deanary::stat_gr(std::string spec) {
    int num_gr;
    for (num_gr = 0; num_gr < groups.size(); num_gr++) {
        if (spec == groups[num_gr].get_spec()) {
            return groups[num_gr].average_mark_group();
        }
    }
}

void Deanary::relocat_st(std::string fio, std::string spec) {
    int num_gr;
    int num_stud;
    for (num_gr = 0; num_gr < groups.size(); num_gr++) {
        for (num_stud = 0; num_stud < groups[num_gr].students.size(); num_stud++) {
            if (fio == groups[num_gr].students[num_stud]->get_fio()) {
                for (int i = 0; i < groups.size(); i++) {
                    if (spec == groups[i].get_spec()) {
                        groups[i].add_student(groups[num_gr].students[num_stud]);
                        groups[num_gr].delete_student(groups[num_gr].students[num_stud]);
                    }
                }
            }
        }
    }
}

void Deanary::deduction(std::string fio) {
    int num_gr;
    int num_stud;
    for (num_gr = 0; num_gr < groups.size(); num_gr++) {
        for (num_stud = 0; num_stud < groups[num_gr].students.size(); num_stud++) {
            if (fio == groups[num_gr].students[num_stud]->get_fio()) {
                groups[num_gr].delete_student(groups[num_gr].students[num_stud]);
            }
        }
    }
}

void Deanary::save() {
    int num_gr;
    int num_stud;
    std::ofstream f_groups("groups.txt");
    std::ofstream f_stud("students.txt");
    if ((f_groups.is_open()) && (f_stud.is_open())) {
        for (num_gr = 0; num_gr < groups.size(); num_gr++) {
            f_groups << groups[num_gr].get_spec() << " ";
            f_groups << groups[num_gr].get_title() << "\n";
            for (num_stud = 0; num_stud < groups[num_gr].students.size(); num_stud++) {
                f_stud << groups[num_gr].students[num_stud]->get_fio() << "\n";
            }
        }
    }
    f_groups.close();
    f_stud.close();
}

void Deanary::elections() {
    for (int i = 0; i < groups.size(); i++) {
        groups[i].find_head();
    }
}

void Deanary::output() {
    int num_gr;
    int num_stud;
    for (num_gr = 0; num_gr < groups.size(); num_gr++) {
        std::cout << "Title: " << groups[num_gr].get_title()
            << std::endl;
        std::cout << "Specialty: " << groups[num_gr].get_spec()
            << std::endl;
        std::cout << "Head: " << groups[num_gr].head->get_fio()
            << std::endl;

        for (int num_stud = 0; num_stud < groups[num_gr].students.size(); num_stud++) {
            std::cout << groups[num_gr].students[num_stud]->get_fio()
                << std::endl;
        }
    }
}





