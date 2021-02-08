// Copyright 2021 idpas
#include "Student.h"
#include <iostream>
#include <string>
#include <vector>
#include "Deanary.h"
#include "Group.h"
#include "Student.h"

Student::Student() {
  this->id = 0;
  this->fio = "";
  this->group = nullptr;
}

Student::Student(int id, std::string fio) {
  this->id = id;
  this->fio = fio;
}

void Student::AddToGroup(Group* group) {
	this->group = group;
}

void Student::AddMark(int mark) {
	this->marks.push_back(mark);
}

float Student::GetAverageMark() {
  int amount = this->marks.size();
  float sum = 0;
  for (unsigned i = 0; i < amount; i++) {
    sum += this->marks.at(i);
  }
  return sum / amount;
}

bool Student::IsHeadOfGroup() {
  return this->group != NULL;
}

int Student::get_id() {
	return this->id;
}

std::string Student::get_fio() {
	return this->fio;
}
	