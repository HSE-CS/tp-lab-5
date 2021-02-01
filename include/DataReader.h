// Copyright 2020 GHA Test Team
#ifndef INCLUDE_DATAREADER_H_
#define INCLUDE_DATAREADER_H_
#include <string>
#include <vector>
#include <fstream>
#include <iostream>


class DataReader {
 private:
  std::vector<std::string> groups;
  std::vector<std::string> students;

 public:
  DataReader();
  DataReader(std::string, std::string, std::string students_format="txt",
    std::string groups_format="txt");
  void readStudentsData(std::string, std::string format = "txt");
  void readGroupsData(std::string, std::string format = "txt");
  void readStudentsFromTxt(std::string);
  void readGroupsFromTxt(std::string);
  std::vector<std::string> getGroups();
  std::vector<std::string> getStudents();
};
#endif  // INCLUDE_DATAREADER_H_
