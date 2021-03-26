#ifndef INCLUDE_STUDENT_HPP_
#define INCLUDE_STUDENT_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include "Group.h"
#define NUMBERS_SET "0123456789"

class Group;

//Studen Class
class Student {
private:
    std::string last_name, first_name, second_name;
    std::vector<int> marks;
    float mean_mark;
    Group *group;
    size_t num;
    id_t id;
    bool is_head;
public:
    Student(std::string id_and_fio, Group* group);
    ~Student();
    
    void group_enroll(Group* group) {this->group = group;}
    void add_mark(unsigned int mark);
    float mean_marks();
    float get_mean() {return mean_mark;}
    id_t get_id() {return id;}
    std::string get_last_name() {return last_name;}
    std::string get_first_name() {return first_name;}
    std::string get_second_name() {return second_name;}
    void set_as_head() {is_head = true;}
    void print_st_data_short();
    void print_fio();
    bool is_group_head() {return is_head;}
};

#endif  // INCLUDE_STUDENT_HPP_
