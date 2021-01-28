#include <iostream>
#include <string>
#include <vector>

#include "Student.h"

class Student;
class Deanery;

class Group {
  friend class Deanery;
 private:
  std::string title;
  std::string spec;
  std::vector<Student*> *students;
  Student* head;
  void addStudent(Student &person);
  void chooseHead();
  void removeStudent(Student &student);

 public:
  Group(std::string tl, std::string sp);
  float getAveragemark();
  Student& getStudent(int id);
  Student& getStudent(std::string name);
  bool isEmpty();
  std::string getTitle();
  Student* getHead();

};
