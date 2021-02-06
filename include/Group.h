// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <cstdint>
#include <string>
#include <vector>

#include "Student.h"

class Deanary;  // Pre-announcement

class Group {
 private:
  std::string title;
  std::string spec;

  Student* head;
  std::vector<Student*> students;

  Deanary* deanary;

 public:
  Group(const std::string& title, const std::string& spec);

  // Setters
  void setStudents(const std::vector<Student*>&);
  void setDeanary(Deanary*);
  void setHead();

  // Changers
  void addStudent(Student&);
  void addStudent(Student*);
  void removeStudent(const Student*);
  void removeStudent(const Student&);
  void removeStudent(uint32_t id);
  void removeStudent(const std::string& name);

  // Getters
  const std::string& getTitle() const;
  const std::string& getSpec() const;
  const std::vector<Student*>& getStudents() const;
  const Student* getStudent(uint32_t id) const;
  const Student* getStudent(const std::string& name) const;
  const Deanary* getDeanary() const;
  const Student* getHead() const;
  double getMeanMark() const;
  std::string getInfo() const;  // for printing

  // Operators
  bool operator==(const Group&);
};

#endif  // INCLUDE_GROUP_H_
