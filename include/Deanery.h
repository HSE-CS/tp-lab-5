#include <vector>
#include <string>
#include <random>
#include "Group.h"

class Student;
class Group;

class Deanery {
private:
  int id;
  std:: vector<Group*> *groups;
public:
  Deanery(); // Done
  void createGroups(); // Done
  void hireStudents(); // Done
  void addMarksToAll(int value); // Done
  void getStatistics(); // Done
  void moveStudent(int student_id, std::string& title); // Done
  void moveStudent(std::string& student_fio, std::string& title); // Done
  // void saveStaff();
  void initHeads(); // Done
  void fireStudents(int student_id); //Doen
  void fireStudents(std::string& student_fio); // Done
  Group & getGroup(const std::string &title); // Done
  Group &groupByStudent(int _id); // Done
  Group &groupByStudent(const std::string& name); // Done
};
