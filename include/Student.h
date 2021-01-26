#include <iostream>
#include <string>
#include <vector>

class MyStack {
 private:
  int id;
  string fio;
  string group = "";
  vector<int> marks;
  bool isHead = false;

  void addmark(int value);
  void addToGroup(string value);

 public:
  float getAveragemark();
  bool isHeadOfGroup();
