// Copyright 2021 mkhorosh
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include<vector>
#include<string>

#include"Student.h"

class Group{
 private:
  std::string title;
  std::string spec;
  std::vector<Student*>students;
  Student* head;

 public:
  Group(std::string title){
    this->title = title;
    this->spec = "";
//    this->students = NULL;
    this->head = NULL;
  }
};

#endif  // INCLUDE_GROUP_H_
