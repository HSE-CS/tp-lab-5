// Copyright 2021 shaidi

#define DEANARY_H
#ifdef DEANARY_H
#include <time.h>
#include <iostream>
#include "Group.h"
#include "Student.h"
#include <sstream>
#include <string>
#include <vector>
#include <fstream>


class Student;
class Group;

class Deanary {

 private:
  std::vector<Group*> groups;
  unsigned int dean_id;

 public:

  Deanary();
  void add_groups(std::string fios_input, std::string groups_input); 
  void change_group(std::string fio, std::string previous_group,
                    std::string new_group);  
  void heads_choice();                       
  void set_random_marks(unsigned int num);
  void get_statistics() const; 
  void remove_students(); 
  void new_data(std::string students, std::string groups) const; 

};

#endif  // DEANARY_H
