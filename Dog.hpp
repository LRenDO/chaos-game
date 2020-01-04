/******************************************************************************
** Dog Class Declaration File 
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/5/19
** Descriptions: This is the class declartion file for the DOg Class.
******************************************************************************/

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"


// Dog Class Declarations
class Dog : public Animal
{
    protected:
        bool isAwake;

    public:
        Dog(); // Default Constructor
        virtual ~Dog() =  default; // Use default destructor
        virtual void changeState(Space*); // Wakes up or goes to sleep
        void wake(Space* ptr); // Dog wakes up and moves out of doorway
        void sleep(Space* ptr); // Dog goes to back to sleep at exit
        bool getIsAwake(); // Returns isAwake
};

#endif
