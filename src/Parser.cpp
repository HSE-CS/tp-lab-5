// Copyright 2021 mkhorosh
#include "Parser.h"
#include <fstream>

void parse_students(std::vector<std::string> &fios, std::vector<std::string> &ids, std::string file) {
  std::string line;
  std::vector<std::string> buff;
  std::ifstream in;
  in.open(file);
  while (getline(in, line)) {
    std::string id;
    int ind = line.find(' ');
    id = line.substr(0, ind);
    ids.push_back(id);
    std::string fio;
    fio = line.substr(ind + 1, line.size() - ind + 1);
    fios.push_back(fio);
  }
  in.close();
}

void parse_groups(std::vector<std::string> &titles, std::vector<std::string> &specs, std::string file) {
  std::string line;
  std::vector<std::string> buff;
  std::ifstream in(file);
  while (getline(in, line)) {
    std::string title;
    int ind = line.find(" ");
    title = line.substr(0, ind + 1);
    titles.push_back(title);
    std::string spec;
    spec = line.substr(ind + 1, line.size() - ind + 1);
    specs.push_back(spec);
  }
  in.close();
}
