#include "Group.h"

#include <iostream>
#include <string>
#include <vector>

Group::Group(std::string tl, std::string sp) {
  title = tl;
  spec = sp;
  head = NULL;
}

void Group::addStudent(Student* person) { students.push_back(person); }

Student* Group::chooseHead() {
  Student* head = getStudent(0);
  head->isHead = true;
  return head;
}

void Group::removeStudent(int id) {
  for (int i = 0; i < students.size(); ++i) {
    if (students[i]->id == id) students.erase(students.begin() + i);
  }
}

float Group::getAveragemark() {
  float summ = 0;
  for (auto person : students) summ += person->getAveragemark();
  return summ / students.size();
}

Student* Group::getStudent(int id) { return students[id]; }

Student* Group::getStudent(std::string) {
  return NULL;  // idk smth with files
}

bool Group::isEmpty() { return students.empty(); }
