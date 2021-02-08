#include <iostream>
#include "deanery.h"

int main() {

    Student s1(1,"Aroslankin A.D.");

    Student s4(12,"Aroslankin A.D.");

    s1.addmark(5);


    s4.addmark(5);
    Group g1("PMI");
    Student s2(5,"Kuklin M.I.", &g1);
    s2.addmark(9);
    s2.attend(&g1);
    s1.attend(&g1);

    cout << s1.getavg() << " " << s2.getavg() << endl;
    g1.voting();
    cout << g1.get_head()->getfio() << endl;
    s2.attend(&g1);
    s4.attend(&g1);
    g1.voting();
    g1.exclude(&s4);
    g1.print();

    cout << endl;
    //g1.print();
    string  input= "/Users/artemaroslankin/Documents/Progacpp/deanary/groups.txt";
    string  output= "/Users/artemaroslankin/Documents/Progacpp/deanary/output.txt";




        Deanery balya(input);
        balya.print_groups();
        balya.print_students();
        balya.auto_exclude();
        //balya.exclude(1);
        cout <<"num of groups "<< balya.get_numOFgroups() << endl;
        balya.voting("g1");
        cout <<"num of st "<<  balya.get_numOFst() << endl;
        balya.transfer(1,"g2");
        balya.add_random_marks();
        balya.voting("g1");
        //balya.voting("g2");
        cout << "sad" <<endl;
        balya.refresh_file(output);
        cout << "sad" << endl;






    return 0;
}