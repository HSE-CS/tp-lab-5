// Copyright 2021 Ryzhova

#include "Student.h"
#include "Deanary.h"
#include "Group.h"

int main() {
  Deanary deanary;
  deanary.create_group_from_file("group.txt");
  deanary.create_group_from_file("group1.txt");
  deanary.create_group_from_file("group2.txt");
  deanary.init_heads();
  for (int i = 0; i < 10; i++) {
    deanary.add_marks_to_all();
  }
  deanary.get_statistics();
  deanary.move_student(10005, "PI-2");
  Student student(40023, "Ryzhova Irina Igorevna");
  deanary.hire_student(&student, "PI-1");
  for (int i = 0; i < 5; i++) {
      deanary.add_marks_to_all();
  }
  deanary.get_statistics();
}
