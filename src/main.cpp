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
    Deanery dn = Deanery();
    std::vector<Group*> groups = dn.createGroupsFromFile("input.json");
    dn.setGroups(groups);
    dn.printInfo();
    dn.saveData("output.json");
    return 0;
}
