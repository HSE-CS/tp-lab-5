// Copyright 2021 Kris

#include "Deanary.h"
#include "Group.h"
#include "Student.h"

int main() {
    Deanary deanary;
    std::string filename("groupstitles.txt");
    deanary.createGroups(filename);
    deanary.printGroups();
    deanary.AddGroup("19pmi-2", "imics");
    Group gr = deanary.getLastGroup();
    Student st = Student(345, "Vasiya Pupkin");
    gr.addStudent(&st);
    deanary.AddGroup("18pmi-2", "imics");
    gr = deanary.getLastGroup();
    st = Student(543, "Liza Kraeva");
    gr.addStudent(&st);
    deanary.fireStudents();
    deanary.addMarksToAll();
    gr = deanary.getLastGroup();
    std::cout << gr.isEmpty()<< "\n";
    deanary.AddGroup("19pmi-2", "imics");
    deanary.printGroups();
    gr = deanary.getLastGroup();
    std::cout << gr.gettitle();
    std::string filename2("students.txt");
    deanary.hireStudents(filename2);
    st = Student(456, "Vasiya Pupkin");
    std::cout << st.getId()<< std::endl;
    st.addmark(5);
    st.addmark(4);
    std::cout << st.getAveragemark();

    return 0;
}