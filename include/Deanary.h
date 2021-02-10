// Copyright 2021 Tatsenko Ilyas
#pragma once
#include<vector>
#include<string>
#include"Group.h"
#include"Student.h"

class Deanary {
 private:
    std::vector<Group*> groups;
    std::vector<Student*> students;

 public:
    void HireStudents(std::string file_name);
    void CreateGroups(std::string filemname);
    void AddEvalsToAll();
    void GetStatistic();
    void MoveStudents(std::string student, std::string group);
    void FireStudent(std:: string student);
    void GetDataFile(std::string filename,  std::string filename2);
    void InitHeads();
};
