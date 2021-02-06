// Copyright 2020 Khoroshavina Ekaterina

#include "Deanary.h"

int main() {
    Group group1("19SE-1", "SE");
    Student student1(1, "Ivanov Ivan Sergeevich");
    student1.addToGroup(&group1);
    std::cout << student1.getGroup()->getTitle() << std::endl;
    std::cout << group1.getStudent(1)->getFIO() << std::endl << std::endl;
    Deanary deanary1;
    deanary1.addGroup(&group1);
    std::cout << deanary1.getGroups()[0]->getTitle() << std::endl;
    deanary1.addMarksToAll(10);
    deanary1.addMarksToAll(8);
    std::cout << group1.getStudent(1)->getAverageMark() << std::endl;
    deanary1.initHeads();
    deanary1.getStatistics();
    return 0;
}
