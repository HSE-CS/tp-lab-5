#include <iostream>
#include <string>
#include <vector>

class Group;

class Student {
  friend class Deanery;
 private:
  int id;
  std::string fio;
  Group * group;
  std::vector<int> marks;
  void addmark(int value);
  void addToGroup(Group * value);

 public:
  bool isHead;
  Student(int _id, std::string name);
  int getId();
  float getAveragemark();
  bool isHeadOfGroup();
  const std::string &getName() const;
};
