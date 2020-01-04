/******************************************************************************
** Animal Class Declaration File 
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/5/19
** Descriptions: This is the class declartion file for the Animal Class.
******************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include "Space.hpp"
#include <string>

// Animal Class Declarations
class Animal
{
    protected:
        int row; // Current Row Postion
        int col; // Current Column Position
        char avatar; // Appearance on board
        std::string name;  // Name of animal

    public:
        Animal() = default; // Default Constructor
        virtual ~Animal() = default; // Use default destructor
        
        void setRow(int);
        void setCol(int); 
        void setName(std::string); 
 
        int getRow(); 
        int getCol(); 
        std::string getName(); 
        char getAvatar(); 

        // Dog changes state to asleep or awake, changes cat state to caught
        virtual void changeState(Space*) = 0; 
        void move(Space* ptr, char direction, int numSpaces);
        void updatePos(Space* ptr);

};

#endif
