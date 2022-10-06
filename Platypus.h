/*-- Platypus.h ---------------------------------------------------------------
 
  This is a header file which creates the class Platypus.
  It has several member functions:

    Default constructor:  Initializes object's data members to default values
    Explicit constructor: each data member gets explicit value
    print:                Displaying information about object
    <<:                   Overloading Output operators
    accessors:            isAlive, isMutant, getName
    mutators:             setAge, setName
    Platypus functoins:   age_me, fight, eat, hatch

-------------------------------------------------------------------------*/
#include <iostream>

using namespace std; 

#ifndef PLATYPUS_H
#define PLATYPUS_H

class Platypus {

/*--------------Data members:--------------------*/

    float weight;
    short age;
    char name_initial;
    char gender;
    bool alive;
    bool mutant;

    public:
/*-----------------------------------Function members:-----------------------------------*/

/*----------constructors-----------*/
        Platypus();
/*----------------------------------------------------------------------
        Construct a default class object

        Precondition:  None
        Postcondition: Platypus object is initialized with assigning false to alive and mutant
        and 0 to weight and age and character '-' to gender and name_initial as default.
-----------------------------------------------------------------------*/
        Platypus(char, float, short, char);
/*----------------------------------------------------------------------
        Construct an explicit-value class object

        Precondition: values of passed parameters (gender, weight, age and name_initial)
        must preserve the class invariant.
        Postcondition: Data members gender, weight, age and name_initial have been
        initialized to gender, weight, age and name_initial respectively.
----------------------------------------------------------------------*/

/*----------setters-----------*/
        void setAge(short);
/*----------------------------------------------------------------------
    Sets the age of a Platypus object to stated value

    Preconditions: age >=0.

    Postcondition: Data member age is set to the value stored in passed parameter age.
----------------------------------------------------------------------*/
        void setName(char);
/*----------------------------------------------------------------------
    Sets the name_initial of a Platypus object to stated value

    Preconditions: ASCII code of character stored in parameter name_initial must be
    between 65 and 90, meaning, name_initial must be an alphabet letter from A-Z.

    Postconditon: Data member name_initial is set to the value stored in passed parameter name_initial.
----------------------------------------------------------------------*/

/*----------getters-----------*/
        bool isAlive() const;
/*----------------------------------------------------------------------
    Access the value stored in the alive data member

    Precondition:  None.
    Postcondition: Value stored in alive is returned.
-----------------------------------------------------------------------*/ 
        bool isMutant() const;
/*----------------------------------------------------------------------
    Access the value stored in the mutant data member 

    Precondition:  None.
    Postcondition: Value stored in mutant is returned.
-----------------------------------------------------------------------*/ 
        char getName() const;
/*----------------------------------------------------------------------
    Access the value stored in the name_initial data member

    Precondition:  None.
    Postcondition: Value stored in name_initial is returned.
-----------------------------------------------------------------------*/ 
        void print();
/*----------------------------------------------------------------------
    Display the information about Platypus object

    Precondition:  None.
    Postcondition: Specified data members' values are displayed using cout
-----------------------------------------------------------------------*/ 
        void age_me();
/*----------------------------------------------------------------------
    Increments the object's age. Include a 2% chance that the object will become a mutant.
    Plus, chances of platypus becoming dead increases according to the platypus' weight

    Precondition:  Platypus is not dead, meaning, data member alive is true.
    Postcondition: Object's age is incremented. Based on its weight and age Platypus' dying
    and mutating chances are calculated, respectively. Accordingly, alive's value may be
    changed and set to false or/and mutant's value may change and be set to false.
-----------------------------------------------------------------------*/ 
        void fight(Platypus &);
/*----------------------------------------------------------------------
    Calling platypus attacks the platypus passed as a parameter. Based on their weight and
    randomly selected number one survives and another one dies

    Precondition:  None of Platypuses are dead, meaning, both object's data member alive are true.
    Postcondition: One of the object's data member alive is set to false. No changes are made to
    another Platypus which is declared as survivor.
-----------------------------------------------------------------------*/ 
        void eat();
/*----------------------------------------------------------------------
    Increases the weight of the platypus by random selected amount based on its current weight 

    Precondition:  Platypus is not dead, meaning, data member alive is true.
    Postcondition: Object's data member weight is increased after calculations.
-----------------------------------------------------------------------*/ 
        void hatch();
/*----------------------------------------------------------------------
    creates new platypus with data member alive set to true, mutant set to false and age set to 0.
    Gender is initialized either to 'M' or 'F' randomly. Weight is randomly set to number between
    0.1 and 1.0 pounds. Name is provided by user or is just chosen randomly

    Precondition:  None.
    Postcondition: New object is constructed with explicit value constructor and all of its data
    members are set according to the function
-----------------------------------------------------------------------*/
};

ostream & operator<<(ostream &, Platypus);
/*------------------------------------------------------------------------
    Overloaded ouput operator

    Precondition:  The ostream object passed as a parameter is open.
    Postcondition: The Platypus object is inserted into ostream object (by member-function print()).
    Reference to ostream object is returned which makes chaining possible.
------------------------------------------------------------------------*/

#endif