// Copyright 2021 Bogomazov
#include <iostream>
#include <vector>
#include <string>
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/writer.h"
#include "../include/rapidjson/stringbuffer.h"
#include "../include/Student.h"
#include "../include/Group.h"
#include "../include/Deanery.h"

int main() {
    std::vector<int> marksOne = {1, 2, 3};
    Student *st = new Student(123, "JijA", marksOne);
    std::vector<Student*> students;
    students.push_back(st);
    Group *gr = new Group("test", "JiJA");
    st->enrollInGroup(gr);
    st->addMark(1);
    std::cout << st->calculateMeanMark() << std::endl;
    Deanery dn = Deanery();
    std::vector<Group*> groups = dn.createGroupsFromFile("test.json");
    dn.setGroups(groups);
    dn.printInfo();
    dn.saveData("output.json");
    return 0;
}
