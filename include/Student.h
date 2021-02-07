////// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <functional>
#include <ctime>
#include <cassert>

class UniqueID {
 protected:
  static int nextID;
 public:
  int id;
  UniqueID();
  UniqueID(const UniqueID &orig);
  UniqueID &operator=(const UniqueID &orig);
  [[nodiscard]] int getId() const;
};

struct PRNG {
  unsigned seed = 0;
};
void initGenerator(PRNG *generator);
unsigned random(PRNG *generator, unsigned minValue, unsigned maxValue);

class Group;
class Student {
  friend class Group;
  friend class Deanary;

 public:
  explicit Student(std::string newFio, UniqueID *newId);
  Student();
  ~Student();
  bool isHeadOfGroup();
  float getAverageMark();
  [[nodiscard]] int getStId() const;
  [[nodiscard]] std::string getStNamed() const;
  [[nodiscard]] std::string getStSpec() const;

 protected:
  static int nextID;

 private:
  int id;
  std::string fio;
  Group *group{};
  std::vector<int> marks;
  void addMarksInit(PRNG *generator, const std::string &whichMark);
  void addToGroup(Student *st, Group *gr);
  void addMark(int mark);
};

#endif  // INCLUDE_STUDENT_H_
