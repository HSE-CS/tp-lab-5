// Copyright dash 2021
#include <Group.h>
#include <Student.h>

void Group::add_student(Student* newstudent) {
  students.push_back(newstudent);
}

void Group::find_head() {
  int s = students.size();
  Student* h = students[rand() % s];
  head = h;
}

double Group::average_mark_group() {
  int s_s = students.size();
  int sum = 0;
  int result = 0;
  for (auto* student : students) {
    sum = sum + student->average_mark();
  }
  return sum / s_s;
}

void Group::delete_student(Student* del_student) {
  for (int i = 0; i < students.size(); i++) {
    if (students[i]->get_fio() == del_student->get_fio()) {
      for (int k = i + 1; k < students.size(); k++) {
        students[k - 1] = students[k];
  }
      students.pop_back();
      break;
  }
  }
}

Student& Group::findStudent(const std::string& fio) {
    for (auto* student : students) {
        if (student->get_fio() == fio) {
            return *student;
        }
    }
}

Student& Group::findStudent(int id) {
    for (auto* student : students) {
        if (student->get_id() == id) {
            return *student;
        }
    }
}

std::string Group::get_title() {
  return title;
}

std::string Group::get_spec() {
  return spec;
}
