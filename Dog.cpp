/******************************************************************************
** Dog Class Implementation File
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/5/19
** Description: This is the class implementation file for the Dog class.
******************************************************************************/
#include "Dog.hpp"
#include <iostream>

/*****************************************************************************
 ** Dog() 
 ** Description: Constructor
 *****************************************************************************/
Dog::Dog()
{   
    name = "DOG NAME";
    row = 17;
    col = 76;
    avatar = 'Q'; 
    isAwake = true; 
}

/*****************************************************************************
 ** changeState(Space*) 
 ** Description: Changes to awake or asleep
 *****************************************************************************/
void Dog::changeState(Space*)
{   
    if(isAwake)  // If dog is awake
    {
        avatar = '@';  // Dog sleeps
        isAwake = false;

    }
    else
    {
        avatar = 'Q';  // Dog wakes
        isAwake = true;

    }

}
/*****************************************************************************
 ** wake(Space*) 
 ** Description: Dog wakes up and moves out of doorway
 *****************************************************************************/
void Dog::wake(Space* ptr) 
{
    if(!isAwake)
    {
        this->changeState(ptr); // Changes dog's avatar to awake to sleep
    
        if(ptr->moveDown(row, col, 3, avatar))  // If dog can move down 
        {
            this->updatePos(ptr);
        }
        else if(ptr->moveUp(row, col, 3, avatar))
        {
            this->updatePos(ptr);
        }
        else if(ptr->moveLeft(row, col, 3, avatar))
        {
            this->updatePos(ptr);
        }
        else
        {
            std::cout << "Error: couldn't move dog to wake position.\n";
        }
    }
}

/*****************************************************************************
 ** sleep(Space*) 
 ** Description: Dog goes to back to sleep at door to next room
 *****************************************************************************/
void Dog::sleep(Space* ptr)
{
    if(isAwake)
    {
        this->changeState(ptr);  // Changes dog's avatar to sleep
    }


    if(ptr->getMapName() != "Bedroom" && ptr->getMapName() != "Garden")
    {
        row = ptr->getNextRow();
        col = ptr->getNextCol();
        ptr->addChar(row, col, avatar);
    }
    else // It is the bedroom and garden.  Dog sleeps away from door
    {
        row = ptr->getNextRow() + 2;
        col = ptr->getNextCol();
        ptr->addChar(row + 2, col, avatar);
    }
}


/*****************************************************************************
 ** getIsAwake() 
 ** Description: Returns isAwake
 *****************************************************************************/
bool Dog::getIsAwake()
{
    return isAwake;
}
