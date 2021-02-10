// Copyright 2021 Tatsenko Alexey
#pragma once
#include <vector>
#include<string>
#include"Group.h"

class Group;
class Deanary;

class Student {
   private:
    std::string id;
    std::string fi;
    std::vector<int> evals;
    Group* group;

   public:
    friend Group;
    friend Deanary;
    Student() : group{nullptr} {}
    Student(std::string id, std::string fi) : group{nullptr}, id{id}, fi{fi} {}
    void AddToGroup(Group* group);
    void AddEval(int mark);
    int GetAvarageEval();
    std::string GetFi();
    std::string GetId();
    std::string GetGroup();
};

