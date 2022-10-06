/*-- Platypus.cpp------------------------------------------------------------
 
   This cpp file implements the member functions of the class Platypus.

-------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip> // for outputing information more clearly with using the function setw()
#include <cstdlib> // for generating random numbers

using namespace std;

#include "Platypus.h"

// Definition of default constructor

Platypus::Platypus() {
    alive = false;
    age = 0;
    weight = 0;
    mutant = false;
    gender = '-';
    name_initial = '-';
}

// Definition of explicit-value constructor

Platypus::Platypus(char gender, float weight, short age, char name_initial) {
    if (gender == 'M' || gender == 'F' || gender =='m' || gender == 'f') {
        this->gender = gender;
    }else {
        cerr << "Wrong gender. Input 'M' or 'm' for male and 'F' or 'f' for female" << endl;
    }
    if (weight > 0) {
        this->weight = weight;
    }else {
        cerr << "Please input valid weight" << endl;
    }
    if (age >= 0) {
        this->age = age;
    }else {
        cerr << "Incorrect age. Please provide valid value" << endl;
    }
    if ((int)name_initial >= 65 && (int)name_initial <= 90) {
        this->name_initial = name_initial;
    }else {
        cerr << "You're trying to write symbol or number. Please only enter first letter of name" << endl;
    }
    alive = true;
    mutant = false;
}

// Implementation of setAge function

void Platypus::setAge(short age) {
    if (age >= 0) {
        this->age = age;
    }else {
        cerr << "Please enter valid age" << endl;
    }
}

// Implementation of setName function

void Platypus::setName(char name_initial) {
    if (!cin.fail() && (int)name_initial >= 65 && (int)name_initial <= 90) {
        this->name_initial = name_initial;
    }else {
        cerr << "Error. Trying to input symbol or number as a name" << endl;
    }
}

// Implementation of isAlive()

bool Platypus::isAlive() const {
    return alive;
}

// Implementation of isMutant()

bool Platypus::isMutant() const {
    return mutant;
}

// Implementation of getName()

char Platypus::getName() const {
    return name_initial;
}

// Implementation of print()

void Platypus::print() {
    cout << "Name: " << setw(10) << name_initial << endl;
    cout << "Age: " << setw(11) << age << endl;
    cout << "Gender: " << setw(8) << gender << endl;
    cout << "Weight: " << setw(8) << weight << endl;
    cout << "Is alive: " << setw(6) << boolalpha << alive << endl;
    cout << "Is mutant: " << boolalpha << mutant << endl; // boolalpha converts 1 and 0 to true and false, respectively
}

// Implementation of age_me()

void Platypus::age_me() {
    if(alive == true) {
        age++;
        int temp; // variable for storing randomly chosen integer
        temp = rand()%50 + 1;
        if (temp == 2) {
            mutant = true;
        }
        if (weight < 10) {
            temp = rand()%100 + 1;
            if (temp <= weight*10) {
                alive = false;
            }
        }else {
            alive = false;
        }
    }else {
        cout << "Sorry. Dead platypuses can't age" << endl;
    }
}

void Platypus::fight(Platypus &other) {
    if(this->alive == true && other.alive == true) {
        int temp = rand()%100 + 1;
        double fight_ratio = (this->weight/other.weight) * 50;
        if (temp < fight_ratio) {
            other.alive = false;
        }else {
            this->alive = false;
        }
    }else {
        cout << "Dead platypuses can't fight!" << endl;
    }
}

void Platypus::eat() {
    if (alive == true) {
        double temp = rand()%50 + 1; // temp's type is double to avoid integer by integer division which truncates the result
        weight += (weight*(temp/10))/100; // since temp gets value between 1-50, it's divided by 10 to obtain interval of 0.1-5
    }else {
        cout << "Dead platypuses can't eat" << endl;
    }
}

void Platypus::hatch() {
    if (alive == true) {
        char newborn_gender;
        int temp = rand()%2;
        if (temp==0) {
            newborn_gender = 'F';
        }else {
            newborn_gender = 'M';
        }
        float newborn_weight;
        float tempo = rand()%10 + 1; // new temporary variable of float for storing randomly chosen integer to avoid semantic error due to int by int division
        newborn_weight = tempo/10; // since temp gets value between 1-10, it's divided by 10 to obtain interval of 0.1-1
        int choice;
        char newborn_name;
        char temp_name;
        do {
            cout << "Enter 0 if you want to choose name of the platypus or 1 to assign it randomly: ";
            cin >> choice; // user chooses whether she/he wants to decide name of platypus or let it be assigned randomly
            if (choice == 0) {
                cout << "Enter initial of your platypus' name: ";
                cin >> temp_name;
                if (!cin.fail() && (int)temp_name >= 65 && (int)temp_name <= 90) {
                    newborn_name = temp_name;
                }else {
                    cerr << "Error. Trying to input symbol or number as a name" << endl;
                    cin.clear(); // cleaning cin to let I/O streams work correctly next time
                    choice = -1;
                }
            }else if (choice == 1) {
                temp = rand()%26 + 65;
                newborn_name = (char)temp;
            }else {
                cout << "Error. Please read the statement and enter 0 or 1 accordingly" << endl;
            }
        } while(choice != 0 && choice != 1);
        Platypus newP(newborn_gender, newborn_weight, 0, newborn_name); // newborn platypus is constructed by explicit-value constructor
        cout << "New Platypus is created" << endl;
    }else {
        cout << "Dead platypus can't hatch" << endl;
    }
}

ostream & operator<<(ostream& out, Platypus p1) {
    p1.print();
    return out; // reference of ostream object (out) is returned to make chaining available
}