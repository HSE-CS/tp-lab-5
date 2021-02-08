// Copyright Roman Balayan @ 2021

#pragma once

#include <memory>
#include <fstream>
#include <vector>
#include <string>

#include "../include/Deanary.h"

class Creator {
 public:
    Creator() {}
    std::unique_ptr<Deanary> fabricMethod
    (const std::string filename = "data.txt");
    std::string getName(std::string str, std::string delimiter = ":") const;
    std::vector<int16_t> getMarks
    (std::string str, std::string delimiter = ":") const;
};
