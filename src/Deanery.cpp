#include "Deanery.h"

void Deanery::CreateStudentsFromFile() {
    std::ifstream file("Students.txt");
    std::string str;
    Group temp = Group("Temp");
    int tempID = 0;
    while (std::getline(file, str)) {
        Student student = Student(tempID, str);
        student.AddGroup(&temp);
        tempID++;
    }
    groups.emplace_back(temp);
    file.close();
}

void Deanery::CreateGroupsFromFile() {
    std::ifstream file("Groups.txt");
    std::string str;
    while(std::getline(file, str)) {
        Group group = Group(str);
        groups.emplace_back(group);
    }
    file.close();
}

const std::vector<Group>* Deanery::getGroups(){
    return &groups;
}

void Deanery::RandMarks() {
    srand(time(NULL));
    for(auto & group : groups) {
        for(int j = 0; j < group.getStudents()->size(); j++) {
            for(int k = 0; k < 10; k++) {
                group.getStudents()->operator[](j).AddMark(rand() % 10);
            }
        }
    }
}

void Deanery::GetStat() {
    for(auto & group : groups) {
        std::cout << "Group: " << group.getTitle() << "(average mark: " << group.CalcAverageMarkInGroup() << ")" << std::endl;
        for(int j = 0; j < group.getStudents()->size(); j++) {
            std::cout << "Student" << group.getStudents()->operator[](j).getId() << ": " << group.getStudents()->operator[](j).getFio() << "(average mark: " << group.getStudents()->operator[](j).CalcAverageMark() << ")" << std::endl;
        }
    }
}

void Deanery::ChangeGroup(Student *student, Group *group) {
    student->group = group;
    for(int i = 0; i < group->getStudents()->size(); i++) {
        if(student->id == group->getStudents()->operator[](i).id) {
            student->id++;
        }
    }
}

void Deanery::KickStudents() {
    for(auto & group : groups) {
        for(int j = 0; j < group.getStudents()->size(); j++) {
            if(group.getStudents()->operator[](j).CalcAverageMark() < 3.5) {
                group.getStudents()->erase(group.getStudents()->begin() + j);
            }
        }
    }
}

void Deanery::RefreshFiles() {
    std::ofstream file("Students.txt");
    for(auto & group : groups) {
        for(int j = 0; j < group.getStudents()->size(); j++) {
            file << group.getStudents()->operator[](j).getFio() << std::endl;
        }
    }
    file.open("Groups.txt");
    for(auto & group : groups) {
        if(group.getTitle() == "Temp")
            continue;
        else
            file << group.getTitle() << std::endl;
    }
    file.close();
}

