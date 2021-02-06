// Copyright 2021 Egor Trukhin
#include "Group.h"

Group::Group(const std::string& title, const std::string& spec) {
  this->title = title;
  this->spec = spec;
  this->head = nullptr;
}

//======================================================================
// Setters

void Group::setStudents(const std::vector<Student*>& students) {
  this->students = students;
}

void Group::setDeanary(Deanary* deanary) { this->deanary = deanary; }

void Group::setHead() {
  if (students.size() == 0) return;
  double best_mean_mark = 0.0;
  for (auto student : students) {
    double current_mean_mark = student->getMeanMark();
    if (best_mean_mark <= current_mean_mark) {
      best_mean_mark = current_mean_mark;
      head = student;
    }
  }
}

//======================================================================
// Changers

void Group::addStudent(Student& student) {
  if (student.getGroup() != nullptr) return;
  students.push_back(&student);
  student.setGroup(this);
}

void Group::addStudent(Student* student) {
  if (student->getGroup() != nullptr) return;
  students.push_back(student);
  student->setGroup(this);
}

void Group::removeStudent(const Student* student) {
  if (student->getGroup() != this) return;
  for (size_t pos = 0; pos < students.size(); pos++)
    if (students[pos] == student) {
      if (students[pos] == head) head = nullptr;
      students[pos]->setGroup(nullptr);
      students.erase(students.begin() + pos);
      return;
    }
}

void Group::removeStudent(const Student& student) {
  if (student.getGroup() != this) return;
  for (size_t pos = 0; pos < students.size(); pos++)
    if (*students[pos] == student) {
      if (students[pos] == head) head = nullptr;
      students[pos]->setGroup(nullptr);
      students.erase(students.begin() + pos);
      return;
    }
}

void Group::removeStudent(uint32_t id) { removeStudent(getStudent(id)); }
void Group::removeStudent(const std::string& name) {
  removeStudent(getStudent(name));
}

//======================================================================
// Getters

const std::string& Group::getTitle() const { return title; }

const std::string& Group::getSpec() const { return spec; }

const std::vector<Student*>& Group::getStudents() const { return students; }

const Student* Group::getStudent(uint32_t id) const {
  for (auto student : students)
    if (student->getId() == id) return student;
  return nullptr;
}

const Student* Group::getStudent(const std::string& name) const {
  for (auto student : students)
    if (student->getName() == name) return student;
  return nullptr;
}

const Deanary* Group::getDeanary() const { return deanary; }

const Student* Group::getHead() const { return head; }

double Group::getMeanMark() const {
  if (students.size() == 0) return 0;
  double sum = 0.0;
  for (auto student : students) sum += student->getMeanMark();
  return sum / static_cast<double>(students.size());
}

std::string Group::getInfo() const {
  std::string info;
  info += "Group \"" + title + "\":\n";
  info += "  Specialty: " + std::string(spec.c_str()) + "\n";
  info += "  Count of students: " + std::to_string(students.size()) + "\n";
  info += "  Group mean mark: " + std::to_string(getMeanMark()) + "\n";
  info += "  Head: ";
  info += (head != nullptr) ? head->getName() + "\n" : "< None >\n";
  info += "  Students: ";
  if (students.size() == 0)
    info += "< Empty > ";
  else
    for (auto student : students)
      info += "\n\t" + std::to_string(student->getId()) + " : " +
              student->getName();
  info += "\n";
  return info;
}

//======================================================================
// Operators

bool Group::operator==(const Group& other) {
  return (this->spec == other.spec && this->title == other.title);
}
