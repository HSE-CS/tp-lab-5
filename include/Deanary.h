// Copyright Mushka Nikita, 2021

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include "Group.h"
#include "Student.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

class Deanary {
private:
    std::vector<Group *> groups;

public:
    void CreateGroup(std::string title, std::string spec);

    static void CreateStudent(int new_id, std::string fio, Group *group);

    Group *GroupByTitle(const std::string &groupName);

    void FillMarks();

    std::string GetStats();

    static void MoveStudent(Student *student, Group *new_group);

    void RemoveFailingStudents();

    bool File_CreateGroups(const std::string &path);

    bool File_CreateStudents(const std::string &path);

    bool File_SaveDeanary(std::string path);

    void ChooseLeaders();
};


#endif  // INCLUDE_DEANARY_H_
