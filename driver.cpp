// Test driver for class Platypus

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime> // to have different seed and get different random numbers every time the program runs

using namespace std;

#include "Platypus.h"

int main() {

    srand(time(0));
    Platypus p1('M', 3.6, 4, 'T');
    cout << boolalpha << p1.isMutant() << endl;
    p1.print();
    Platypus p2;
    cout << boolalpha << p2.isAlive() << endl;
    p2.eat();
    p1.setName('A');
    p1.setAge(10);
    p1.age_me();
    cout << p1;
    Platypus p3('F', 5.3, 2, 'L');
    p3.hatch();
    cout << p3.getName() << endl;
    p3.eat();
    p1.fight(p3);


    return 0;

}