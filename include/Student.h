//
// Created by mushka on 19.03.2021.
//

#ifndef TP_LAB_5_STUDENT_H
#define TP_LAB_5_STUDENT_H
#include <string>
#include <vector>

class Group;
class Student {
    friend class Group;
    friend class Deanary;

private:
    int id;
    std::string fio;
    std::vector<int> marks;
    Group *group{};

public:
    explicit Student(int id, std::string fio);

    void AddToGroup(Group *group);
    void AddMark(int mark);
    float CountAvgMark();

    int GetId() const;
    std::string GetFio();
};


#endif //TP_LAB_5_STUDENT_H
