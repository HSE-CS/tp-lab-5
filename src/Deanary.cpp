// Copyright 2021 Egor Trukhin
#include "Deanary.h"

Deanary::Deanary(const char* filename_groups, const char* filename_students) {
  // Read groups
  std::ifstream ifgroups(filename_groups);
  if (!ifgroups.is_open())
    throw std::runtime_error("Input file is not opened!");
  std::vector<std::string> groups_info;
  while (!ifgroups.eof()) {
    std::string line;
    std::getline(ifgroups, line);
    if (line.length() < 2) continue;
    groups_info.push_back(line);
  }
  ifgroups.close();

  // Read students
  std::ifstream ifstudents(filename_students);
  if (!ifstudents.is_open())
    throw std::runtime_error("Input file is not opened!");
  std::vector<std::string> students_info;
  while (!ifstudents.eof()) {
    std::string line;
    std::getline(ifstudents, line);
    if (line.length() < 2) continue;
    students_info.push_back(line);
  }
  ifstudents.close();

  // Init groups and students
  createGroups(groups_info);
  hireStudents(students_info);
}

Deanary::~Deanary() {
  for (auto group : groups) {
    for (auto student : group->getStudents()) delete student;
    delete group;
  }
}

// INPUT: vector < "NAME GROUP_TITLE" >
void Deanary::hireStudents(const std::vector<std::string>& students_info) {
  for (auto student_info : students_info) {
    std::istringstream info(student_info);
    std::string name, name1, name2, group_title;
    info >> name >> name1 >> name2 >> group_title;
    name += " " + name1;
    name += " " + name2;

    for (auto group : groups)
      if (group->getTitle() == group_title) {
        group->addStudent(new Student(students_counter++, name));
        break;
      }
  }
}

// INPUT: vector < "GROUP_TITLE SPEC" >
void Deanary::createGroups(const std::vector<std::string>& groups_info) {
  for (auto group_info : groups_info) {
    std::istringstream info(group_info);
    std::string group_title, group_spec;
    info >> group_title >> group_spec;
    groups.push_back(new Group(group_title, group_spec));
  }
}

//======================================================================
// Setters

void Deanary::setRandomMarks(uint32_t count) {
  for (auto group : groups)
    for (auto student : group->getStudents())
      for (uint8_t i = 0; i < count; ++i) student->addMark(rand() % 11);
}

void Deanary::setHeads() {
  for (auto group : groups) group->setHead();
}

//======================================================================
// Changers

void Deanary::fireStudents() {
  std::vector<Student*> fire_list;
  for (auto group : groups)
    for (auto student : group->getStudents())
      if (student->getMeanMark() < group->getMeanMark())
        fire_list.push_back(student);
  fireStudents(fire_list);
}

void Deanary::fireStudents(double min_mark) {
  std::vector<Student*> fire_list;
  for (auto group : groups)
    for (auto student : group->getStudents())
      if (student->getMeanMark() < min_mark) fire_list.push_back(student);
  fireStudents(fire_list);
}

void Deanary::fireStudents(const std::vector<Student*>& fire_list) {
  for (auto student : fire_list)
    for (auto group : groups)
      if (group == student->getGroup()) {
        group->removeStudent(student);
        students_counter--;
        delete student;
        break;
      }
}

void Deanary::moveStudents(const std::vector<Student*>& move_list,
                           Group* new_group) {
  for (auto student : move_list)
    for (auto group : groups)
      if (group == student->getGroup()) {
        group->removeStudent(student);
        new_group->addStudent(student);
        break;
      }
}

//======================================================================
// Getters

const std::vector<Group*>& Deanary::getGroups() const { return groups; }

Group* Deanary::getGroup(const std::string& title) {
  for (auto group : groups)
    if (group->getTitle() == title) return group;
}

std::string Deanary::getInfo() const {
  std::string info;
  info += "Deanary:\n";
  info += "  Count of students: " + std::to_string(students_counter - 1) + "\n";
  info += "  Count of groups: " + std::to_string(groups.size()) + "\n";
  info += "  Groups: ";
  if (groups.size() == 0)
    info += "< Empty > ";
  else
    for (auto group : groups)
      info += "\n\t" + group->getTitle() + " (" +
              std::to_string(group->getStudents().size()) + ")";
  info += "\n";
  return info;
}

//======================================================================

void Deanary::saveData(const char* filename_groups,
                       const char* filename_students) {
  // Write groups
  std::ofstream ofgroups(filename_groups);
  if (!ofgroups.is_open())
    throw std::runtime_error("Output file is not opened!");

  for (auto group : groups)
    if (group->getStudents().size() != 0)
      ofgroups << group->getTitle() << " " << group->getSpec() << "\n";

  ofgroups.close();

  // Write students
  std::ofstream ofstudents(filename_students);
  if (!ofstudents.is_open())
    throw std::runtime_error("Output file is not opened!");

  for (auto group : groups)
    if (group->getStudents().size() != 0)
      for (auto student : group->getStudents())
        ofstudents << student->getName() << " " << group->getTitle() << "\n";
  ofstudents.close();
}
