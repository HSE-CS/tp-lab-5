// Copyright 2021 Artyom Lavrov


#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>
#include "Student.h"


class Group {
  private:
   std::string title;
   std::string specialization;
   std::vector<Student*> students;
   Student* head;

  public:
   Group(std::string title, std::string specialization);
   void chooseHead(Student* head);
   void addStudent(Student* student);
   double calculateAverageMark();
   void removeStudent(Student* student);

   Student* getStudent(std::string stId);
   Student* getHead() const;

   void setTitle(const std::string& title);
   void setSpecialization(const std::string& specialization);
   const std::vector<Student*>& getStudents() const;
   const std::string& getSpecialization() const;
   const std::string& GetTitle() const;

   virtual ~Group();
};

#endif  // INCLUDE_GROUP_H_
