// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include "Group.h"
#include <iostream>
#include <string>
#include <vector>
class Group;

class Student {
    friend class Group;
    friend class Deanary;
 private:
    int id;
    std::string fio;
    Group* group;
    std::vector<int> marks;
    void addToGroup(Group* gr);
    void addmark(int mark);

 public:
    explicit Student() {
        id = 0;
        fio = "";
        group = nullptr;
        marks = {0};
    }
    explicit Student(Student& st) {
        id = st.id;
        fio = st.fio;
        group = st.group;
        for (int i = 0;i < st.marks.size();i++) {
            marks[i] = st.marks[i];
        }
    }
    explicit Student(int id_, std::string fio_, Group* group_, std::vector<int> marks_) {
        id = id_;
        fio = fio_;
        group = group_;
		for (int i = 0;i < marks_.size();i++) {
			marks.push_back(marks_[i]);
		}
    }
    double getAveragemark();
    bool isHeadOfGroup();
    int getId();
    std::string getFio();
};
#endif  // INCLUDE_STUDENT_H_