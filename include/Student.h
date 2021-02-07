#ifndef TP_LAB_5_STUDENT_H
#define TP_LAB_5_STUDENT_H

#include <string>
#include <vector>
#include "Group.h"

class Student {
private:
    int id;
    std::string fio;
    std::vector<int> marks;

public:
    Group* group;
    int getId() const;
    std::string getName() const;
    Student(int input_id, const std::string& input_fio);
    void addToGroup(Group* group);
    void addMark(int mark);
    double getAverageMark();
};



#endif //TP_LAB_5_STUDENT_H
