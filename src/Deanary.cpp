//
//  Deanary.cpp
//  tp-lab-5
//
//  Created by Anastasiya Rogozyan on 03.03.2021.
//  Copyright © 2021 Anastasiya Rogozyan. All rights reserved.
//
 #include <string>
 #include <iostream>
 #include <fstream>
 #include "Deanary.h"

 void Deanary::student_hire(Student* student, std::string prog) {
     for (size_t i = 0; i < groups.size(); i++) {
         if (groups[i].get_spec() == prog)
             groups[i].student_add(student);
     }
 }

 void Deanary::student_reading() {
     std::ifstream fin("students.txt");
     std::string FIO;
     int ID = 1;
     while (getline(fin, FIO)) {
         Student new_men(ID, FIO);
         Students.push_back(new_men);
         ID++;
     }
 }

 void Deanary::student_distribution() {
     for (int i = 0; i < Students.size(); i++) {
         int number = std::rand() % groups.size();
         groups[number].student_add(&Students[i]);
     }
 }

 double Deanary::student_statistic(std::string FIO) {
     for (size_t i = 0; i < groups.size(); i++) {
         for (size_t j = 0; j < groups[i].students.size(); j++) {
             if (groups[i].students[j]->student_FIO() == FIO)
                 return groups[i].students[j]->student_mark_avarage();
         }
     }
 }

 void Deanary::student_moving(std::string FIO, std::string programm) {
     for (size_t i = 0; i < groups.size(); i++) {
         for (size_t j = 0; j < groups[i].students.size(); j++) {
             if (groups[i].students[j]->student_FIO() == FIO) {
                 for (size_t k = 0; k < groups.size(); k++) {
                     if (groups[k].get_spec() == programm) {
                         groups[k].student_add(groups[i].students[j]);
                         groups[i].student_remove(groups[i].students[j]);
                     }
                 }
             }
         }
     }
 }

 void Deanary::student_expulsion(std::string FIO) {
     for (size_t i = 0; i < groups.size(); i++) {
         for (size_t j = 0; j < groups[i].students.size(); j++) {
             if (groups[i].students[j]->student_FIO() == FIO)
                 groups[i].student_remove(groups[i].students[j]);
         }
     }
 }

 void Deanary::student_head() {
     for (size_t i = 0; i < groups.size(); i++) {
         groups[i].student_choice_head();
     }
 }

 void Deanary::marks_adding() {
     for (size_t i = 0; i < groups.size(); i++) {
         for (size_t j = 0; j < groups[i].students.size(); j++) {
             for (size_t num = 0; num < 10; num++) {
                 groups[i].students[j]->add_mark(std::rand() % 10 + 1);
             }
         }
     }
 }

 void Deanary::group_adding(Group group) {
     groups.push_back(group);
 }

 void Deanary::group_reading() {
     std::ifstream fin("groups.txt");
     std::string programm;
     std::string name;
     while (getline(fin, programm)) {
         getline(fin, name);
         Group new_group(name, programm);
         groups.push_back(new_group);
     }
 }

 double Deanary::group_statistic(std::string programm) {
     for (size_t i = 0; i < groups.size(); i++) {
         if (groups[i].get_spec() == programm) {
             return groups[i].mark_avarage();
         }
     }
 }

 void Deanary::information_save() {
     std::ofstream fout;
     fout.open("output.txt");
     for (size_t i = 0; i < groups.size(); i++) {
         fout << groups[i].get_spec() << std::endl;
         for (size_t j = 0; j < groups[i].students.size(); j++) {
             fout << groups[i].students[j]->student_FIO() << std::endl;
         }
     }
     fout.close();
 }

 void Deanary::print() {
     for (int i = 0; i < groups.size(); i++) {
         std::cout << "The programm is " << groups[i].get_spec() << std::endl;
         std::cout << "The name of group is "
             << groups[i].get_title() << std::endl;
         std::cout << "Head is " << groups[i].head->student_FIO() << std::endl;
         std::cout << "-------------list-----------------" << std::endl;
         for (int j = 0; j < groups[i].students.size(); j++) {
             std::cout << groups[i].students[j]->student_FIO() << std::endl;
         }
         std::cout << std::endl;
     }
 }
