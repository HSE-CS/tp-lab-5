// Copyright 2021 Egor Trukhin
#include "Student.h"

Student::Student(uint32_t id, const std::string& name, Group* group) {
  this->id = id;
  this->name = std::string(name);
  this->group = group;
}

Student::Student(const Student& other) {
  this->id = other.id;
  this->name = std::string(other.name);
  this->group = other.group;
  this->marks.resize(other.marks.size());
  std::copy(other.marks.begin(), other.marks.end(), this->marks.begin());
}

//======================================================================
// Setters

void Student::setGroup(Group* group) { this->group = group; }

void Student::addMark(uint8_t mark) { this->marks.push_back(mark); }

//======================================================================
// Getters

uint32_t Student::getId() const { return id; }

const std::string& Student::getName() const { return name; }

const std::vector<uint8_t>& Student::getMarks() const { return marks; }

const Group* Student::getGroup() const { return group; }

double Student::getMeanMark() const {
  if (marks.size() == 0) return 0;
  double sum = 0.0;
  for (auto mark : marks) sum += static_cast<double>(mark);
  return sum / static_cast<double>(marks.size());
}

std::string Student::getInfo() const {
  std::string info;
  info += "Student #" + std::to_string(id) + "\n";
  info += "  Name: " + name + "\n";
  info += "  Count of marks: " + std::to_string(marks.size()) + "\n";
  info += "  Mean mark: " + std::to_string(getMeanMark()) + "\n";
  info += "  Marks: ";
  if (marks.size() == 0)
    info += "< Empty >";
  else
    for (auto mark : marks) info += std::to_string(mark) + " ";
  info += "\n";
  return info;
}

//======================================================================
// Operators

bool Student::operator==(const Student& other) { return this->id == other.id; }
