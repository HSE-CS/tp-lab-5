// Copyright 2021 Tatsenko Ilya
#include <iostream>
#include<vector>
#include "Group.h"


std::string Group::GetTitle() { return this->title; }
std::string Group :: GetSpec() { return this->spec; }

std::string Group::GetHeader() {
        return this->head->GetFi();
    }
std::string Group::GetLastStudents() {
    if (students[students.size() - 1] == nullptr) return "ERROR";
    return (this->students[students.size() -1]->GetFi());
}

void Group::AddStudent(Student* student) {
    this->students.push_back(student);
    student->AddToGroup(this);
}

void Group::ChooseHeader(Student* student) {
    head = student;
}

Student* Group::GetStudent(std::string name_id) {
    for (auto & student : students) {
        if (student->fi == name_id || student->id == name_id) {
            return student;
        }
    }
}

double Group::GetAvarageEval() {
    double sum = 0;
    int k = 0;
    for (auto &student : students) {
      sum += student->GetAvarageEval();
      k++;
    }
    return sum / k;
}

void Group::RemoveStudent(Student* stud) {
  if (this->head == stud) {
    this->head = nullptr;
  }
  int k = 0;
    for (auto &student : students) {
        if (student->id == stud->id && student->fi == stud->fi) {
            students.erase(students.begin() + k);
            break;
        }
        k++;
    }
}
