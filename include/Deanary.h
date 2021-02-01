// Copyright by JMax 2020

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <vector>
#include <string>
#include "Group.h"
#include "Student.h"

class Group;
class Student;

class Deanary {
 private:
    std::vector<Group*> groups;

    bool isIdUnique(unsigned int id,
                    std::vector<Student*> *studentsVec = nullptr);
    Student* createStudent(const std::string& fio,
                           std::vector<Student*> *studentsVec = nullptr);
    unsigned int numOfGroups() const;
    bool containsGroup(const std::string& title) const;
    std::string generateStatistics();
    void addGroup(Group* group);
    static void addStudent(Student* student, Group *group);
    int groupIndex(const std::string& title) const;

 public:
    Deanary();
    ~Deanary();
    void createGroups(const std::string& fileName);
    void hireStudents(const std::string& fileName);
    void addMarksToAll();
    void getStatistics();
    void moveStudent(const unsigned int id,
                     const std::string& from, const std::string& to);
    void moveStudent(const std::string& fio,
                     const std::string& from, const std::string& to);
    void saveStaff(const std::string& fileName);
    void addStudent(const std::string& fio, const std::string& groupTitle);
    void addGroup(const std::string& title, const std::string& spec);
    void initHeads();
    void fireStudents();
    Group* getGroup(const std::string& title) const;
};

#endif  // INCLUDE_DEANARY_H_
