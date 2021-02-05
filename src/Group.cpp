//Copyright 2021 Nikita Naumov
#include "Group.h"
#include "Student.h"


/*создание группы с указанием названия
добавление студента
избрание старосты
поиск студента по ФИО или ИД
вычисление соеднего балла в группе
исключение студента из группы*/
Group::Group(std::string title) { 
    this->title = title;
    this->spec = (std::string) "spec"; 
    this->head = nullptr;
}
Group::~Group() { 
    this->title.clear();
    this->head = nullptr;
    this->students.clear();
}  
void Group::addStudentToGroup(Student* studentToAdd) {
  studentToAdd->addToGroup(this);
  this->students.push_back(studentToAdd);
}
std::string Group::getTitle() { return this->title; }
void Group::setHead() {

}
bool Group::findStudentByID(unsigned id) { return true; }
bool Group::findStudentByFIO(std::string fio) { return true; }
double Group::getAverageGroupMark() { return 0; }
void Group::fireStudentFromGroup() {

}
