// Copyright 2021 KarMashanova
#include "Deanary.h"
#include <string>
#include <iostream>
#include <fstream>
#include <fstream>
#include <nlohmann/json.hpp>

void Deanary::createGroups() {
  std::string s;
  std::ifstream file("groups.txt");
  while (getline(file, s)) {
    std::string s2;
    getline(file, s2);
    Group gr(s, s2);
    groups.push_back(gr);
  }
}
