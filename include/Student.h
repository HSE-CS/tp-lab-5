#include <iostream>
#include <string>
#include <vector>

class Student {
 private:
  int id;
  std::string fio;
  std::string group;
  std::vector<int> marks;
  void addmark(int value);
  void addToGroup(const char* value);

 public:
  bool isHead;
  Student(const char* name);
  float getAveragemark();
  bool isHeadOfGroup();
};
