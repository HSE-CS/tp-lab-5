#include"Deanary.h"

int main() {
  std::ifstream file("groups.txt");
  Deanary hse(std::move(file));
  hse.createGroup();
  hse.addMarksToAll(5, "19E5");
  hse.addMarksToAll(4, "19PI-1");
  hse.addMarksToAll(3, "19FM");
  hse.getStudent("Barinova Ksenia Vladimirovna", "19E5")->addmark(2);
  hse.getStudent("Gryaznova Marina Dmitrievna", "19E5")->addmark(4);
  hse.getStudent("Gryzlov Vladislav Igorevich", "19FM")->addmark(2);
  hse.getStudent("Levin Gleb Sergeevich", "19FM")->addmark(5);
  hse.getStudent("Dumarevskaya Tatyana Nikolaevna", "19PI-1")->addmark(5);
  hse.getStudent("Nikolaeva Olesya Igorevna", "19PI-1")->addmark(5);
  hse.getStudent("Emshanov Pavel Andreevich", "19PI-1")->addmark(5);
  Student student("19E524", "Ivanov Ivan Andreevich");
  hse.hireStudents(&student, "19E5");
  student.addmark(3);
  hse.fireStudents("Medvedeva Arina Andreevna", "19FM");
  hse.getStatistic();
  hse.initHeads("19E5", "Vinokurova Alyona Igorevna");
  hse.initHeads("19PI-1", "Safronov Ivan Dmitrievich");
  hse.initHeads("19FM", "Dragunova Ksenia Aleksandrovna");
  hse.moveStudents("Pashin Anton Nikolaevich", "19FM", "19E5");
  hse.saveStaff();
  return 0;
}