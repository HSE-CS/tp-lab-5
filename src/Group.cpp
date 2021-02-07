////// Copyright 2021 Ozhiganova Polina
#include "Group.h"

Group::Group(std::string newTitle,
             std::string newSpec,
             const std::vector<Student *> &newStudents,
             Student *newHead) {
  this->title = std::move(newTitle);
  this->spec = std::move(newSpec);
  this->head = newHead;
}

Group::~Group() {
  for (auto &st : students) {
    st->~Student();
  }
  this->title.clear();
  this->spec.clear();
  this->students.clear();
  this->head = nullptr;
}

bool Group::containStudent(int stId) {
  for (auto &st : students) {
    if (st->getStId() == stId) {
      return true;
    } else {
      return false;
    }
  }
  return false;
}

Student *Group::getStudent(int stId) {
  for (auto &st : students) {
    if (st->getStId() == stId) {
      return st;
    }
  }
  return nullptr;
}

float Group::getAverageMark() {
  float sum = 0.0;
  for (auto &st : students) {
    sum += st->getAverageMark();
  }
  return sum / students.size();
}

bool Group::isEmpty() {
  if (students.empty()) {
    return true;
  } else {
    return false;
  }
}

void Group::addStudent(Student *st, Group *gr) {
  st->addToGroup(st, gr);
}

void removeFromVec(std::vector<Student *> *vec, size_t pos) {
  auto it = vec->begin();
  std::advance(it, pos);
  vec->erase(it);
}

void Group::removeStudent(int stId) {
  Student *st = getStudent(stId);
  int stIndexInVec = 0;
  for (int i = 0; i < students.size(); ++i) {
    if (st == students[i]) {
      stIndexInVec = i;
      break;
    }
  }
  bool isHead = false;
  if (st->isHeadOfGroup()) {
    isHead = true;
  }
  removeFromVec(&students, stIndexInVec);
  if (isHead) {
    chooseHead(students);
  }
}

Student *Group::chooseHead(const std::vector<Student *> &newStudents) {
  int beginId = newStudents[0]->getStId();
  int endId = newStudents[newStudents.size() - 1]->getStId();
  if (beginId > endId) {
    for (auto &st : newStudents) {
      if (st->getStId() == beginId) {
        return st;
      }
    }
  } else {
    PRNG *generator = new PRNG;
    initGenerator(generator);
    int idHead = random(generator, beginId, endId);
    for (auto &st : newStudents) {
      if (st->getStId() == idHead) {
        return st;
      }
    }
  }
  return nullptr;
}

std::vector<Student *> Group::getStudents() {
  return this->students;
}

std::string Group::getSpec() {
  return this->spec;
}

std::string Group::getTitle() {
  return this->title;
}
