// Copyright 2021 Tatsenko Ilyas
#pragma once
#include<vector>
#include<string>
#include"Group.h"
#include"Student.h"

class Deanary {
 private:
    std::vector<Group*> groups;
    std::vector<Student*> students;
 public:

    void create_students_from_file(std::string file_name);
    void creative_groups_from_file(std::string filemname);
    void add_marks_to_all();
    void get_statistic();
    void move_students(std::string student, std::string group);
    void fire_student(std:: string student);
    void save_data_in_file(std::string filename,  std::string filename2);
    void init_heads();
};