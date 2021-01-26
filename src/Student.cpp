#include "Student.h"

Student:: void addmark(int value) {
  marks.push_back(value);
}

Student:: void addToGroup(string value)
{
  group = value;
}

Student:: float getAveragemark() {
    double mean = 0.0;
    for (auto x : marks) {
      mean += x;
  }

  return mean / marks.size();
 }

Student:: bool isHeadOfGroup() {
  return isHead;
}
