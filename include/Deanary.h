//  Copyright 2020 GHA created by Klykov Anton

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include "Student.h"
#include "Group.h"
#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;
class Group;
class Deanary {
 private:
  std::vector<Group*> groups;
  class CreateGroup_F {
   private:
    std::vector<std::string> title_vector;

   public:
    std::vector<std::string> getTitle() {
      return this->title_vector;
    }
    void readFile() {
      std::ifstream fin("img/groups.json");
      json j;
      j = json::parse(fin);
      j["title"].get_to<std::vector<std::string>>(this->title_vector);
      fin.close();
    }
    Group* parseGroup() {
      static int iter{0};
      auto *gr_p = new Group(title_vector.at(iter));
      iter++;
      return gr_p;
    }
  };
  class CreateStudent_F {
   private:
    std::vector<std::string> fio_student;

   public:
    std::vector<std::string> getFio() {
      return this->fio_student;
    }
    void readFile() {
      std::ifstream oin("img/students.json");
      json j;
      j = json::parse(oin);
      j["fio"].get_to<std::vector<std::string>>(this->fio_student);
      oin.close();
    }
    Student* parseStudent() {
      static int it{0};
      auto* st_p = new Student(fio_student.at(it));
      it++;
      return st_p;
    }
  };

 public:
  void createGroups();
  void hireStudent();
  void addMarksToAll();
  void getStatistics();
  void moveStudent(int _id, int number_group);
  void initHeaders();
  void fireStudent(int _id);
  void fireBadStudents();
  int getAmountGroup();
  std::string getTitleGroup(int _num);
  int getAmountStudents(int _num);
  Group* getGroup(int _num);
};

#endif  // INCLUDE_DEANARY_H_
