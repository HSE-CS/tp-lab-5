// Copyright 2020 Uskova
#include <iostream>
#include <fstream>
#include <algorithm>
#include "cmath"
#include "Deanary.h"

Deanary::Deanary() {
    std::vector<Group*> st;
    this->groups = st;
}

void Deanary::createGroups(const char* file, std::vector <Student*> students) {
    std::string line;
    std::ifstream in(file);
    std::string spec;
    int i = 0;
    int j = 0;
    if (in.is_open()) {
        while (getline(in, line)) {
            Group* group = new Group("1", line);
            groups.push_back(group);
        }
    }
    std::random_shuffle(students.begin(), students.end());
    int size_of_gr = floor(students.size()/groups.size()) + 1;
    if (size_of_gr > 25) {
        size_of_gr = 25;
    }
    while (i < students.size() && j < groups.size()) {
        while (groups[j]->students.size() < size_of_gr && i < students.size()) {
            this->groups[j]->addStudent(students.at(i));
            i += 1;
        }
        j += 1;
    }
    int counter = 1;
    int s = groups.size();
    while (i < students.size()) {
        int size = students.size() - i;
        counter += 1;
        char num[5];
        _itoa_s(counter, num, 10);
        std::string number(num);
        for (int k = 0; k < s; ++k) {
            Group* group = new Group(number, groups[k]->spec);
            this->groups.push_back(group);
        }
        size_of_gr = floor(size / s) + 1;
        while (i < students.size() && j < groups.size()) {
          while (groups[j]->students.size() < size_of_gr &&
              i < students.size()) {
                this->groups[j]->addStudent(students.at(i));
                i += 1;
          }
          j += 1;
        }
    }
    for (int k = 0; k < groups.size(); ++k) {
        if (groups[k]->isEmpty()) {
        groups.erase(groups.begin() + k, groups.begin() + groups.size());
            break;
        }
    }
    in.close();
}

std::vector<Student*> Deanary::hireStudents(const char* file) {
    setlocale(LC_ALL, "RUS");
    std::string line;
    std::ifstream in(file);
    std::vector<Student*> studs;
    int id = 1;
    if (in.is_open()) {
        while (getline(in, line)) {
            studs.push_back(new Student(id, line));
            id += 1;
        }
        return studs;
    } else {
        std::cout << "Error of opening the file";
    }
    in.close();
}

void Deanary::addMarks(int num_of_marks) {
  std::srand(time(0));
  std::srand(time(0));
  for (int i = 0; i < groups.size(); ++i) {
    for (int j = 0; j < groups[i]->students.size(); ++j) {
      for (int k = 0; k < num_of_marks; ++k) {
          int rand_mark = std::rand() % 10 + 1;
          this->groups[i]->students.at(j)->addMark(rand_mark);
      }
    }
  }
}

void Deanary::moveStudents(Student* st, Group* new_gr) {
  for (int i = 0; i < groups.size(); ++i) {
      if (groups[i] ->containsStudent(st)) {
          if (groups[i]->getHead() == st) {
              groups[i]->chooseRandHead();
          }
          groups[i]->removeStudent(st);
      }
  }
  new_gr->addStudent(st);
}

void Deanary::fireStudents() {
  for (int i = 0; i < groups.size(); ++i) {
    for (int j = 0; j < groups[i]->students.size(); ++j) {
      Student* st = groups[i]->students[j];
      if (st->getAverageMark() < 4.0) {
        if (groups[i]->getHead() == st) {
          groups[i]->chooseRandHead();
        }
        groups[i]->removeStudent(st);
      }
    }
  }
}


  void Deanary::initHeads() {
    for (int i = 0; i < groups.size(); ++i) {
       groups[i]->head = groups[i]->chooseRandHead();
    }
  }

  void Deanary::getStatistic(const char* file) {
    std::ofstream out_file(file);
    out_file.open(file);
    if (out_file.is_open()) {
      for (int i = 0; i < groups.size(); ++i) {
        out_file << "Group: " << groups[i]->title << ' ' << groups[i]->spec
                 << '\n';
        out_file << "Average mark: " << groups[i]->getAverageMark() << '\n';
        float min = 10.0;
        int min_ind = 0;
        float max = 0;
        int max_ind = 0;
        for (int j = 0; j < groups[i]->students.size(); ++j) {
          if (min > groups[i]->students[j]->getAverageMark()) {
            min = groups[i]->students[j]->getAverageMark();
            min_ind = j;
          }
          if (max < groups[i]->students[j]->getAverageMark()) {
            max = groups[i]->students[j]->getAverageMark();
            max_ind = j;
          }
        }
        out_file << "The worst student: " << groups[i]->students[min_ind]->id
                 << '  ' << groups[i]->students[min_ind]->fio << ": "
                 << groups[i]->students[min_ind]->getAverageMark() << '\n';
        out_file << "The best student: " << groups[i]->students[max_ind]->id
                 << '  ' << groups[i]->students[max_ind]->fio << ": "
                 << groups[i]->students[max_ind]->getAverageMark() << '\n';
        out_file << '\n' << '\n';
      }
    }
  }

  bool Deanary::saveChangesInFile(const char* file) {
    std::ofstream out_file(file);
    out_file.open(file);
    if (out_file.is_open()) {
      for (int i = 0; i < groups.size(); ++i) {
        out_file << "Group: " << groups[i]->title << ' ' << groups[i]->spec
                 << '\n';
        for (int j = 0; j < groups[i]->students.size(); ++j) {
          Student* st = groups[i]->students[j];
          out_file << st->id << '  ' << st->fio << ": " << st->getAverageMark()
                   << '\n';
        }
        out_file << '\n' << '\n';
      }
      return 0;
    }
    return 1;
  }


  void Deanary::showData() {
    for (int i = 0; i < groups.size(); ++i) {
      std::cout << "Group: " << groups[i]->title << ' ' << groups[i]->spec
               << std::endl;
      for (int j = 0; j < groups[i]->students.size(); ++j) {
        Student* st = groups[i]->students[j];
        std::cout << "   " << st->id << ' ' << st->fio << ": " <<
            st->getAverageMark() << std::endl;
      }
      std::cout << "Average mark: " << groups[i]->getAverageMark() << std::endl;
      std::cout << std::endl << std::endl;
    }
  }


  Student* Deanary::findId(int id) {
    Student* st = nullptr;
    for (int i = 0; i < groups.size(); ++i) {
      for (int j = 0; j < groups[i]->students.size(); ++j) {
        if (groups[i]->students[j]->id == id) {
          st = groups[i]->getStudent(id);
          break;
        }
      }
    }
    return st;
  }

  Student* Deanary::findFio(std::string fio) {
    Student* st = nullptr;
    for (int i = 0; i < groups.size(); ++i) {
      for (int j = 0; j < groups[i]->students.size(); ++j) {
        if (groups[i]->students[j]->fio == fio) {
          st = groups[i]->getStudent(fio);
          break;
        }
      }
    }
    return st;
  }

  Group* Deanary::findGr(std::string title, std::string spec) {
    Group* gr = nullptr;
    for (int i = 0; i < groups.size(); ++i) {
      if (groups[i]->title == title && groups[i]->spec == spec) {
         gr = groups[i];
        break;
      }
    }
    return gr;
  }

  int Deanary::return_gr_num() {
      return groups.size();
  }
