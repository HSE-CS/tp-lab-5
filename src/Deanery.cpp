#include "Deanery.h"

#include <cstdlib>
#include <fstream>
#include <iostream>

Deanery::Deanery() = default;

void Deanery::initFromFile(std::ifstream file) {
  enum State { TOP, GROUP, STUDENT };
  State state = TOP;
  std::string str_token;
  std::string extra_str_token;
  int num_token_extra;
  int num_token;
  int head_id;
  while (!file.eof()) {
    switch (state) {
      case TOP:
        str_token.clear();
        file >> str_token;
        if (str_token == "group") {
          state = GROUP;
        } else if (str_token.empty()) {
          break;
        } else {
          std::cerr << "expected 'group', got '" << str_token << "'\n";
          std::exit(1);
        }
        break;
      case GROUP:
        file >> str_token >> extra_str_token >> head_id;
        groups.emplace_back(str_token, extra_str_token);
        state = STUDENT;
        break;
      case STUDENT:
        file >> str_token;
        if (str_token == "endgroup") {
          for (auto& s : groups.back().students) {
            if (s.id == head_id) {
              groups.back().head = &s;
              break;
            }
          }
          state = TOP;
          break;
        }
        extra_str_token.clear();
        extra_str_token += str_token + " ";
        file >> str_token;
        extra_str_token += str_token + " ";
        file >> str_token;
        extra_str_token += str_token;
        file >> num_token;
        groups.back().students.emplace_back(num_token, extra_str_token);
        file >> num_token;
        for (int i = 0; i < num_token; ++i) {
          file >> num_token_extra;
          groups.back().students.back().addMark(num_token_extra);
        }
        break;
    }
  }
  for (auto& g : groups) {
    for (auto& s : g.students) {
      s.setGroup(&g);
    }
  }
}
void Deanery::printInfo() const {
  for (const Group& g : groups) {
    std::cout << "title: " << g.title << "\nspeciality: " << g.speciality
              << "\naverage mark: " << g.averageMark() << "\n";
    int head_id = -1;
    if (g.head != nullptr) head_id = g.head->id;
    for (const auto& s : g.students) {
      std::cout << "id: " << s.id << ", fio: " << s.fio
                << ", average mark: " << s.averageMark();
      if (head_id == s.id) std::cout << " (*)";
      std::cout << "\n";
    }
  }
}
void Deanery::removeFailingStudents() {
  for (auto& g : groups) {
    for (auto& s : g.students) {
      if (s.averageMark() < 4.0) {
        s.group->removeStudent(s.id);
      }
    }
  }
}
void Deanery::moveStudent(int id, const std::string& from_title,
                          const std::string& to_title) {
  Group* from_group = nullptr;
  Group* to_group = nullptr;
  for (Group& g : groups) {
    if (g.title == from_title) {
      from_group = &g;
    } else if (g.title == to_title) {
      to_group = &g;
    }
    if (from_group != nullptr && to_group != nullptr) {
      Student s = Student(*from_group->getStudentById(id));
      from_group->removeStudent(id);
      s.setGroup(to_group);
      to_group->addStudent(s);
      return;
    }
  }
}
void Deanery::reelectHeads() {
  for (auto& g : groups) {
    g.selectHead();
  }
}
void Deanery::saveToFile(std::ofstream file) const {
  for (const auto& g : groups) {
    file << "group " << g.title << " " << g.speciality << " "
         << (g.head == nullptr ? -1 : g.head->id);
    for (const auto& s : g.students) {
      file << "\n  " << s.fio << " " << s.id << " " << s.marks.size();
      for (auto m : s.marks) {
        file << " " << m;
      }
    }
    file << "\nendgroup\n";
  }
}
void Deanery::addGroup(Group& group) {
  groups.push_back(group);
  reelectHeads();
}
void Deanery::addStudentToGroup(Group* group, const Student& student) {
  group->addStudent(student);
}
void Deanery::addMarkToStudent(Student& student, int mark) {
  student.addMark(mark);
}
