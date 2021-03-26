#ifndef deanery_h
#define deanery_h 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include "group.hpp"

class Deanery {
private:
    std::map<std::string, Group*> groups;

public:
    Deanery(std::string stud_file_name, std::string gr_file_name);
    void add_marks_for_groups();
    bool student_transfer(id_t id, std::string from_group, std::string to_group);
    bool expell_one_student(id_t id);
    void expell_students();
    void head_choices();
    void head_choices_in_group(std::string group_name);
    void data_output();
    void save_data(std::string file_name);
    void calculate_means();
};

#endif deanery_h
