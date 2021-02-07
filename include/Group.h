// Copyright dash 2021
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <Student.h>
#include <string>
#include <vector>

class Student;

class Group {
    friend class Deanary;
 private:
    std::string title;
    std::string spec;
    Student* head;
    std::vector<Student*> students;
 public:
    Group(std::string newtitle, std::string newspec) {
        title = newtitle;
        spec = newspec;
    }
    void add_student(Student* student);
    void find_head();
    double average_mark_group();
    void delete_student(Student* del_student);
    Student& findStudent(const std::string& fio);
    Student& findStudent(int id);
    std::string get_title();
    std::string get_spec();
};

#endif  // INCLUDE_GROUP_H_
