// Copyright 2021 Kasyanov
#ifndef INCLUDE_READGROUP_H_
#define INCLUDE_READGROUP_H_

#include <fstream>
#include <vector>
#include <string>
#include "Student.h"

class ReadGroup {
 private:
  std::vector<std::string> filenames;
 public:
  explicit ReadGroup(std::vector<std::string>);
  std::vector<std::string> GetFileNames() const;
  std::vector<Student*> CreateStudents(Group*, std::string);
  std::vector<Group*> CreateGroups(std::string);
  friend class Deanary;
};




#endif  // INCLUDE_READGROUP_H_
