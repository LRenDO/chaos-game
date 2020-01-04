/******************************************************************************
** Cat Class Declaration File 
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/5/19
** Descriptions: This is the class declartion file for the Cat Class.
******************************************************************************/

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Dog.hpp"
#include <vector>


// Cat Class Declarations
class Cat : public Animal 
{
    protected:
        bool hasItem;
        int chaos;
        std::vector<char> mouth; // Container for carrying objects in mouth
        unsigned maxCapacity; // Maximum container capacity

    public:
        Cat(); // Default Constructor
        virtual ~Cat() = default; // Use default destructor
        virtual void changeState(Space*); // Gets caught
        void setChaos(int points); // Sets chaos points
        void printMouth(); // Prints mouth contents
        void caught(Space* ptr); // Human appears avatar changes to caught state
        // Bats item 1 space.
        void bat(Space* ptr, Dog* dog, char direction); 
        // Sets item and mouthFull set to true
        void pickUp(Space* ptr, char direction); 
        // Returns item and mouthFull set to false
        void drop(Space* ptr, Dog* dog, char direction); 
        bool getHasItem(); // Returns mouthFull
        int getChaos(); // Returns chaos points

};

#endif
