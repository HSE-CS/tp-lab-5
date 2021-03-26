#ifndef INCLUDE_GROUP_HPP_
#define INCLUDE_GROUP_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include "Student.hpp"

class Student;

class Group {
private:
    std::string title;
    std::string spec;
    size_t quantity;
    Student* head;
    std::vector<Student*> students;
    float group_mean;

    bool _check_fio(std::vector<std::string> arr1, std::vector<std::string> arr2);
    void _add_student_to_arr(Student* st, size_t pos);
    void _del_student(std::vector<Student*>::iterator iter, bool delete_student = true);
public:
    Group(std::string title);

    static std::vector<std::string> split(std::string str, std::string sep);

    bool create_student(std::string str);
    bool add_student(Student* student);
    Student* head_choice();
    float mean_mark_group();
    void add_marks();
    bool transfer_to_group(id_t id, Group* group);
    bool is_student_exist(id_t id);
    bool expell_student(size_t index);
    bool expell_by_id(id_t id);
    std::vector<id_t> choose_students_to_expell();
    Student* search_student(id_t id);
    Student* search_student(std::string fio);
    void print_group_data();
    std::vector<Student*> get_students() { return students; }
    float get_group_mean() { return group_mean; }
};
#endif  // INCLUDE_GROUP_HPP_
