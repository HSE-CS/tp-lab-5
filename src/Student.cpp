//  Copyright 2020 GHA created by Klykov Anton

#include "Student.h"
#include <random>

int Student::m_id = 0;

void Student::addToGroup(Group* _gr) {
  group = _gr;
}
void Student::addMark(int j) {
  unsigned int coef_rand{0};
  std::random_device rd;
  std::mt19937 mersenne(rd());
  for (size_t i = 0; i < this->FinSenThn.size(); ++i) {
    coef_rand += static_cast<unsigned int>(this->FinSenThn[i]);
  }
  coef_rand = ((coef_rand) / (this->id + 1) * 46328);
  if (j <= 2) {
    marks.push_back(static_cast<unsigned int>((mersenne() * coef_rand) % 11));
  }
  if (this->getAverageMark() <= 10 && this->getAverageMark() >= 7) {
    marks.push_back(static_cast<unsigned int>((mersenne() * coef_rand) % 5) + 6);
  } else if (this->getAverageMark() <= 7 && this->getAverageMark() >= 5) {
    marks.push_back(static_cast<unsigned int>((mersenne() * coef_rand) % 5) + 5);
  } else if (this->getAverageMark() <= 5 && this->getAverageMark() >= 3) {
    marks.push_back(static_cast<unsigned int>((mersenne() * coef_rand) % 5) + 4);
  } else if (this->getAverageMark() <= 3 && this->getAverageMark() >= 0) {
    marks.push_back(static_cast<unsigned int>((mersenne() * coef_rand) % 5) + 3);
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
