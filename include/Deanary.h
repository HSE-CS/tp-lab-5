//
// Created by mushka on 19.03.2021.
//

#ifndef TP_LAB_5_DEANARY_H
#define TP_LAB_5_DEANARY_H

#include "Group.h"
#include "Student.h"
#include <iostream>
#include <vector>

using namespace std;


class Deanary {
private:
    int studentsNum = 0;
    std::vector<Group*> groups;

public:
    void CreateGroup(std::string title, std::string spec);
    void CreateStudent(std::string fio, Group* group);
    Group* GroupByTitle(const std::string& groupName);
    bool createGroupsFromFile(const std::string& path);
    bool createStudentsFromFile(std::string path);
    void addRandomMarks();
    std::string getStatistics();
    void moveStudent(Student* student, Group* new_group);
    void kickStudentsForBadMarks(float BadMark);
    bool saveToFile(std::string path);
    void initHeads();
};


#endif //TP_LAB_5_DEANARY_H
