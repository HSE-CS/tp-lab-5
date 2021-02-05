//  Copyright © 2021 Ksuvot. All rights reserved.

#include "Deanary.h"
#include <iostream>

int main() {
  Student student(11, "Votinova Ksenia Konstantinovna");
  student.getAverageMark();
  Deanary deanary;
  deanary.createGroups();
  deanary.createStudents();
  deanary.saveData();
}
