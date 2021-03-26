#include <fstream>

#include "Deanery.h"

int main() {
  Deanery d;
  d.initFromFile(std::ifstream("../db"));
  d.printInfo();
  d.saveToFile(std::ofstream("../db2"));
  return 0;
}