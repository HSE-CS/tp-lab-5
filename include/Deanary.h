#ifndef TP_LAB_5_DEANARY_H
#define TP_LAB_5_DEANARY_H

#include <vector>
#include "Group.h"

class Deanery {
private:
    std::vector<Group*> groups;

public:
    void createGroups();
    void createStudents();
    void addRandomMarks();
    void getStat();
    static void moveStudent(Student* student, Group* destination);
    void fireStudents();
    void saveNewData();
    void initHeadChoice();
    void printData();
};


#endif //TP_LAB_5_DEANARY_H
