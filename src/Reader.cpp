//// Copyright 2021 Ozhiganova Polina
#include <sstream>
#include "reader/Reader.h"

std::map<std::string, std::string> Reader::parseGrSp
    (const json &file) {
  std::map<std::string, std::string> grSp;
  for (auto &el1 : file.items()) {
    std::string gr;
    std::string sp;
    std::string strGrSp = el1.key();
    int begSp = (el1.key().find('-'));
    gr.append(strGrSp, 0, begSp);
    sp.append(strGrSp, begSp + 1,
              strGrSp.size() - begSp);
    grSp[gr] = sp;
  }
  return grSp;
}

std::vector<std::vector<std::string>> Reader::parseFI
    (const json &file) {
  std::vector<std::string> fi;
  std::vector<std::vector<std::string>> finale;
  for (auto &el1 : file.items()) {
    for (auto &el2 : el1.value()) {
      std::string name = el2["name"];
      std::string surname = el2["surname"];
      std::string surnameName = surname + " " + name;
      fi.push_back(surnameName);
    }
    finale.push_back(fi);
    fi.clear();
  }
  return finale;
}

void Reader::saveStaff(Deanary *d, json &file) {
  std::map<std::string, std::vector
      <std::map<std::string, std::string>>> finale_data;
  std::vector<Group *> groups = d->getGroups();
  for (auto &gr : groups) {
    std::string grTitleSpec;
    grTitleSpec = gr->getTitle() + "-" + gr->getSpec();
    std::vector<std::map<std::string, std::string>> fioVec;
    std::vector<Student *> students = gr->getStudents();
    for (auto &st : students) {
      std::map<std::string, std::string> surnameName;
      std::string surname;
      std::string name;

      std::string fi = st->getStNamed();
      std::string word;
      std::istringstream iss(fi, std::istringstream::in);
      std::vector<std::string> fAndI;
      while (iss >> word) {
        fAndI.push_back(word);
      }
      surname = fAndI[0];
      name = fAndI[1];
      surnameName["surname"] = surname;
      surnameName["name"] = name;
      fioVec.push_back(surnameName);
    }
    finale_data[grTitleSpec] = fioVec;
    file[grTitleSpec] = fioVec;
  }
  std::ofstream o("output.json");
  o << file << std::endl;
}
