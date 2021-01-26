#include <iostream>
#include <string>
#include <vector>

class Student {
 private:
  int id;
  std::string fio;
  std::string group;
  std::vector<int> marks;
  bool isHead;

  void addmark(int value);
  void addToGroup(const char* value);

 public:
  Student(const char* name);
  float getAveragemark();
  bool isHeadOfGroup();
};
