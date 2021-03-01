#ifndef TP_LAB_5_DEANERY_H
#define TP_LAB_5_DEANERY_H

#include "Group.h"
#include <fstream>

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

#endif //TP_LAB_5_DEANERY_H
