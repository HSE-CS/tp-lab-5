// Copyright 2020 Stanislav Stoianov

#include "../include/Deanary.h"

void Deanery::addMarksToAll() {
  for (Group *g : groups) {
    for (Student *s : g->getStudents()) {
      s->addMark(rand() % 10);
    }
  }
}

void Deanery::moveStudents(Group *fromGroup, Group *toGroup) {
  for (Student *s: fromGroup->getStudents()) {
    s->addToGroup(toGroup);
  }
}

void Deanery::initHeads() {
  for (Group *g : groups) {
    g->chooseHead(g->getStudents()
                      .at(rand() % g->getStudents().size()));
  }
}

