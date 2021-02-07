// Copyright 2021 dmitrycvetkov2000


#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>

class Student;
class Deanary;

class Group {
  public:
    friend class Student;
    friend class Deanary;

    explicit Group(const std::string& name);
    ~Group();

    void addStudent(Student* student);
    void chooseHead(int id);
    double getAverageMark() const;
    Student* getStudent(int id) const;
    bool containsStudent(int id) const;
    void removeStudent(int id);
    bool isEmpty() const;

  private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    int headId;

    std::vector<Student*>::const_iterator findStudent(int id) const;
};

#endif  // INCLUDE_GROUP_H_
