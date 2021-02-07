// Copyright 2021 Egor Buzanov

#include "Deanary.h"

Deanary::Deanary() { id = 0; }

void Deanary::createGroups(std::string _filename) {
  std::ifstream input_file;
  input_file.open(_filename);
  std::string title, spec;

  input_file >> title;
  input_file >> spec;
  while (title != "" && spec != "") {
    groups.push_back(new Group(title, spec));
    title = "";
    spec = "";
    input_file >> title;
    input_file >> spec;
  }

  input_file.close();
}

void Deanary::hireStudents(std::string _filename) {
  std::ifstream input_file;
  input_file.open(_filename);
  std::string fio;

  for (auto &group : groups) {
    fio = "";
    input_file >> fio;
    while (fio != "" && fio != "-") {
      group->students.push_back(new Student(++id, fio));
      group->students.back()->AddToGroup(group);
      fio = "";
      input_file >> fio;
    }
  }

  input_file.close();
}

void Deanary::addMarksToAll() {
  std::random_device rd;
  std::mt19937 mersenne(rd());
  for (const auto &group : groups) {
    for (auto &student : group->students) {
      for (size_t i = 0; i < 10; i++) {
        student->AddMark(mersenne() % 11);
      }
    }
  }
}

void Deanary::getStatistics(std::string _filename) {
  std::ofstream output_file(_filename);

  for (const auto &group : groups) {
    output_file << group->title << " : " << group->spec << " "
                << group->getAverageMark() << std::endl;
    for (const auto &student : group->students) {
      output_file << student->id << " " << student->fio << " "
                  << student->getAverageMark() << std::endl;
    }
  }

  output_file.close();
}

void Deanary::MoveStudents(unsigned int _id, std::string _title) {
  Student *target_student = nullptr;
  Group *target_group = nullptr;

  for (auto &group : groups) {
    if (group->title == _title) {
      target_group = group;
    }
    if (group->getStudent(_id) != nullptr) {
      target_student = group->getStudent(_id);
    }
  }

  target_student->group->removeStudent(target_student);
  target_student->AddToGroup(target_group);
  target_group->AddStudent(target_student);
}

void Deanary::saveStaff(std::string _groups_filename,
                        std::string _students_filename) {
  std::ofstream output_groups_file(_groups_filename);
  std::ofstream output_students_file(_students_filename);
  for (const auto &group : groups) {
    output_groups_file << group->title << std::endl << group->spec << std::endl;
    for (const auto &student : group->students) {
      output_students_file << student->fio << std::endl;
    }
    output_students_file << "-" << std::endl;
  }
  output_groups_file.close();
}

void Deanary::initHeads() {
  for (auto &group : groups) {
    group->chooseHead();
  }
}

void Deanary::fireStudents() {
  for (auto &group : groups) {
    for (auto &student : group->students) {
      if (student->getAverageMark() < 3.50) {
        group->removeStudent(student);
      }
    }
  }
}

Group *Deanary::getGroup(std::string _title) {
  for (auto &group : groups) {
    if (group->title == _title) {
      return group;
    }
  }
  return nullptr;
}
