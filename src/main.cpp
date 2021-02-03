// Copyright 2021 Smirnov Grigory
#include "..\include\Deanery.h"

Group* groupReader(std::string path) {
  std::ifstream file(path);
  std::string title;
  std::string spec;
  file >> title;
  file >> spec;
  Group* result = new Group(title, spec);

  std::random_device seed;
  std::string fio;
  file >> fio;
  while (fio!="EOF") {
    Student* newbie = new Student((seed()), fio);
    result->addStudent(newbie);
    file >> fio;
  }
  return result;
}

int main() {
  std::string name = "Seledkin Valentin Andreevich";
  Student test = Student(123, name);
  test.addMark(1);
  test.addMark(10);
  test.addMark(2);
  std::cout << test.getAverageMark() << std::endl;
  Group* eco1 = groupReader("..\\..\\test\\groups_input\\eco1.txt");
  std::cout << eco1->getNumberOfStudents()<<std::endl<<eco1->getGroupInfo()<<std::endl<<eco1->getNumberOfStudents();
}
