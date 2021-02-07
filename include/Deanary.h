// Copyright 2021 Shatilov Victor

#ifndef INCLUDE_DEANARY_H
#define INCLUDE_DEANARY_H
#include <vector>
#include "Group.h"

class Deanary {
 private:
    std::vector<Group*> groups;
 public:
    void createGroupsFromFile(std::string path);
    void createStudentsFromFile(std::string path);
    void addRandomMarks();
    std::string getStatistics();
    void moveStudent(Student* student, Group* new_group);
    void kickStudentsForBadMarks(int BadMark);
    void saveToFile(std::string path);
    void initHeads();
};


#endif //INCLUDE_DEANARY_H
