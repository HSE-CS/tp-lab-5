// Copyright 2021 mkhorosh
#ifndef INCLUDE_PARSER_H_
#define INCLUDE_PARSER_H_
#include <vector>
#include <string>

void parse_students(std::vector<std::string> *fios,
                    std::vector<std::string> *ids, std::string file);
void parse_groups(std::vector<std::string> *titles,
                  std::vector<std::string> *specs, std::string file);

#endif  // INCLUDE_PARSER_H_
