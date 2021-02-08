// Copyright 2021 idpas	
#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
#include "Deanary.h"
#include "Group.h"
#include "Student.h"

Group::Group() {
  this->title = "";
  this->spec = "";
  this->head = nullptr;
}

Group::Group(std::string title) {
  this->title = title;
  this->spec = "";
  this->head = nullptr;
}

void Group::AddStudent(Student* student) {
	this->students.push_back(student);
}

void Group::ChooseHead() {
  int amount = this->students.size();
  if (amount) {
    int head_i = std::rand() % amount;
    this->head = this->students.at(head_i);
  }
}

int Group::GetAvarageMark() {
  int amount = this->students.size();
  float sum = 0;
  for (int i = 0; i < amount; i++) {
    sum += this->students.at(i)->GetAverageMark();
  }
  return sum / amount;
}

Student* Group::GetStudent_id(int id) {
  int size = this->students.size();
  if (!size) {
    return NULL;
  }
  else {
    for (int i = 0; i < size; i++) {
      if (this->students.at(i)->get_id() == id) {
        return this->students.at(i);
        break;
      }
    }
  }
  return nullptr;
}

Student* Group::GetStudent_fio(std::string fio) {
  int amount = this->students.size();
  int i = 0;
  for (; i < amount; i++) {
    if (this->students.at(i)->getFio() == fio) {
      return this->students.at(i);
      break;
    }
  }
}

void Group::RemoveStudent_id(int id) {
  int amount = this->students.size();
  for (int i = 0; i < amount; i++) {
    if (this->students.at(i)->get_id() == id) {
      this->students.erase(this->students.begin() + i);
      break;
    }
  }
}

void Group::RemoveStudent_fio(std::string fio) {
  unsigned number_of_students = this->students.size();
  for (unsigned i = 0; i < number_of_students; i++) {
    if (this->students.at(i)->getFio() == fio) {
      this->students.erase(this->students.begin() + i);
      break;
    }
  }
}


