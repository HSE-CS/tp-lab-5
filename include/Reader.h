// Copyright 2020 Osmanov Islam
#ifndef INCLUDE_READER_H_
#define INCLUDE_READER_H_

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include "Deanary.h"


class Reader {
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


#endif  // INCLUDE_READER_H_
