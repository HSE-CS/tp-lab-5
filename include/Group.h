#ifndef Group_h
#define Group_h

#include "Deanary.h"
#include "Student.h"

class Student;

class Group {
    friend class Deanary;
    friend class Student;
private:
    std::string title;
    std::string spec;
    std::vector <Student*> students;
    Student* head;
public:
    Group() {}
    Group(std::string name);
    void addSpeciality(std::string speciality);
    void addStudent(Student* newStudent);
    void chooseHead();
    Student* find(std::string key);
    float averageGroupMark();
    void goodbyeStudent(std::string id);
};

#endif /* Group_h */
