#pragma once

#include <memory>
#include <fstream>

#include "Deanary.h"

class Creator {

public:
    Creator() {

    }
    std::unique_ptr<Deanary> fabricMethod(const std::string filename = "data.txt") const;
    std::string getName(std::string str, std::string delimiter = ":") const;
    std::vector<short> getMarks(std::string str, std::string delimiter = ":") const;
};