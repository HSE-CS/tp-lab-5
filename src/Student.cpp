// Copyright 2021 tatsenko Ilya
#include"Student.h"
#include"Group.h"

void Student::AddToGroup(Group * gt) { this->group = gt; }

void Student::AddEval(int eval) {
    evals.push_back(eval);
}

int Student::GetAvarageEval() {
    int x = 0;
    for (auto &eval : this->evals) {
      x += eval;
    }
    return (x / evals.size());
}

std::string Student::GetId() { return this->id; }
std::string Student::GetFi() { return this->fi; }
