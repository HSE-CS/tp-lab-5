// Copyright 2021 Dev-will-work
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include <string>
#include <vector>
#include <stack>

class Group;
class Student;

enum class FileFormat {
  TXT, JSON, XML
};

class Deanary {
 public:
  Group* operator[](int);  // get by index
  void createGroups(int num_groups);
  void hireStudents(int students_count);
  void addMarksToAll(int count);
  void getStatistics();
  void saveStaff(std::string filename = "state.txt");
  void getLastState();
  void initHeads();
  void moveStudents(std::string, std::string);
  void moveStudents(int, int);
  void fireStudents(int count);
  size_t size();
 private:
  std::vector<Group*> groups;
};

class DeanFactory {
 public:
  friend class Deanary;
  uint64_t createId();
  std::vector<Student*> createStudents();
  void returnStudents(std::vector<Student*>);
  std::vector<Group*> createGroups();
  void returnGroups(std::vector<Group*>);

 private:
  std::string filename = "input.txt";
  FileFormat format = FileFormat::TXT;

  DeanFactory(std::string, FileFormat);
};

#endif  // INCLUDE_DEANARY_H_
