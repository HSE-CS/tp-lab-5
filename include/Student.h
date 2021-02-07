//Copyright 2021 Sozinov Kirill
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>
#include "Group.h"

class Student {
    friend class Group;
    friend class Deanery;
 private:
     size_t id;
     std::string fio;
     Group *group;
     std::vector <size_t> marks;
     void addToGroup(Group *group);
     void addmark(size_t mark);
     std::string getFIO();
     unsigned getID();
     bool isHead = false;
     Group *getGroup();
 public:
    Student(unsigned id, std::string fio);
    ~Student();
    bool isHeadOfGroup();
    double getAverageMark();
    
};


#endif  // INCLUDE_STUDENT_H_
