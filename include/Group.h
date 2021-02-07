// Copyright 2021 Sozinov Kirill
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>

class Student;
class Deanery;

class Group {
    friend class Deanery;

 private:
     std::string title;
     std::string spec;
     std::vector <Student *> students;
     Student *head;
     void addStudent(Student *st);
     void chooseHead();
     void removeStudent(Student *st);

 public:
     Group(std::string title, std::string spec);
     ~Group();
     Student *getHead();
     Student *getStudent(std::string fio);
     Student *getStudent(unsigned id);
     bool containsStudent(std::string fio);
     bool containsStudent(unsigned id);
     double getAverageMark();
     std::vector <Student *> getStudents() const;
};

#endif  // INCLUDE_GROUP_H_
