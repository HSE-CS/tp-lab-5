// Copyright 2021 Nikita Naumov
#include "Student.h"
#include "Group.h"

void delimiter() {
  std::cout << "=========================================\n";
}

int main() {
  Group group((std::string)"19PMI");
  //that all work
  Student test1(0, (std::string) "Name Surname");
  test1.getInfo();
  delimiter();
  test1.printMarks();
  delimiter();
 /* for (size_t i = 0; i < 5; ++i) {
    test1.addMarkToStudent(rand()%11);
  }*/
  //test1.printMarks();
  //std::cout << test1.getAverageMark() << std::endl;
  //std::cout << std::endl;
  //test1.addToGroup(&group);
  //=================================================
  group.printInfoAboutGroup();  //working
  delimiter();
  group.addStudentToGroup(&test1);  // working
  test1.getInfo();                  // working
  delimiter();
  group.printInfoAboutGroup();  // working
  delimiter();
  std::cout << group.getTitle() << std::endl;  // working
  delimiter();
  std::cout << "====TEST OF .FINDSTUDENTBY...()\n\n";
  std::cout << "Is Name Surname in the group? ";
  std::cout << group.findStudentByFIO((std::string) "Name Surname")
            << std::endl;  // working
  delimiter();
  std::cout << "Is Nam Surname in the group? ";
  std::cout << group.findStudentByFIO((std::string) "Nam Surname") 
            << std::endl;  // working
  delimiter();
  std::cout << "Is student with ID = 0 in the group? ";
  std::cout << group.findStudentByID(0) << std::endl;  // working
  delimiter();
  std::cout << "Is student with ID = 1 in the group? ";
  std::cout << group.findStudentByID(1) << std::endl;  // working
  delimiter();
  std::cout << "\n\n";
  std::cout << "===TEST OF .SETHEAD()\n";
  group.setHead(&test1);  
  test1.getInfo();  // working
  delimiter();
  group.printInfoAboutGroup();  // working
  delimiter();
  std::cout << "===TEST OF .GETAVERAGEGROUPMARK()\n";
  std::cout << "*add second student\n";
  Student test2(1, "Nam Surname");
  group.addStudentToGroup(&test2);
  group.printInfoAboutGroup();  // working
  delimiter();
  std::cout << "If students in the group have no marks average mark is ";
  std::cout << group.getAverageGroupMark() << std::endl;  // working
  delimiter();
  for (size_t i = 0; i < 5; ++i) {
    test1.addMarkToStudent(i + 5);
    test2.addMarkToStudent(i + 3);
  }
  std::cout << "If students in the group have marks average mark is ";
  std::cout << group.getAverageGroupMark() << std::endl;  // working
  delimiter();
  std::cout << "\n\n";
  std::cout << "===Test of changing head of group\n";
  group.setHead(&test2);  //fully working
  group.printInfoAboutGroup();  // working
  delimiter();
  test1.getInfo();  //working
  delimiter();
  test2.getInfo();  //working
  delimiter();
  std::cout << "\n\n";
  std::cout << "===TEST OF .FIRESTUDENTFROMGROUP\n";
  std::cout << "===Fire regular student\n";
  group.fireStudentFromGroup(0);
  group.printInfoAboutGroup();  // working
  delimiter();
  test1.getInfo();  // working
  delimiter();
  test2.getInfo();  // working
  delimiter();
  std::cout << "\n\n";
  group.addStudentToGroup(&test1);
  group.printInfoAboutGroup();  // working
  delimiter();
  test1.getInfo();  // working
  delimiter();
  test2.getInfo();  // working
  delimiter();
  std::cout << "\n";
  std::cout << "===Fire head of group\n";
  group.fireStudentFromGroup(1);
  group.printInfoAboutGroup();  // working
  delimiter();
  test1.getInfo();  // working
  delimiter();
  test2.getInfo();  // working
  delimiter();


  return 0;
}