#include "Deanery.h"

using namespace std;

int main() {
    Student student1 = Student(10, "abcd");
    Deanery deanery1;
    deanery1.CreateStudentsFromFile();
    deanery1.CreateGroupsFromFile();
    deanery1.RandMarks();
    deanery1.GetStat();
    return 0;
}