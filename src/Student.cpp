//  Copyright 2020 GHA created by Klykov Anton

#include "Student.h"
#include <cstdlib>
#include <ctime>

int Student::m_id = 0;

void Student::addToGroup(Group* _gr) {
  group = _gr;
}
void Student::addMark(int iteration) {
  srand(static_cast<unsigned int>(time(nullptr)));
  unsigned int coef_rand{0};
  for (size_t i = 0; i < this->FinSenThn.size(); ++i) {
    coef_rand += static_cast<unsigned int>(this->FinSenThn.at(i));
  }
  coef_rand = ((coef_rand) / (this->id + 1) * (iteration + 46328));
  if (iteration <= 2) {
    marks.push_back(static_cast<unsigned int>(((rand() * coef_rand)) % 11));
  } else {
    if (this->getAverageMark() <= 10 && this->getAverageMark() >= 7) {
      marks.push_back(static_cast<unsigned int>((rand() * coef_rand) % 5) + 6);
    } else if (this->getAverageMark() <= 7 && this->getAverageMark() >= 5) {
      marks.push_back(static_cast<unsigned int>((rand() * coef_rand) % 5) + 5);
    } else if (this->getAverageMark() <= 5 && this->getAverageMark() >= 3) {
      marks.push_back(static_cast<unsigned int>((rand() * coef_rand) % 5) + 4);
    } else if (this->getAverageMark() <= 3 && this->getAverageMark() >= 0) {
      marks.push_back(static_cast<unsigned int>((rand() * coef_rand) % 5) + 3);
    }
  }
}
double Student::getAverageMark() {
  double average{0};
  for (const double mark : marks) {
    average += mark;
  }
  return (average / marks.size());
}
bool Student::isHeadOfGroup() const {
  return isHead;
}
size_t Student::getId() const {
  return id;
}
Student::Student(const std::string& fio) {
  id = m_id++;
  FinSenThn = fio;
  group = nullptr;
}
Group* Student::getGroup() {
  return group;
}
int Student::getAmountMarks() {
  return marks.size();
}
