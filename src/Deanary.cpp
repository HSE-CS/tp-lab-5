// Copyright 2021 Tatsenko Ilya
#include<fstream>
#include<ctime>
#include<clocale>
#include"Deanary.h"
#include"Group.h"
#include"Student.h"

void Deanary::HireStudents(std::string name) {
    srand(time(0));

    std::ifstream file(name);

    std::string string;
    std::string id;

    while (file >> id) {
        std::getline(file, string);
        Student* student = new Student(id, string);
        this->students.push_back(student);
        student->AddToGroup(this->groups[std::rand() % groups.size()]);
    }

    file.close();
}

void Deanary::CreateGroups(std::string file_name) {
    std::ifstream file(file_name);
    std::string str;
    std::string spec;

    while (file >> str) {
        std::getline(file, spec);
        Group* g = new Group(str, spec);
        this->groups.push_back(g);
    }
    file.close();
}

void Deanary::AddEvalsToAll() {
    srand(time(0));

    for (auto& x : students) {
      int random = rand() % 9 + 1;
        for (int i = 0; i != random; i++) {
            x->AddEval(rand() % 10 + 1);
        }
    }
}


void Deanary::InitHeads() {
    srand(time(0));
    for (auto& x : groups) {
        x->ChooseHeader(x->students[rand() % x->students.size()]);
    }
}

void Deanary::MoveStudents(std::string name , std::string grup) {
  for (auto& student : students) {
    if (name == student->fi) {
      for (auto& group : groups) {
        if (grup == group->title) {
          student->group->RemoveStudent(student);
          group->AddStudent(student);
          student->group = group;
          break;
        }
      }
    }
  }

}

void Deanary::FireStudent(std::string name) {
    Student* stud = nullptr;
    int k{0};
    for (auto &student : students) {
        if (student->fi == name) {
            student->group->RemoveStudent(student);
            students.erase(students.begin() + k);
            break;
        }
        k++;
    }
}



void Deanary::GetStatistic() {
    setlocale(LC_ALL, "rus");
    std::cout << "STATISTIC" << std::endl;
    std::cout << "-------------------------------------";
    std::cout << "GROUPS" << std::endl;

    for (auto& group : groups) {
        std::cout << "Title" << group->title << std::endl;
        std::cout << "Avarage Eval" << group->GetAvarageEval() << std::endl;
        std::cout << "Head" << group->head->fi << std::endl;
        std::cout << "---------------------------------";
        std::cout << "STUDENTS" << std::endl;
        for (auto& student : group->students) {
            std::cout << student->id << " " << student->fi;
            std::cout << " " << student->GetAvarageEval() << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}

void Deanary::GetDataFile(std::string name1, std::string name2) {
    std::ofstream file1;
    std::ofstream file2;

    file1.open(name1, std::ofstream::out | std::ofstream::trunc);
    file2.open(name2, std::ofstream::out | std::ofstream::trunc);

    for (auto& student : students) {
        file1 << student->id << " " << student->fi << std::endl;
    }
    for (auto& group : groups) {
        file2 << group->title << " " << group->spec << std::endl;
    }

    file1.close();
    file2.close();
}
