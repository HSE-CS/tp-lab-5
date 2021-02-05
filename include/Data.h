// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_DATA_H_
#define INCLUDE_DATA_H_
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<int> getmarks(std::string buff);
std::vector<std::string> read_data(std::string filename);
void write_data(std::string filename, std::string data);
std::string getfio(std::string buff);
std::vector<std::string> read_data(std::string filename);
std::string join(std::vector<int> mk);
int getid(std::string buff);

#endif  // INCLUDE_DEANARY_H_