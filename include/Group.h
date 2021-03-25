// Copyright 2021 by Maxim


#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "Student.h"

class Student;

class Group {
 private:
    std::string title;
    std::string spec;
    std::vector<Student *> students;
    Student *head;

 public:
    Group(std::string title, std::string spec) {
        this->title = title;
        this->spec = spec;
    }

    std::string getTitle() {
        return this->title;
    }

    std::vector<Student *> getAllStudents() {
        return this->students;
    }

    std::string getSpec() {
        return this->spec;
    }

    Student *getHead() {
        return head;
    }

    void addStudent(Student *new_studet) {
        students.push_back(new_studet);
    }

    void chooseHead(int idx) {
        int head_pk = idx;
        this->head = this->students[head_pk];
    }

    double getAveragemark() {
        double sum = 0;
        for (auto &el : this->students) {
            sum += el->getAveragemark();
        }
        return sum / this->students.size();
    }

    Student *getStudent(int id) {
        for (int i = 0; i < this->students.size(); i++) {
            if (this->students[i]->getID() == id) {
                return this->students[i];
            }
        }
        return nullptr;
    }

    bool containsStudent(int id) {
        for (int i = 0; i < this->students.size(); i++) {
            if (this->students[i]->getID() == id) {
                return true;
            }
        }
        return false;
    }

    void removeStudent(Student *student) {
        student->addToGroup(nullptr);
        this->students.erase(
                std::remove(this->students.begin(),
                            this->students.end(), student),
         this->students.end());
    }

    bool isEmpty() {
        if (this->students.size() == 0) {
            return true;
        }
        return false;
    }
};

#endif  // INCLUDE_GROUP_H_
