// copyright Toliman 2021

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "../include/Group.h"
#include "../include/Student.h"

class Deanary {
 private:
  std::vector<Group *> groups;
 public:
    static std::vector<Student *> createStudents(int count);

    void createGroup(const std::string &groupFile);

    std::vector<Group *> getGroups();

    static void addMark(Student student, int count);

    void getStats();

    static void changeGroup(Student student, Group group);

    void removeFoolStudents();

    void save();

    void initializeHeadChoose();
};

#endif  // INCLUDE_DEANARY_H_
