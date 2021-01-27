#include <iostream>
#include <string>
#include <vector>

#include "Student.h"

class Group {
 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head;
  void addStudent(Student* person);
  Student* chooseHead();
  void removeStudent(int id);

 public:
  Group(std::string tl, std::string sp);
  float getAveragemark();
  Student* getStudent(int id);
  Student* getStudent(std::string);
  bool isEmpty();
};
