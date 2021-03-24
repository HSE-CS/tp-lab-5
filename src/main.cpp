// Copyright 2021 Vadukk
#include <iostream>
#include "Deanary.h"

int main() {
  srand(time(0));
  std::vector<std::string> filenames = {"../First_group.txt",
                          "../Second_group.txt", "../Third_group.txt"};
  ReadGroup reader(filenames);
  Deanary deanary(reader, "math");
  deanary.FireStudent(15);
  deanary.HireStudent(15, "Нагаев Дмитрий Федорович", "Group 1", ABILITY::GOOD);
  deanary.AddMarksToAll(10);
  deanary.MoveStudent(18, "Group 2");
  deanary.GetStatistics();
  std::cout << "Head of Group 1 is "
            << deanary.GetGroup("Group 1")->GetHead().GetName() << '\n';
  std::cout << "Head of Group 2 is "
            << deanary.GetGroup("Group 2")->GetHead().GetName() << '\n';
  std::cout << "Head of Group 3 is "
            << deanary.GetGroup("Group 3")->GetHead().GetName() << '\n';
  return 0;
}
