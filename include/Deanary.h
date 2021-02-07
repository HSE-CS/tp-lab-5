//Copyright 2021 Nikita Naumov
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include "Student.h"
#include "Group.h"

class Student;
class Group;
/*
Примерный перечень полей:

groups - массив групп
Обеспечить класс следующими методами:

создание студентов на основе данных из файла
создание групп на основе данных из файла
добавление случайных оценок студентам
получение статистики по успеваемости студентов и групп
перевод студентов из группы в группу
отчисление студентов за неуспеваемость
сохранение обновленных данных в файлах
инициация выборов старост в группах
вывод данных на консоль
Создать два файла с данными для групп и студентов (не менее 3 групп и 30
студентов). Использовать эти файлы при формировании данных групп и студентов

Написать демонстрационную версию приложения
*/

class Deanary {
 public:
  Deanary();
  ~Deanary();
  void initialiseStudents();
  void createGroups();
  void addRandomMarks(Student*, int);
  double getStudentStatistic(Student*);
  double getGroupStatistic(Group*);
  void moveStudent(Student*, Group*);
  void fireForAcademicFailure();
  void initialiseElection();
  void printAllInfo();
  void saveChanges();
  double getCurrentAmountOfStudents();
  double getCurrentAmoutOfGroups();
  Student* getStudentAddress(unsigned);
  Group* getGroupAddress(unsigned);
  void addStudentToGroup(Student*, Group*);
  void addStudent(Student*);
  void addGroup(Group*);
 private:
  std::vector<Student*> allStudents;
  std::vector<Group*> groups;
  unsigned numberOfStudents;
  void addStudentToRandomGroup(Student*);
};



#endif  // !INCLUDE_DEANARY_H_
