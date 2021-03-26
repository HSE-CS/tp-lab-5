#pragma once
#include <string>
#include <vector>

class Deanery;
class Group;

class Student {
  friend class Deanery;
  friend class Group;

 private:
  int id;
  std::string fio;
  Group* group = nullptr;
  std::vector<int> marks = std::vector<int>();
  void setGroup(Group* p_group);
  void addMark(int mark);
  Student(int id, std::string fio, Group* group);

 public:
  Student(int id, std::string fio);
  double averageMark() const;
  const std::string& getFio() const { return fio; }
  const std::string& getId() const { return fio; }
  const std::vector<int>& getMarks() const { return marks; }
};