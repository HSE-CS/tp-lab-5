////// Copyright 2021 Ozhiganova Polina
#include <iostream>
#include "reader/Reader.h"

int main() {
  //  WORK WITH FILE
  Reader *r = new Reader;
  std::ifstream f("groups.json");
  if (!f.is_open()) {
    std::cout << "*** Error opening file ***";
    exit(1);
  }
  nlohmann::json jf = nlohmann::json::parse(f);
  f.close();
  //  PARSE DATA
  std::map<std::string, std::string> nameGrSp = r->parseGrSp(jf);
  std::vector<std::vector<std::string>> namesFI = r->parseFI(jf);
  //  CREATE DEANERY
  Deanary *d = new Deanary;
  //  CREATE GROUPS
  d->createGroups(nameGrSp, namesFI);
  //  GENERATE MARKS TO ALL ST-S
  d->addMarksToAll();
  // ADD MARK TO A CURTAIN STUDENT
  d->addMarkToSt(10, 1);
  /*       MOVE ST-S
   *  REWARD --> student av.mark is >= 8
   *  PUNISH --> student av.mark is < group av.mark
   *  FIRE --> student av.mark is <= 3
  */
  STATISTICS statistics1 = REWARD;
  d->getStatistics(statistics1);
  STATISTICS statistics2 = PUNISH;
  d->getStatistics(statistics2);
  STATISTICS statistics3 = FIRE;
  d->getStatistics(statistics3);
  //  NEW GROUPS SIZE
  d->printGroupSize();
  //  END OF WORK
  nlohmann::json finaleFile;
  r->saveStaff(d, finaleFile);
  //  CLEAN
  d->~Deanary();
  return 0;
}
