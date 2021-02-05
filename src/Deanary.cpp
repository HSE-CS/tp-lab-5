//  Copyright 2020 Baklanov

#include "Deanary.h"
#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>

int id = 0;

int markGetToInt(std::string mark) {
 int intmark = 0;
 for (int i = 0; i < mark.length(); ++i) {
  intmark += (static_cast<int>(mark[i]) - 48) * pow(10, mark.length() - i - 1);
 }
 return intmark;
}

void Deanary::createGroups(std::string path) {
 std::ifstream fin;
 Group bufGroup("something", "something");
 bufGroup.students.reserve(10);
 fin.open(path);
 if (!fin.is_open())
  return;
 std::string buffer;
 std::getline(fin, buffer);
 while (buffer != "") {
  bufGroup.title = buffer;
  std::getline(fin, buffer);
  bufGroup.spec = buffer;
  buffer = "♣-♣♣-☼♫";
  bufGroup.acadPerform = rand() % 3 + 1;
  this->groups.push_back(bufGroup);
  std::getline(fin, buffer);
  std::getline(fin, buffer);
 }
}


void Deanary::hireStudents(std::string path) {
 int number = 0;
 int studentPerform = 0;
 std::ifstream fin;
 fin.open(path);
 if (!fin.is_open()) {
  return;
 }
 std::string buffer;
 getline(fin, buffer);
 while (!fin.eof()) {
  if (buffer == "") {
   getline(fin, buffer);
   continue;
  }
  ++id;
  switch (groups[number].acadPerform) {
   case(1):
   studentPerform = rand() % 3 + 1;
   break;
   case(2):
   studentPerform = rand() % 4 + 1;
   break;
   case(3):
   studentPerform = rand() % 4 + 2;
   break;
  }
  auto* s = new Student(id, buffer, &groups[number], studentPerform);
  groups[number].addStudent(s);
  getline(fin, buffer);
  if (buffer[7]) {
   int i = 7;
   std::string mark;
   while(i < buffer.length()) {
    while ((buffer[i] != ' ') && (i < buffer.length())) {
     mark.push_back(buffer[i]);
     ++i;
    }
    int markInt = markGetToInt(mark);
    groups[number].students[groups[number].
    students.size() - 1]->addmark(markInt);
    mark.clear();
    ++i;
   }
  }
  getline(fin, buffer);
  if (buffer == "") {
   getline(fin, buffer);
   ++number;
  }
 }
}

void Deanary::addMarksToAll() {
 int mount = 0;
 for (Group g : groups) {
  for (int j = 0; j < g.students.size(); ++j) {
   mount = rand() % 5 + 2;
   for (int k = 0; k < mount; ++k) {
    g.students[j]->addmark(rand() % 11);
   }
  }
 }
}

double Deanary::getStatistics() {
 double sum = 0;
 int mount = 0;
 for (int i = 0; i < this->groups.size(); ++i) {
  if (groups[i].getAveragemark()) {
   if (groups[i].getAveragemark()) {
    sum += groups[i].getAveragemark();
    ++mount;
   }
  }
 }
 if (mount == 0) {
  return 0;
 }
 return sum / mount;
}



void Deanary::moveStudents() {
 int number1, number2;
 int numIntel;
 std::string studentnumber = 0;
 std::cin >> number1 >> number2;
 Group* from = &groups[number1 - 1];
 Group* to = &groups[number2 - 1];
 std::cin >> studentnumber;
 Student* a = from->getStudent(studentnumber);
 if (a == NULL)
  return;
 if (a->intel == "low") {
  numIntel = 1;
 } else if (a->intel == "average") {
    numIntel = 2;
 } else {
    numIntel = 4;
 }
 Student* buf = new Student(a->id, a->fio, a->group, numIntel);
 buf->isHead = a->isHead;
 from->removeStudent(a);
 to->addStudent(buf);
 std::cout << buf->fio << std::endl;
}

void Deanary::initHeads() {
 for (Group g : groups) {
  int choise = rand() % g.students.size();
  g.chooseHead(choise);
 }
}

void Deanary::fireStudents(int number) {
 std::string studentnumber;
 std::cin >> studentnumber;
 Student *a = groups[number - 1].getStudent(studentnumber);
 if (a == NULL)
  return;
 groups[number - 1].removeStudent(a);
}

void Deanary::saveStaff(std::string pathGroup, std::string pathStudent) {
 std::ofstream foutGr, foutSt;
 foutGr.open(pathGroup);
 if (!foutGr.is_open()) {
  std::cout << "Can't open file" << std::endl;
  return;
 }
 std::string buffer;
 for (Group g : groups) {
  foutGr << g.title << std::endl << g.spec << "\n\n";
 }
 foutGr.close();
 foutSt.open(pathStudent);
 if (!foutSt.is_open()) {
  std::cout << "Can't open file" << std::endl;
  return;
 }
 for (Group g : groups) {
  for (Student* s : g.students) {
   foutSt << s->fio << std::endl << "marks: ";
   for (int mark : s->marks) {
    foutSt << mark << " ";
   }
   foutSt << std::endl;
  }
  foutSt << std::endl;
 }
 foutSt << std::endl;
}
