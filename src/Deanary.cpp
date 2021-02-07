// Copyright 2021 Kasyanov
#include "../include/Deanary.h"

Deanary::Deanary(ReadGroup& reader, std::string spec) {
  groups = reader.CreateGroups(spec);
  InitHead();
}

void Deanary::AddMarksToAll(int marks_number) {
  for (auto group : groups) {
    for (auto student : group->students) {
      if (student->skill == ABILITY::OK) {
        for (int i = 0; i < marks_number; ++i) {
          int prob = rand() % 101 + 1;
          if (prob <= 20) {
            student->AddMark(2);
          } else if (prob > 20 && prob <= 70) {
            student->AddMark(3);
          } else if (prob > 70 && prob <= 90) {
            student->AddMark(4);
          } else {
            student->AddMark(5);
          }
        }
      }
      if (student->skill == ABILITY::GOOD) {
        for (int i = 0; i < marks_number; ++i) {
          int prob = rand() % 101 + 1;
          if (prob <= 5) {
            student->AddMark(2);
          } else if (prob > 5 && prob <= 15) {
            student->AddMark(3);
          } else if (prob > 15 && prob <= 75) {
            student->AddMark(4);
          } else {
            student->AddMark(5);
          }
        }
      }
      if (student->skill == ABILITY::EXCELLENT) {
        for (int i = 0; i < marks_number; ++i) {
          int prob = rand() % 101 + 1;
          if (prob <= 1) {
            student->AddMark(2);
          } else if (prob > 1 && prob <= 6) {
            student->AddMark(3);
          } else if (prob > 6 && prob <= 26) {
            student->AddMark(4);
          } else {
            student->AddMark(5);
          }
        }
      }
    }
  }
}

void Deanary::GetStatistics() const {
  for (auto group : groups) {
    auto students = group->GetAllStudents();
    for (auto student : students) {
      std::cout << "Student name - " << student->GetName() << '\n';
      std::cout << group->GetTitle() << '\n';
      std::cout << "Average mark - " << student->GetAverageMark() << '\n';
      std::cout << '\n' << '\n' << '\n';
    }
    std::cout << '\n' << '\n';
  }
}

void Deanary::MoveStudent(int id, std::string new_group_name) {
  Student* st;
  Group* old_group;
  Group* new_group = GetGroup(new_group_name);
  for (auto group : groups) {
    for (auto student : group->students) {
      if (student->id == id) {
        st = student;
        old_group = group;
      }
    }
  }
  old_group->RemoveStudent(st);
  if (st->IsHeadOfGroup()) {
    st->isHead = false;
    old_group->ChooseHead();
  }
  st->AddToGroup(new_group);
}

void Deanary::SaveStaff(const ReadGroup& reader) const {
  for (int i = 0; i < groups.size(); ++i) {
    std::ofstream output(reader.filenames[i]);
    for (auto student : groups[i]->students) {
      output << student->id << " " << student->fio << '\n';
    }
    output.close();
  }
}

void Deanary::InitHead() {
  for (auto group : groups) {
    group->ChooseHead();
  }
}

void Deanary::FireStudent(int id) {
  Group* gr;
  Student* st;
  for (auto group : groups) {
    for (auto student : group->students) {
      if (student->id == id) {
        st = student;
        gr = group;
        break;
      }
    }
  }
  gr->RemoveStudent(st);
  if (st->IsHeadOfGroup()) {
    gr->ChooseHead();
  }
  delete st;
}

Group* Deanary::GetGroup(std::string group_name) {
  for (auto group : groups) {
    if (group->title == group_name) {
      return group;
    }
  }
}

void Deanary::HireStudent(int id, std::string name, std::string group_name,
                          ABILITY skill) {
  Group* group = GetGroup(group_name);
  Student* new_student = new Student(id, name, group);
  new_student->skill = skill;
}
