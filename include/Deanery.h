// Copyright [2021] <Ziganshin Nikita>
#ifndef INCLUDE_DEANERY_H_
#define INCLUDE_DEANERY_H_

#include "Group.h"
#include <fstream>
#include <vector>

class Deanery {
 private:
    std::vector<Group> groups;
 public:
    void CreateStudentsFromFile();

    [[nodiscard]] std::vector<Group> *getGroups();

    void CreateGroupsFromFile();

    void RandMarks();

    void GetStat();

    static void ChangeGroup(Student *student, Group *group);

    void KickStudents();

    void RefreshFiles();

    void SetHead();

    void GetInfo();
};

#endif  // INCLUDE_DEANERY_H_
