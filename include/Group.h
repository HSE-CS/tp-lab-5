// copyright Toliman 2021

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>
#include <random>

class Student;

class Group {
 private:
  std::string title;
  std::string spec;
  std::string fileName;
  std::vector<Student *> students;
  Student *head;

 public:
    explicit Group(std::string titleParam);

    std::string getTitle();

    void setSpec(std::string specParam);

    void setTitle(std::string titleParam);

    void setFileName(std::string file);

    std::string getFileName();

    void addStudent(Student student);

    void chooseHead();

    Student *getHead();

    Student *searchStudent(const std::string &fioField);

    Student *searchStudent(int idField);

    float getMiddleMark();

    void deleteStudent(Student student);

    std::vector<Student *> getStudents();

    void str();
};

#endif  // INCLUDE_GROUP_H_
