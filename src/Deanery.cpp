// Copyright 2021 Bogomazov
#include <vector>
#include <string>
#include <fstream>
#include "../include/Student.h"
#include "../include/Group.h"
#include "../include/Deanery.h"
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/writer.h"
#include "../include/rapidjson/stringbuffer.h"

std::vector<Student> Deanery::createStudentsFromFile(std::string fileName) {
    std::string myText;
    std::ifstream MyReadFile(fileName);

    while (std::getline(MyReadFile, myText)) {
        std::cout << myText;
    }

    MyReadFile.close();
    // rapidjson::Document d;
    // d.Parse(json);

    // rapidjson::Value& s = d["stars"];
    // s.SetInt(s.GetInt() + 1);
    std::vector<Student> students;
    return students;
}
// std::vector<Group> Deanery::createGroupsFromFile(std::string fileName) {

// }
// bool Deanery::saveData(std::string fileName) {

// }
