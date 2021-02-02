//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Deanary.h"
#include "Group.h"
#include "Student.h"

void Deanary::hireStudents(std::string file_name) {
  std::ifstream infile(file_name);
  int new_ID;
  std::string first_name, last_name;
  while (infile >> first_name >> last_name >> new_ID) {
    std::string new_fio = "" + first_name + " " + last_name;
    Student* new_student = new Student(new_ID, new_fio);
    this->all_students_.push_back(new_student);
  }
}

void Deanary::createGroups(std::string file_name) {
  std::ifstream infile(file_name);
  std::string new_title, new_spec, ids_line;

  while (infile >> new_title >> new_spec){
    getline (infile, ids_line);
    // create group
    Group* new_group = new Group(new_title, new_spec);

    int new_id;
    std::stringstream ss (ids_line);
    // add students by ID
    while (ss >> new_id){
      for (auto& st : this-> all_students_){
        if (st->ID_ == new_id){
          new_group->addStudent(st);
          break;
        }
      }
    }
    this->groups_.push_back(new_group);
  }
}

void Deanary::addMarksToAll(int marks_num, int bias) {
  std::srand(std::time(nullptr));
  for (auto& st : this->all_students_) {
    int target_mark = (std::rand() % bias - 1) + 2;
    for (int i = 0; i < marks_num; i++){
      int offset = std::rand() % 2;
      st->addMark(target_mark - 1 * offset);
    }
  }
}

void Deanary::getStatistics() {
  float avg_mark = 0.0;
  std::cout << " *** DEANARY STATS *** " << std::endl;
  std::cout << "_______________________" << std::endl;
  for (auto& gp : this->groups_) {
    std::cout << "Group '" << gp->title_ << "' in " << gp->spec_ << " specialization :" << std::endl;
    std::cout << " > student number " << gp->students_.size() << std::endl;
    std::cout << " > average mark " << gp->getAverageMark() << std::endl;
    if (gp->head_ != nullptr)
      std::cout << " > head student " << gp->head_->fio_ << std::endl;
    else
      std::cout << " > head student NO_STUDENTS" << std::endl;
    std::cout << std::endl;
    if (gp->getAverageMark() != NULL)
      avg_mark += gp->getAverageMark();
  }
  std::cout << "_____________" << std::endl;
  std::cout << "Common stats:" << std::endl;
  std::cout << " > student number " << this->all_students_.size() << std::endl;
  std::cout << " > group number " << this->groups_.size() << std::endl;
  std::cout << " > average mark " << avg_mark/this->groups_.size() << std::endl;
  std::cout << "_____________" << std::endl << std::endl;
}

void Deanary::moveStudent(Student* student, Group* group) {
  student->group_->removeStudent(student);
  group->addStudent(student);
}

void Deanary::initHeads() {
  std::srand(std::time(nullptr));
  for (auto& gp : this->groups_) {
    if (gp->students_.size() == 0){
      gp->head_ = nullptr;
      continue;
    }
    int head_index = rand() % gp->students_.size();
    gp->head_ = gp->students_[head_index];
  }
}

void Deanary::fireStudent(float min_avg_mark) {
  unsigned students_num = this->all_students_.size();
  for (int i = 0; i < students_num; i++){
    if(this->all_students_[i]->getAverageMark() < min_avg_mark) {
      this->all_students_[i]->group_->removeStudent(this->all_students_[i]);
      if (this->all_students_[i]->isHeadOfGroup()){
        this->all_students_[i]->group_ = nullptr;
        this->initHeads();
      }
      (this->all_students_[i])->~Student();
      this->all_students_.erase(this->all_students_.begin() + i);
      i--;
      students_num--;
    }
  }
}
  
void Deanary::saveStuff(std::string path) {
  std::ofstream out;
  std::ofstream out2;
  // Students
  out.open(path + "newStudents.txt");
  out2.open(path + "newStudentsMarks.txt");
  if (out.is_open() && out2.is_open()) {
    for (auto& st : this->all_students_) {
      out << st->fio_ << " " << st->ID_ << std::endl;
      out2 << st->fio_ << " " << st->ID_ << " : ";
      for (auto& mark : st->marks_)
        out2 << mark << " ";
      out2 << std::endl;
    }
  }
  out.close();
  out2.close();
  // Groups
  out.open(path + "newGroups.txt");
  if (out.is_open()) {
    for (auto& gp : this->groups_){
      out << gp->title_ << " " << gp->spec_;
      for (auto st : gp->students_)
        out << " " << st->ID_;
      out << std::endl;
    }
  }
  out.close();
}

Group Deanary::getGroup(int index, std::string title) const {
  if (index == -1 && title == "")
     throw std::invalid_argument("no arguments");
  
  Group* obj_of_copy = nullptr;
  if (index != -1 && index < this->groups_.size()) {
        obj_of_copy = this->groups_[index];
  } else {
    for (auto& gp : this->groups_){
      if (gp->title_ == title){
        obj_of_copy = gp;
        break;
      }
    }
  }
  
  if (obj_of_copy == nullptr)
     throw std::invalid_argument("no such group in deanary");

  Group copy (*(obj_of_copy));
  return copy;
}
