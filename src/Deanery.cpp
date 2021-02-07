// Copyright 2021 Bogomazov
#include <time.h>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <random>
#include <fstream>
#include "../include/Student.h"
#include "../include/Group.h"
#include "../include/Deanery.h"
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/writer.h"
#include "../include/rapidjson/stringbuffer.h"

std::vector<Student*> Deanery::createStudentsFromFile(std::string fileName) {
    std::ifstream ifs(fileName);
    std::string content((std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()));
    ifs.close();
    rapidjson::Document d;
    d.Parse(content.c_str());
    rapidjson::Value& jsonData = d["students"];
    std::vector<Student*> students;
    for (rapidjson::SizeType i = 0; i < jsonData.Size(); i++) {
        std::vector<int> marks;
        if (jsonData[i].HasMember("marks")) {
            for (rapidjson::SizeType j = 0;
                j < jsonData[i]["marks"].Size(); j++) {
                marks.push_back(jsonData[i]["marks"][j].GetInt());
            }
        }
        std::string fio = jsonData[i]["fio"].GetString();
        students.push_back(new Student(
            jsonData[i]["id"].GetInt(),
            fio,
            marks));
    }
    return students;
}

std::vector<Group*> Deanery::getGroups() {
    return _groups;
}
void Deanery::setGroups(std::vector<Group*> groups) {
    _groups = groups;
}

std::vector<Group*> Deanery::createGroupsFromFile(std::string fileName) {
    std::ifstream ifs(fileName);
    std::string content((std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()));
    ifs.close();
    rapidjson::Document d;
    d.Parse(content.c_str());
    rapidjson::Value& jsonGroups = d["groups"];
    std::vector<Student*> students = createStudentsFromFile(fileName);
    std::vector<Group*> groups;
    for (rapidjson::SizeType i = 0; i < jsonGroups.Size(); i++) {
        std::vector<Student*> grStud;
        Student *headman;
        for (rapidjson::SizeType j = 0;
                j < jsonGroups[i]["students"].Size(); j++) {
                int studId = jsonGroups[i]["students"][j].GetInt();
                for (unsigned int k = 0; k < students.size(); k++) {
                    if (students[k]->getId() == studId) {
                        grStud.push_back(students[k]);
                    }
                    if (students[k]->getId() ==
                        jsonGroups[i]["headId"].GetInt())
                        headman = students[k];
                }
            }
        Group *gr = new Group(
            jsonGroups[i]["title"].GetString(),
            jsonGroups[i]["spec"].GetString(),
            grStud,
            headman);
        groups.push_back(gr);
    }
    return groups;
}

void Deanery::printInfo() {
    std::string separator = "===================================";
    std::cout << separator  << std::endl;
    for (unsigned int i = 0; i != _groups.size(); ++i) {
        std::cout << "GROUP TITLE: " << _groups[i]->getTitle() << std::endl;
        std::cout << "GROUP SPEC: " << _groups[i]->getSpec() << std::endl;
        std::vector<Student*> students = _groups[i]->getStudents();
        std::cout << "STUDENTS OF GROUP: " << std::endl;
        for (unsigned int j = 0; j != students.size(); ++j) {
            std::cout << "    Id: " << students[j]->getId()
                << "\n    FIO: " << students[j]->getFio()
                << "\n    Mean of marks: " << students[j]->calculateMeanMark();
            if (_groups[i]->getHeadman()->getId() == students[j]->getId()) {
                std::cout << "\n    IS HEADMAN!";
            }
            std::cout << std::endl << std::endl;
        }
        std::cout << separator  << std::endl;
    }
}

void Deanery::addMarksToAll() {
    unsigned int seed = time(NULL);
    for (unsigned int i = 0; i != _groups.size(); ++i) {
        std::vector<Student*> students = _groups[i]->getStudents();
        for (unsigned int j = 0; j != students.size(); ++j) {
            int randMark = rand_r(&seed) % 10 + 1;
            students[i]->addMark(randMark);
        }
    }
}

std::vector<float> Deanery::getStatistics(bool byGroup) {
    std::vector<float> stats;
    if (byGroup) {
        for (unsigned int i = 0; i != _groups.size(); ++i) {
            int sum = 0;
            std::vector<Student*> students = _groups[i]->getStudents();
            for (unsigned int j = 0; j != students.size(); ++j) {
                sum += students[j]->calculateMeanMark();
            }
            float mean = static_cast<float>(sum) /
                static_cast<float>(students.size());
            stats.push_back(mean);
        }

    } else {
        for (unsigned int i = 0; i != _groups.size(); ++i) {
            std::vector<Student*> students = _groups[i]->getStudents();
            for (unsigned int j = 0; j != students.size(); ++j) {
                stats.push_back(students[j]->calculateMeanMark());
            }
        }
    }
    return stats;
}

void Deanery::fireStudents() {
    for (unsigned int i = 0; i != _groups.size(); ++i) {
        std::vector<Student*> students = _groups[i]->getStudents();
        for (unsigned int j = 0; j != students.size(); ++j) {
            if (students[j]->calculateMeanMark() < 4) {
                _groups[i]->removeStudentFromGroup(students[j]);
            }
        }
    }
}

void Deanery::moveStudents(Student *student, Group *newGroup) {
    student->getGroup()->removeStudentFromGroup(student);
    newGroup->addStudentToGroup(student);
}

bool Deanery::saveData(std::string fileName) {
    rapidjson::StringBuffer s;
    rapidjson::Writer<rapidjson::StringBuffer> writer(s);
    writer.StartObject();
    writer.Key("groups");
    writer.StartArray();
    for (unsigned int i = 0; i < _groups.size(); ++i) {
        writer.StartObject();
        writer.Key("title");
        writer.String(_groups[i]->getTitle().c_str());
        writer.Key("spec");
        writer.String(_groups[i]->getSpec().c_str());
        writer.Key("headId");
        writer.Uint(_groups[i]->getHeadman()->getId());
        writer.Key("students");
        writer.StartArray();
        std::vector<Student*> students = _groups[i]->getStudents();
        for (unsigned int j = 0; j != students.size(); ++j) {
            writer.Uint(students[j]->getId());
        }
        writer.EndArray();
        writer.EndObject();
    }
    writer.EndArray();
    writer.Key("students");
    writer.StartArray();
    for (unsigned int i = 0; i < _groups.size(); ++i) {
        std::vector<Student*> students = _groups[i]->getStudents();
        for (unsigned int j = 0; j != students.size(); ++j) {
            writer.StartObject();
            writer.Key("id");
            writer.Uint(students[j]->getId());
            writer.Key("fio");
            writer.String(students[j]->getFio().c_str());
            writer.Key("marks");
            writer.StartArray();
            for (unsigned int k = 0; k != students[j]->getMarks().size(); ++k) {
                writer.Uint(students[j]->getMarks()[k]);
            }
            writer.EndArray();
            writer.EndObject();
        }
    }
    writer.EndArray();
    writer.EndObject();

    std::ofstream file(fileName);
    std::string my_string = s.GetString();
    file << my_string;
    file.close();
    return true;
}
