// Copyright 2021 Tatsenko Ilya
#pragma once
#include<iostream>
#include <vector>
#include<string>
#include"Group.h"

class Group;
class Deanary;

class Student {
 private:
    int id;
    std::string fio;
    Group* group = nullptr;
    std::vector<int> marks;

 public:
    Student() {}
    Student(int id, std::string fio) {
        this->id = id;
        this->fio = fio;
    }
    void add_to_group(Group* group);
    void add_mark(int mark);
    double get_avarage_mark();
    std::string get_fio() {
        return fio;
    }
    int get_id() {
        return id;
    }
    std::string get_group() {
        return group->title;
    }
    friend Group;
    friend Deanary;
};

