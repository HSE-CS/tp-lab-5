// Copyright 2021 Artem Danyaev
#include "Deanary.h"

void Deanary::createGroupsFromFile(std::string path) {
  std::ifstream file(path);
  std::string s;

  while (std::getline(file, s)) {
    int pos = s.find(' ');
    std::string name = s.substr(0, pos);
    std::string spec = s.substr(pos + 1);
    groups.push_back(new Group(name, spec));
  }
  file.close();
}

void Deanary::createGroup(std::string title, std::string spec) {
  groups.push_back(new Group(title, spec));
}

void Deanary::hireStudent(std::string fio, std::string groupTitle) {
  for (Group *group : groups) {
    if (group->title == groupTitle) {
      group->addStudent(new Student(idCounter, fio));
      idCounter++;
      break;
    }
  }
}

Group *Deanary::getGroup(std::string title) {
  for (Group *group : groups) {
    if (group->title == title) {
      return group;
    }
  }
  return nullptr;
}

void Deanary::hireStudentsFromFile(std::string path) {
  std::ifstream file(path);
  std::string s;

  while (std::getline(file, s)) {
    int pos = s.rfind(' ');
    std::string fio = s.substr(0, pos);
    std::string group = s.substr(pos + 1);
    for (Group *gr : groups) {
      if (gr->title == group) {
        gr->addStudent(new Student(idCounter, fio));
        idCounter++;
        break;
      }
    }
  }
}

void Deanary::addMarksToAll() {
  std::srand(static_cast<unsigned int>(time(0)));
  for (Group *group : groups) {
    for (Student *student : group->students) {
      for (int i = 0; i < 10; i++) {
        student->addMark(std::rand() % 5 + 1);
      }
    }
  }
}

void Deanary::getStatistics(std::string path) {
  std::ofstream file(path);
  for (Group *group : groups) {
    file << "Group title: " << group->title
         << " Specialization: " << group->spec << '\n';
    if (group->head) {
      file << "Head: " << group->head->fio << '\n';
    }
    file << "Group average mark: " << group->getAverageMark() << '\n';
    for (Student *student : group->students) {
      file << student->fio << " Average mark: " << student->getAverageMark()
           << '\n';
    }
  }
  file.close();
}

void Deanary::moveStudent(Student *student, std::string name) {
  for (Group *group : groups) {
    if (group->title == name) {
      Student *st = new Student(student->id, student->fio);
      for (unsigned int mark : student->marks) {
        st->addMark(mark);
      }
      group->addStudent(st);
      break;
    }
  }
  student->group->removeStudent(student->id);
}

void Deanary::saveStuff(std::string path) {
  std::ofstream file(path);
  for (Group *group : groups) {
    file << "Group title: " << group->title
         << " Specialization: " << group->spec << '\n';
    if (group->head) {
      file << "Head: " << group->head->fio << '\n';
    }

    for (Student *student : group->students) {
      file << student->id << ' ' << student->fio << ' ';
      for (int i = 0; i < student->marks.size(); i++) {
        file << student->marks[i];
      }
      file << '\n';
    }
    file << '\n';
  }
  file.close();
}

void Deanary::initHeads() {
  for (Group *group : groups) {
    Student *newhead = nullptr;
    float max = 0;
    for (Student *student : group->students) {
      if (student->getAverageMark() > max) {
        max = student->getAverageMark();
        newhead = student;
      }
    }
    group->head = newhead;
  }
}

void Deanary::fireStudents(std::vector<Student *> &students) {
  for (Student *student : students) {
    student->group->removeStudent(student->id);
  }
}
