#ifndef WORK_READER_H
#define WORK_READER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Deanary.h"


class Reader{
public:
    std::vector <std::pair<std::string, std::string>> names;
    int num_groups = 0;
    std::string spec;
    std::vector <std::pair<std::string, std::string>> groups;
    std::vector <std::pair<std::string, std::string>> ids;
    std::vector <std::pair<std::string, std::string>> marks;
    void StudentsReader(std::string fileName);
    void MarksReader(std::string fileName);
    void GroupsReader(std::string fileName);
};

#endif //WORK_READER_H
