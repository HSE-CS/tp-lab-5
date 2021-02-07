// Copyright dash 2021
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include <string>
#include <vector>
#include <Student.h>
#include <Group.h>

class Student;
class Group;

class Deanary {
private:
    std::vector<Group> groups;
    std::vector<Student> students;
public:
    void add_st_file();
    void add_gr_file();
    void add_marks();
    double stat_st(std::string fio);
    double stat_gr(std::string spec);
    void relocat_st(std::string fio, std::string spec);
    void deduction(std::string fio);
    void save();
    void elections();
    void output();
};

#endif // INCLUDE_DEANARY_H_ 