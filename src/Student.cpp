// Copyright dash 2021

#include <Student.h>

double  Student::average_mark() {
  int result = 0;
  int size = marks.size();
  for (int i : marks) {
    result = result + i;
  }
  return result / size;
}

void Student::add_mark(int newmark) {
  marks.push_back(newmark);
}
void  Student::add_to_group(Group* group) {
  this->group = group;
}

int Student::get_id() {
  return id;
}

std::string Student::get_fio() {
  return fio;
}
