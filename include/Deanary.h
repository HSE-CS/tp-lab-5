// Copyright 2021 Shatilov Victor

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include <vector>
#include <fstream>
#include <string>
#include "Group.h"
#include "Student.h"


class Deanary {
 private:
    int studentsId = 1;
    std::vector<Group*> groups;

 public:
    void createGroup(std::string title, std::string spec);
    void createStudent(std::string fio, Group* group);
    Group* getGroupByTitle(const std::string& groupName);
    bool createGroupsFromFile(const std::string& path);
    bool createStudentsFromFile(std::string path);
    void addRandomMarks();
    std::string getStatistics();
    void moveStudent(Student* student, Group* new_group);
    void kickStudentsForBadMarks(float BadMark);
    bool saveToFile(std::string path);
    void initHeads();
};


#endif  // INCLUDE_DEANARY_H_
