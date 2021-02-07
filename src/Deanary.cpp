//  Copyright 2021 Nikita Naumov
#include "Deanary.h"
#include "Student.h"
#include "Group.h"

std::string getFileName() {
  std::cout << "Please, print file name (Without spaces and with extencion)\n";
  std::string fileName;
  std::cin >> fileName;
  return fileName;
}

Deanary::Deanary() {
  this->numberOfStudents = 0;
  this->allStudents.clear();
  this->groups.clear();
}
Deanary::~Deanary() {
  this->allStudents.clear();
  this->groups.clear();
}
void Deanary::createGroups() {
  std::string fileName;
  fileName = getFileName();
  std::ifstream FileIn;
  FileIn.open(fileName);
  if (!FileIn.is_open()) {
    std::cout << "File isn't open" << std::endl;
    throw -1;
  }
  std::string groupName;
  std::string groupSpec;
  while (!FileIn.eof()) {
    FileIn >> groupName >> groupSpec;
    Group* group = new Group(groupName);
    (*group).spec = groupSpec;
    (this->groups).push_back(&(*group));
  }
  FileIn.close();
}
void Deanary::addStudentToRandomGroup(Student* studentToAdd) {
    unsigned groupNum = rand() % (this->groups).size();
    int minSize = INT_MAX;
    int minInd = INT_MAX;
    if ((this->groups[groupNum])->students.size() < 31) {
      (this->groups[groupNum])->addStudentToGroup(studentToAdd);
    } else {
      for (size_t i = 0; i < this->groups.size(); ++i) {
        if ((this->groups[i])->students.size() < minSize) {
          minInd = i;
          minSize = (this->groups[i])->students.size();
        }
      }
      (this->groups[minInd])->addStudentToGroup(studentToAdd);
    }
}
void Deanary::initialiseStudents() {
  std::string fileName;
  fileName = getFileName();
  std::ifstream FileIn;
  FileIn.open(fileName);
  if (!FileIn.is_open()) {
    std::cout << "File isn't open" << std::endl;
    throw -1;
  }
  std::string studentNameAndSurname;
  std::string studentNameAndSurname2;
  while (!FileIn.eof()) {
    FileIn >> studentNameAndSurname;
    studentNameAndSurname += " ";
    FileIn >> studentNameAndSurname2;
    studentNameAndSurname += studentNameAndSurname2;
    Student* studentToAdd = new Student(this->numberOfStudents, studentNameAndSurname);
    (this->allStudents).push_back(&(*studentToAdd));
    addStudentToRandomGroup(&(*studentToAdd));
    studentNameAndSurname.clear();
    (this->numberOfStudents) += 1;
  }
  FileIn.close();
}
void Deanary::addRandomMarks(Student* studentToAdd, int quantity) {
  for (size_t i = 0; i < quantity; ++i) {
    (*studentToAdd).addMarkToStudent(rand() % 11);
  }
}
double Deanary::getStudentStatistic(Student* student) {
  return (*student).getAverageMark();
}
double Deanary::getGroupStatistic(Group* group) {
  return (*group).getAverageGroupMark();
}
void Deanary::moveStudent(Student* studentToMove, Group* destination) {
  Group* source = (*studentToMove).group;
  if (source == destination) {
    std::cout << "Student is already in destination group!\n";
    return;
  }
  source->fireStudentFromGroup((*studentToMove).id);
  destination->addStudentToGroup(studentToMove);
}
void Deanary::fireForAcademicFailure() {
  double averageMark = 0;
  for (size_t i = 0; i < allStudents.size(); ++i) {
    averageMark = (this->allStudents[i])->getAverageMark();
    if (averageMark < 3.5) {
      unsigned currId = (this->allStudents[i])->id;
      Group* currGroup = (this->allStudents[i])->group;
      currGroup->fireStudentFromGroup(currId);
      (this->allStudents).erase(allStudents.begin() + i);
      i = 0;
    }
  }
}
void Deanary::initialiseElection() {
  for (size_t i = 0; i < (this->groups).size(); ++i) {
    if ((this->groups[i])->students.size() != 0) {
      unsigned newHead = rand() % ((this->groups[i])->students.size());
      (this->groups[i])->setHead((this->groups[i])->students[newHead]);
    }
  }
}
void Deanary::printAllInfo() {
  std::cout << "Information about groups" << std::endl;
  for (size_t i = 0; i < (this->groups).size(); ++i) {
    std::cout << "==========================================" << std::endl;
    (this->groups[i])->printInfoAboutGroup();
    std::cout << std::endl;
  }
  std::cout << "Information about students" << std::endl;
  for (size_t i = 0; i < (this->allStudents).size(); ++i) {
    std::cout << "==========================================" << std::endl;
    (this->allStudents[i])->printInfoAboutStudent();
    std::cout << std::endl;
  }
}
void Deanary::saveChanges() {
  std::string fileName = getFileName();
  std::ofstream FileOut;
  FileOut.open(fileName);
  if (!FileOut.is_open()) {
    std::cout << "File isn't open" << std::endl;
    throw -1;
  }
  FileOut.clear();
  FileOut << "Student's name and surname\t"
          << "Student's ID\t"
          << "Student's group\t"
          << "Average mark\t"
          << "Is student head of group?\n";
  for (size_t i = 0; i < (this->allStudents).size(); ++i) {
    FileOut << (this->allStudents[i])->fio << "\t" 
            << (this->allStudents[i])->id << "\t" 
            << ((this->allStudents[i])->group)->getTitle() << "\t"
            << (this->allStudents[i])->getAverageMark() << "\t";
    if ((this)->allStudents[i]->isHead) {
      FileOut << "True" << "\n";
    } else {
      FileOut << "False" << "\n";
    }
  }
}
double Deanary::getCurrentAmountOfStudents() {
  return ((this->allStudents).size());
}
double Deanary::getCurrentAmoutOfGroups() { return ((this->groups).size()); }
Student* Deanary::getStudentAddress(unsigned index) {
  return (this->allStudents[index]);
}
Group* Deanary::getGroupAddress(unsigned index) {
    return (this->groups[index]); 
}
void Deanary::addStudent(Student* StudentObj) {
  this->allStudents.push_back(StudentObj);
}
void Deanary::addGroup(Group* GroupObj) {
    this->groups.push_back(GroupObj); 
}
void Deanary::addStudentToGroup(Student* StudentObj, Group* GroupObj) {
  GroupObj->addStudentToGroup(StudentObj);
}