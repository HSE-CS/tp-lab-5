// Copyright 2021 Kasyanov
#include "../include/Deanary.h"

ReadGroup::ReadGroup(std::vector<std::string> _filenames) {
  filenames = _filenames;
}

std::vector<Student*> ReadGroup::CreateStudents(Group* group,
                                                std::string filename) {
  std::ifstream input(filename);
  int student_id = 0;
  std::vector<Student*> res;
  while (input >> student_id) {
    std::string name;
    std::string tmp;
    input >> tmp;
    name += (tmp + " ");
    input >> tmp;
    name += (tmp + " ");
    input >> tmp;
    name += tmp;
    Student* st = new Student(student_id, name, group);
    res.push_back(st);
  }
  return res;
}

std::vector<Group*> ReadGroup::CreateGroups(std::string spec) {
  std::vector<Group*> groups;
  std::string group_name = "Group 1";
  for (int i = 0; i < filenames.size(); ++i) {
    group_name.pop_back();
    group_name += ((i + 1) + '0');
    Group* group = new Group(group_name, spec);
    group->students = CreateStudents(group, filenames[i]);
    groups.push_back(group);
  }
  return groups;
}

std::vector<std::string> ReadGroup::GetFileNames() const { return filenames; }
