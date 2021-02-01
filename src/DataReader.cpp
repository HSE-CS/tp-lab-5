// Copyright 2020 GHA Test Team
#include "DataReader.h"


DataReader::DataReader() {

}

DataReader::DataReader(std::string students_file_name,
  std::string groups_file_name, std::string students_format,
  std::string groups_format) {
  this->readStudentsData(students_file_name, students_format);
  this->readGroupsData(groups_file_name, groups_format);
}

void DataReader::readStudentsData(std::string file_name, std::string format) {
  if (format == "txt")
    this->readStudentsFromTxt(file_name);
  else {
    std::cout << "ERROR: unsupported file format" << std::endl;
  }
}

void DataReader::readGroupsData(std::string file_name, std::string format) {
  if (format == "txt")
    this->readGroupsFromTxt(file_name);
  else 
    std::cout << "ERROR: unsupported file format" << std::endl;
}

void DataReader::readStudentsFromTxt(std::string file_name) {
  std::ifstream students_file(file_name);
  std::string first_name;
  std::string second_name;
  std::string middle_name;
  while (students_file >> second_name >> first_name >> middle_name) {
    this->students.push_back(second_name + " " +
      first_name + " " +  middle_name);
  }
}

void DataReader::readGroupsFromTxt(std::string file_name) {
  std::ifstream groups_file(file_name);
  std::string group;
  while (groups_file >> group) {
    this->groups.push_back(group);
  }
}

std::vector<std::string> DataReader::getGroups() {
  return this->groups;
}

std::vector<std::string> DataReader::getStudents() {
  return this->students;
}
