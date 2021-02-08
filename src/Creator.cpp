// Copyright Roman Balayan @ 2021

#include "../include/Creator.h"

std::unique_ptr<Deanary> Creator::fabricMethod(const std::string filename) {
    std::ifstream inp(filename);
    std::unique_ptr<Deanary> deanary(new Deanary);
    std::string line;
    std::shared_ptr<Group> group;
    std::getline(inp, line);
    std::getline(inp, line);
    std::string title = line.substr(0, line.find(':'));
    std::string spec = line.substr(line.find(':') + 1, line.size());
    group = std::make_shared<Group>(title, spec);
    while (std::getline(inp, line)) {
        if (line == "group") {
            deanary->addGroup(group);
            std::getline(inp, line);
            title = line.substr(0, line.find(':'));
            spec = line.substr(line.find(':') + 1, line.size());
            group = std::make_shared<Group>(title, spec);
            continue;
        }

        std::string stName = getName(line);
        std::vector<int16_t> stMarks = getMarks(line);
        std::shared_ptr<Student> student =
            std::make_shared<Student>(stName, stMarks);
        student->setGroup(group);
        group->addStudent(student);
    }
    deanary->addGroup(group);

    return deanary;
}

std::string Creator::getName(std::string str, std::string delimiter) const {
    return str.substr(0, str.find(delimiter));
}

std::vector<int16_t> Creator::getMarks(std::string str,
    std::string delimiter) const {
    std::vector<int16_t> res;
    std::string num;
    for (int i = str.find(delimiter) + 1; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            num += str[i];
        } else {
            res.push_back(atoi(num.c_str()));
            num.clear();
        }
    }
    if (!num.empty())
        res.push_back(atoi(num.c_str()));
    return res;
}
