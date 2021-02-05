// Copyright 2020 Konina Tatiana
#include <fstream>
#include <iostream>
#include "Data.h"


std::string findToken(std::string tok, std::string delimiter, std::string buf) {
  size_t pos1 = buf.find(tok);
  pos1 += tok.length() + 1;
  size_t pos2 = buf.substr(pos1, buf.length()).find(delimiter) + pos1;
  return buf.substr(pos1, pos2 - pos1);
}

std::vector<std::map<std::string, std::string>> read_st(std::string input) {
  std::ifstream file(input);

  if (file.is_open()) {
    std::vector<std::map<std::string, std::string>> data;
    std::string buf = "";
    while (getline(file, buf)) {
      std::map<std::string, std::string > curentStudent;
      curentStudent.insert(std::pair<std::string,
        std::string>("id", findToken("id", ",", buf)));
      curentStudent.insert(std::pair<std::string,
        std::string>("fio", findToken("fio", ",", buf)));
      curentStudent.insert(std::pair<std::string,
        std::string>("marks", findToken("marks", ",", buf)));
      curentStudent.insert(std::pair<std::string,
        std::string>("spec", findToken("spec", ",", buf)));
      data.push_back(curentStudent);
      curentStudent.clear();
    }
    return data;
  } else {
    throw "file error";
  }
}
std::vector<std::string> read_spec(std::string input) {
  std::ifstream file(input);
  if (file.is_open()) {
    std::vector<std::string> specList;
    std::string buf = "";
    while (getline(file, buf)) {
      specList.push_back(buf);
    }
    return specList;
  } else {
    throw "file error";
  }
}

