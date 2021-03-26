// Copyright [2021] <Nikita Semaev>
#include <string>
#include <vector>
#include "../include/Group.h"
#include "../include/Deanery.h"

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

class Student{
 public:
    Student(uint16_t id, std::string &&fio) : id(id)
                                            , fio(fio)
                                            , group(nullptr)
    {}
    Student(const Student&) = delete;
    void addToGroup(Group *group);
    void addMark(uint8_t mark);
    float averageMark() const;
    friend Student* Group::findStudent(uint16_t id);
    friend Student* Group::findStudent(std::string fio);
    friend std::ostream& operator<<(std::ostream& os, Deanery &deanery);
 private:
    uint16_t id;
    std::string fio;
    Group *group;
    std::vector <uint8_t> marks;
};




#endif  // INCLUDE_STUDENT_H_
