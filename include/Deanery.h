// Copyright [2021] <Nikita Semaev>
#include <initializer_list>
#include <string>
#include <vector>
#include <iostream>

#ifndef INCLUDE_DEANERY_H_
#define INCLUDE_DEANERY_H_

class Group;

class Deanery {
 public:
    Deanery(std::initializer_list <std::string> filesList);
    void randomMarks();
    const std::vector <Group *> &getGroups() const;
    friend std::ostream& operator<<(std::ostream& os, Deanery &deanery);
 private:
    std::vector <Group*> groups;
};

#endif  // INCLUDE_DEANERY_H_
