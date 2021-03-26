// Copyright Mushka Nikita, 2021

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

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


#endif  // INCLUDE_STUDENT_H_
