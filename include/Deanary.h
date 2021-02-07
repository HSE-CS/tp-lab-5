// Copyright 2021 Kasyanov
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include "ReadGroup.h"

class Deanary {
 private:
  std::vector<Group*> groups;

 public:
  Deanary(ReadGroup&, std::string);
  void AddMarksToAll(int);
  void GetStatistics() const;
  void MoveStudent(int, std::string);
  void SaveStaff(const ReadGroup&) const;
  void InitHead();
  void FireStudent(int);
  Group* GetGroup(std::string);
  void HireStudent(int, std::string, std::string, ABILITY);
};

#endif  // INCLUDE_DEANARY_H_
