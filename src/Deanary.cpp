// Copyright 2020 me
#include "..\include\Deanary.h"

unsigned getmark(unsigned short iq) {
  if (iq < 90) {
    return std::rand() % 5;
  }
  if (iq < 100) {
    return 6 + std::rand() % 4;
  } else {
    return 7 + std::rand() % 4;
  }
}

void Deanary::createGroups(std::string path) {
    std::ifstream read(path);
    nlohmann::json info;
    read >> info;
    auto mass = info.get<std::vector<nlohmann::json>>();
    for (const auto& v : mass) {
      auto title = v["group"].get<std::string>();
      auto spec = v["spec"].get<std::string>();
      Group* gr = new Group(spec, title);
      groups->push_back(gr);
    }
}

void Deanary::createGroups(std::string spec, std::string title) {
  Group* gr = new Group(spec, title);
  groups->push_back(gr);
}

void Deanary::hireStudents(std::string path, int num) {
  std::ifstream read(path);
  nlohmann::json info;
  read >> info;
  auto mass = info.get<std::vector<nlohmann::json>>();
  int count = 0;
  for (const auto& v : mass) {
    if (num != -1 && count == num) break;
    ++count;
    auto name = v["name"].get<std::string>();
    auto iq = v["iq"].get<unsigned int>();
    Student* st = new Student(name, iq);
    unsigned int gr_num = std::rand() % groups->size();
    groups->at(gr_num)->addStudent(st);
    st->addToGroup(groups->at(gr_num));
  }
}

void Deanary::addMarksToAll() {
  for (auto gr : *groups) {
    for (auto st : *gr->students) {
      st->addMark(getmark(st->iq));
    }
  }
}

void Deanary::getStatistics(std::string path) {
  std::ofstream out(path);
  for (auto gr : *groups) {
    out << "Group name: " << gr->title << "\nSpecializetion: " << gr->spec
        << "\nGroup size: " << gr->students->size()
        <<"\nAverage mark: "<< gr->getAveragemark() << "\n";
    double max_av = 0.0, min_av = 10.0;
    Student* best = nullptr;
    Student* worst = nullptr;
    unsigned less = 0, more = 0;
    for (auto st : *gr->students) {
      double av = st->getAveragemark();
      if (av >= 4.0) {
        ++more;
      } else {
        ++less;
      }
      if (av > max_av) {
        max_av = av;
        best = st;
      } else {
        if (av < min_av) {
          min_av = av;
          worst = st;
        }
      }
    }
    if (more != 0) {
      out << "Satisfactory: " << more << "\n";
    }
    if (less != 0) {
      out << "Not satisfactory: " << less << "\n";
    }

    if (best != nullptr) {
      out << "Best student: " << best->fio << " id: " << best->id
          << " Average:" << best->getAveragemark() << "\n";
    }
    if (worst != nullptr) {
      out << "Worst student: " << worst->fio << " id:" << worst->id
          << " Average: " << worst->getAveragemark() << "\n";
    }
    out << "\n\n";
  }
}

void Deanary::moveStudents(unsigned st_id, std::string gr_title) {
    Group* to = getGroupByTitle(gr_title);
    for (auto gr : *groups) {
      Student* st = gr->getStudentById(st_id);
      if (st != nullptr) {
         gr->removeStudent(st);
         to->addStudent(st);
      }
    }
}

Group* Deanary::getGroupByTitle(std::string title) {
    for (auto gr : *groups) {
      if (gr->title == title) {
         return gr;
      }
    }
    return nullptr;
}

void Deanary::saveStaff(std::string path) {
  std::ofstream out(path);
  for (auto gr : *groups) {
    out << gr->spec << " " << gr->title << "\nHead: "
        << gr->head->fio << " id: " << gr->head->id << "\nStudents:\n";
    unsigned count = 1;
    for (auto st : *gr->students) {
      out << count << ") " << st->fio << " id: " << st->id << " AM: "
          << st->getAveragemark() << "\n";
      count++;
    }
    out << "\n\n";
  }
}

void Deanary::initHeads() {
  for (auto gr : *groups) {
    gr->chooseHead();
  }
}

void Deanary::fireStudents(unsigned st_id) {
  for (auto gr : *groups) {
    Student* st = gr->getStudentById(st_id);
    if (st != nullptr) {
      gr->removeStudent(st);
    }
  }
}
