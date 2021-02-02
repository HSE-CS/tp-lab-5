// Copyright 2021 Smirnov Grigory
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include "Group.h"

class Deanery {
 private:
  std::vector<Group*> groups;
  
 public:
   Deanery();
   void addRandomMarks(int n);

};
#endif  // INCLUDE_DEANARY_H_
