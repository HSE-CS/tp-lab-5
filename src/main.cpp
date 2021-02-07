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
    // const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    // rapidjson::Document d;
    // d.Parse(json);

    // rapidjson::Value& s = d["stars"];
    // s.SetInt(s.GetInt() + 1);

    // rapidjson::StringBuffer buffer;
    // rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    // d.Accept(writer);

    // std::cout << buffer.GetString() << std::endl;
    std::vector<int> marksOne = {4, 6, 12};
    Student *st = new Student(123, "JijA", marksOne);
    std::string name = "Test";
    std::string spec = "JiJA";
    std::vector<Student*> students;
    students.push_back(st);
    Group gr = Group(name, spec, students);
    std::cout << gr.calculateMeanMark() << std::endl;
    // Deanery dnry = Deanery();
    return 0;
}
