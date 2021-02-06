// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <cstdint>
#include <string>
#include <vector>

class Group;  // Pre-announcement

class Student {
 private:
  uint32_t id;
  std::string name;
  std::vector<uint8_t> marks;

  Group* group;

 public:
  Student(uint32_t id, const std::string& name, Group* group = nullptr);
  Student(const Student&);

  // Setters
  void setGroup(Group* group);

  // Changers
  void addMark(uint8_t mark);

  // Gettters
  uint32_t getId() const;
  const std::string& getName() const;
  const std::vector<uint8_t>& getMarks() const;
  const Group* getGroup() const;
  double getMeanMark() const;
  std::string getInfo() const;  // for printing

  // Operators
  bool operator==(const Student&);
};

#endif  // INCLUDE_STUDENT_H_
