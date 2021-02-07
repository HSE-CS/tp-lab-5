#ifndef Student_h
#define Student_h

#include "Group.h"

class Group;

class Student {
    friend class Deanary;
    friend class Group;
private:
    std::string id;
    std::string fio;
    Group* group;
    std::vector <uint64_t> marks;
public:
    Student() {}
    Student(std::string ID, std::string FIO);
    void groupIs(Group* G);
    void addMark(uint64_t mark);
    float averageMark();
};

#endif /* Student_h */
