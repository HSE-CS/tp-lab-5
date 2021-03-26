#include "Student.h"

#include <utility>
Student::Student(int id, std::string fio, Group *group)
    : id(id), fio(std::move(fio)), group(group) {}
Student::Student(int id, std::string fio) : id(id), fio(std::move(fio)) {}
void Student::setGroup(Group *p_group) { group = p_group; }
void Student::addMark(int mark) { marks.emplace_back(mark); }
double Student::averageMark() const {
  int sum = 0;
  for (int m : marks) {
    sum += m;
  }
  return static_cast<double>(sum) / static_cast<double>(marks.size());
}
