  // Copyright 2021 Bulatov D.
#include <string>

#include "Deanary.h"
#include "Group.h"
#include "Student.h"

int main() {
  Student st("Ivan Ivanov", 10);
  auto s = st.getFio();
  Deanary dr;
  dr.createGroups();
  dr.hireStudents();
  dr.addMarks();
  dr.moveStudents();
  dr.initHead();
  dr.printInfo();
  dr.moveStudent("Lewis Ramirez", "First group");
  dr.fireStudent();
  dr.printInfo();
  dr.saveStuff();
}
