#include "Group.h"

#include <algorithm>
#include <string>
#include <utility>
#include <vector>

Group::Group(std::string title, std::string speciality)
    : title(std::move(title)), speciality(std::move(speciality)) {}
void Group::addStudent(const Student& student) { students.push_back(student); }
void Group::removeStudent(int id) {
  for (int i = 0; i < students.size(); ++i) {
    if (students[i].id == id) {
      if (&students[i] == head) {
        students.erase(students.begin() + i);
        selectHead();
      } else {
        students.erase(students.begin() + i);
      }
      break;
    }
  }
}
void Group::selectHead() {
  double best_mark = 0.0;
  Student* best_student = nullptr;
  for (auto& s : students) {
    double student_mark = s.averageMark();
    if (student_mark > best_mark) {
      best_mark = student_mark;
      best_student = &s;
    }
  }
  head = best_student;
}
std::vector<Student> Group::getStudentByFio(const std::string& fio) const {
  std::vector<Student> with_fio;
  for (const auto& s : students) {
    if (s.fio == fio) {
      with_fio.emplace_back(s);
    }
  }
  return with_fio;
}
const Student* Group::getStudentById(int id) const {
  for (const auto& s : students) {
    if (s.id == id) {
      return &s;
    }
  }
  return nullptr;
}
const Student* Group::getHead() const { return head; }
double Group::averageMark() const {
  double sum = 0.0;
  for (const auto& s : students) {
    // loosing all accuracy here...
    sum += s.averageMark();
  }
  return sum / static_cast<double>(students.size());
}
