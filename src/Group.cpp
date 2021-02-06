// Copyright 2021 mkhorosh
#include"Group.h"
#include <ctime>

Group::Group(std::string title, std::string spec){
  this->title = title;
  this->spec = spec;
  std::vector<Student*>students={};
  this->students = students;
  this->head = nullptr;
}
double Group::getAverageMark() {
  double ans=0;
  int n = students.size();
  for(int i=0;i<n;i++){
    ans+=students[i]->getAverageMark();
  }
  if(n==0){
    return 0;
  }
  return ans/n;
}
Student *Group::getStudent(const std::string& id) {
  for(auto & student : students){
    if(student->id == id){
      return student;
    }
  }
}
bool Group::isEmpty() {
  return students.empty();
}
void Group::addStudent(Student *new_student) {
  students.push_back(new_student);
}
void Group::chooseHead() {
  srand(time(nullptr));
  int n= this->students.size();
  if(n==0){
    return;
  }
  int pos=rand()%n;
  this->head=students[pos];
}
void Group::removeStudent(const std::string& id) {
  for(int i=0;i<students.size();i++){
    if(students[i]->id == id){
      while(students[i]->isHeadOfGroup()){
        students[i]->group->chooseHead();
      }
      students[i]->addToGroup(nullptr);
      students.erase(students.begin()+i);

      return;
    }
  }
}
