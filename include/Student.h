// Copyright 7.02.2021 Golovanov

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <utility>
#include <vector>


class Group;
class Student {
private:
std::string id;
std::string fio;
Group* group;
std::vector<int> marks;

public:
Student(std::string id, std::string fio);
void addToGroup(Group* group);

Group* getGroup() const;
void setGroup(Group* group);
std::string getId() const;

void setId(std::string id);
void setFio(const std::string& fio);
const std::string& getFio() const;
const std::vector<int>& getMarks() const;

void addMark(int mark);
double calculateAverageMark();

virtual ~Student();
};

#endif  // INCLUDE_STUDENT_H_
