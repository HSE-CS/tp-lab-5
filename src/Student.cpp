////// Copyright 2021 Ozhiganova Polina
#include "Student.h"
#include "Group.h"

int UniqueID::nextID = 0;

UniqueID::UniqueID() {
  id = ++nextID;
}

UniqueID::UniqueID(const UniqueID &orig) {
  id = orig.id;
}

UniqueID &UniqueID::operator=(const UniqueID &orig) {
  id = orig.id;
  return (*this);
}

int UniqueID::getId() const {
  return this->id;
}

Student::Student(std::string newFio, UniqueID *newId) {
  this->id = newId->id;
  this->fio = std::move(newFio);
}

Student::Student() {
  this->id = 0;
  this->fio = "";
}

Student::~Student() {
  this->id = 0;
  this->fio.clear();
  this->marks.clear();
  this->group = nullptr;
}

bool Student::isHeadOfGroup() {
  Student *isItHead = group->head;
  if (isItHead->fio == this->fio) {
    return true;
  } else {
    return false;
  }
}

float Student::getAverageMark() {
  if (this->marks.empty()) {
    return 0.0;
  }
  float sum = 0.0;
  for (auto &num : this->marks) {
    sum += num;
  }
  return sum / marks.size();
}

void initGenerator(PRNG *generator) {
  generator->seed = unsigned(std::time(nullptr));
}

unsigned random(PRNG *generator, unsigned minValue, unsigned maxValue) {
  assert(minValue < maxValue);
  generator->seed = (generator->seed * 73129 + 95121);
  return (generator->seed % (maxValue + 1 - minValue)) + minValue;
}

void Student::addMarksInit(PRNG *generator, const std::string &whichMark) {
  std::vector<int> vec;
  initGenerator(generator);
  for (int i = 0; i < 15; ++i) {
    if (whichMark == "low") {
      int mark = random(generator, 0, 4);
      vec.push_back(mark);
    } else if (whichMark == "high") {
      int mark = random(generator, 8, 10);
      vec.push_back(mark);
    } else if (whichMark == "normal") {
      int mark = random(generator, 1, 10);
      vec.push_back(mark);
    }
  }
  this->marks = vec;
}

void Student::addToGroup(Student *st, Group *gr) {
  this->group = gr;
  this->group->students.push_back(st);
}

int Student::getStId() const {
  return this->id;
}

std::string Student::getStNamed() const {
  return this->fio;
}

std::string Student::getStSpec() const {
  return this->group->getSpec();
}
void Student::addMark(int mark) {
  this->marks.push_back(mark);
}
