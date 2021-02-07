// Copyright dash 2021
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include <Group.h>
#include <string>
#include <vector>

class Group;

class Student {
    friend class Deanary;
private:
    Group* group;
    unsigned int id;
    std::string fio;
    std::vector<int> marks;
   

public:
    double average_mark();
    void add_mark(int newmark);
    void add_to_group(Group* group);
    Student(unsigned int newid, std::string newfio) {
        id = newid;
        fio = newfio;
    }
    int get_id();
    std::string get_fio();
};
#endif // INCLUDE_STUDENT_H_
