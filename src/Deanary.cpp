////// Copyright 2021 Ozhiganova Polina
#include "Deanary.h"

Deanary::~Deanary() {
  for (auto &gr : groups) {
    gr->~Group();
  }
}

std::vector<Student *> Deanary::hireStudents
    (const std::vector<std::string> &namesFI) {
  std::vector<Student *> newStudents;
  for (auto &fi : namesFI) {
    UniqueID *newId = new UniqueID;
    Student *newSt = new Student(fi, newId);
    newStudents.push_back(newSt);
  }
  return newStudents;
}

void Deanary::createGroups(const std::map<std::string,
                                          std::string> &nameGrSp,
                           const std::vector
                               <std::vector<std::string>> &namesFI) {
  auto it = nameGrSp.begin();
  for (int i = 0; it != nameGrSp.end(); it++, i++) {
    Group *gr = nullptr;
    std::vector<Student *> newStudents;
    newStudents = hireStudents(namesFI[i]);
    Student *newHead = initHeads(gr, newStudents);
    Group *newGr = new Group(it->first, it->second,
                             newStudents, newHead);
    for (auto &st : newStudents) {
      st->addToGroup(st, newGr);
    }
    groups.push_back(newGr);
  }
}

void Deanary::addMarksToAll() {
  std::vector<int> marks;
  for (auto &gr : groups) {
    for (auto &st : gr->students) {
      sleep(1);
      PRNG *gen_low_mark = new PRNG;
      initGenerator(gen_low_mark);
      int low_mark = random(gen_low_mark, 1, 4);
      int high_mark = random(gen_low_mark, 8, 10);
      sleep(1);
      PRNG *generator = new PRNG;
      std::string whichMark = "normal";
      if (low_mark == 1) {
        whichMark = "low";
        st->addMarksInit(generator, whichMark);
      } else if (high_mark == 8) {
        whichMark = "high";
        st->addMarksInit(generator, whichMark);
      } else {
        st->addMarksInit(generator, whichMark);
      }
    }
  }
}

void Deanary::getStatistics(STATISTICS statistics) {
  if (statistics == FIRE) {
    std::vector<Student *> stsFire = getStatisticsFire();
    if (!stsFire.empty()) {
      std::cout << ">> Will be FIRED: " << stsFire.size()
                << " students." << std::endl;
      for (auto &st : stsFire) {
        std::cout << "NAME: " << st->getStNamed() << " ("
                  << st->getStSpec() << ") " << "   AVERAGE MARK: "
                  << st->getAverageMark() << "\n";
      }
      std::cout << std::endl;
      fireStudents(stsFire);
    }
  } else if (statistics == REWARD) {
    std::map<std::vector<Student *>, std::string> stsMove
        = getStatisticsReward();
    for (auto &obj1 : stsMove) {
      if (!obj1.first.empty()) {
        std::cout << std::endl << ">> Will be MOVED (Reward): " << std::endl;
        for (auto &el : stsMove) {
          for (auto &stName : el.first) {
            std::cout << "NAME: " << stName->getStNamed() << " ("
                      << stName->getStSpec() << ") " << "   AVERAGE MARK: "
                      << stName->getAverageMark() << std::endl;
          }
          std::cout << "MOVE TO: " << el.second << "\n\n";
          moveStudents(el.first, el.second);
        }
        break;
      }
    }
  } else if (statistics == PUNISH) {
    std::map<std::vector<Student *>, std::string>
        stsMove = getStatisticsPunish();
    for (auto &obj1 : stsMove) {
      if (!obj1.first.empty()) {
        std::cout << ">> Will be MOVED (Punish): " << std::endl;
        for (auto &el : stsMove) {
          for (auto &stName : el.first) {
            std::cout << "NAME: " << stName->getStNamed() << " ("
                      << stName->getStSpec() << ") "
                      << "   AVERAGE MARK: " << stName->getAverageMark()
                      << std::endl;
          }
          std::cout << "MOVE TO: " << el.second << "\n\n";
          moveStudents(el.first, el.second);
        }
        break;
      }
    }
  }
}

std::map<std::vector<Student *>,
         std::string> Deanary::getStatisticsReward() {
  std::vector<Student *> stsHigherBI;
  std::vector<Student *> stsHigherPMI;
  std::map<std::vector<Student *>, std::string> stsToGrMove;
  for (auto &gr : groups) {
    for (auto &st : gr->students) {
      // so-so --> move to higher group
      if (st->getAverageMark() >= 8) {
        if (st->group->spec == "PI") {
          continue;
        } else if (st->group->spec == "PMI") {
          stsHigherPMI.push_back(st);
        } else if (st->group->spec == "BI") {
          stsHigherBI.push_back(st);
        }
      }
    }
  }
  stsToGrMove[stsHigherPMI] = "PI";
  stsToGrMove[stsHigherBI] = "PMI";
  return stsToGrMove;
}

std::map<std::vector<Student *>,
         std::string> Deanary::getStatisticsPunish() {
  float generalAverageMark = 0.0;
  std::vector<Student *> stsLowerPI;
  std::vector<Student *> stsLowerPMI;
  std::map<std::vector<Student *>, std::string> stsToGrMove;
  for (auto &gr : groups) {
    generalAverageMark = gr->getAverageMark();
    for (auto &st : gr->students) {
      // so-so --> move to lower group
      if (st->getAverageMark() < generalAverageMark) {
        if (st->group->spec == "PI") {
          stsLowerPI.push_back(st);
        } else if (st->group->spec == "PMI") {
          stsLowerPMI.push_back(st);
        } else if (st->group->spec == "BI") {
          continue;
        }
      }
    }
  }
  stsToGrMove[stsLowerPI] = "PMI";
  stsToGrMove[stsLowerPMI] = "BI";
  return stsToGrMove;
}

std::vector<Student *> Deanary::getStatisticsFire() {
  std::vector<Student *> stsToFire;
  for (auto &gr : groups) {
    for (auto &st : gr->students) {
      // very bad marks  --> fire
      if (st->getAverageMark() <= 3) {
        stsToFire.push_back(st);
      }
    }
  }
  return stsToFire;
}

void Deanary::moveStudents(const std::vector<Student *> &sts,
                           const std::string &newGr) {
  std::vector<Student *> stsToMove;
  Group *newGroup;
  for (auto &gr : groups) {
    if (gr->spec == newGr) {
      newGroup = gr;
      break;
    }
  }
  for (auto &st : sts) {
    Student *stMove = new Student;
    //  save all info
    stMove->id = st->id;
    stMove->fio = st->fio;
    stMove->group = newGroup;
    stMove->marks = st->marks;
    //  del from group
    st->group->removeStudent(st->id);
    //  add to new
    newGroup->addStudent(stMove, newGroup);
  }
}

void Deanary::fireStudents(const std::vector<Student *> &sts) {
  for (auto &st : sts) {
    Group *gr = st->group;
    gr->removeStudent(st->id);
  }
}

Student *Deanary::initHeads
    (Group *gr, const std::vector<Student *> &newStudents) {
  return gr->chooseHead(newStudents);
}

std::vector<Group *> Deanary::getGroups() {
  return this->groups;
}

void Deanary::printGroupSize() {
  std::vector<Group *> grs = getGroups();
  for (auto &gr : grs) {
    std::cout << "GROUP: " << gr->getSpec()
              << "   SIZE: " << gr->getStudents().size()
              << std::endl;
  }
  std::cout << std::endl;
}

void Deanary::addMarkToSt(int mark, int stId) {
  Student *st = nullptr;
  for (auto &gr : groups) {
    st = gr->getStudent(stId);
    if (st) {
      break;
    }
  }
  st->addMark(mark);
}

int Deanary::getGrsSize() {
  return this->getGroups().size();
}
