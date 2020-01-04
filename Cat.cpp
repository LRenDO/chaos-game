/******************************************************************************
** Cat Class Implementation File
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/5/19
** Description: This is the class implementation file for the Cat class.
******************************************************************************/
#include "Cat.hpp"
#include <iostream>

/*****************************************************************************
 ** Cat() 
 ** Description: Default Constructor
 *****************************************************************************/
Cat::Cat()
{   
    name = "Snowflake";
    row = 2;
    col = 34;
    avatar = '%';
    hasItem = false;
    maxCapacity = 2;
    chaos = 25;
}

/*****************************************************************************
 ** setChaos(int) 
 ** Description: Sets chaos points to parameter
 *****************************************************************************/
void Cat::setChaos(int points)
{
    chaos = points;
}

/*****************************************************************************
 ** bat(Space*, Dog*)
 ** Description: Moves item 1 space in direction passed or interacts with 
 **              space's special item
 *****************************************************************************/
void Cat::bat(Space* ptr, Dog* dog, char direction)
{   
    char item;

    switch(direction)
    {
        case 'a':
            item = ptr->getChar(row, col-1); // Get item on that space
            if(item == '*' || item == '.') // If bat-able item
            {
                if(ptr->moveLeft(row, col-1, 1, item))
                {
                    ptr->removeChar(row, col-1);
                    chaos += 1;
                }
            }
            else if(item == 'I') // If special item
            {
                ptr->interact(row, col-1);
                dog->wake(ptr);
            }
                break;
    
        case 'd':
            item = ptr->getChar(row, col+1); // Get item on that space
            if(item == '*' || item == '.') // If bat-able item
            {
                if(ptr->moveRight(row, col+1, 1, item))
                {
                    ptr->removeChar(row, col+1);
                    chaos += 1;
                }
            }
            else if(item == 'I') // If special item
            {
                ptr->interact(row, col+1);
                dog->wake(ptr);
            }
            break;
    
        case 'w':
            item = ptr->getChar(row-1, col); // Get item on that space
            if(item == '*' || item == '.') // If bat-able item
            {
               if(ptr->moveUp(row-1, col, 1, item))
                {
                    ptr->removeChar(row-1, col);
                    chaos += 1;
                }
            }
            else if(item == 'I') // If special item
            {
                ptr->interact(row-1, col);
                dog->wake(ptr);
            }
            break;
    
        case 's':
            item = ptr->getChar(row+1, col); // Get item on that space
            if(item == '*' || item == '.') // If bat-able item
            {
                if(ptr->moveDown(row+1, col, 1, item))
                {
                    ptr->removeChar(row+1, col);
                    chaos += 1;
                }
            }
            else if(item == 'I') // If special item
            {
                ptr->interact(row+1, col);
                dog->wake(ptr);
            }
         
    }

}

/*****************************************************************************
 ** pickUp(Space*, char) 
 ** Description: Changes hasItem to true and sets item
 *****************************************************************************/
void Cat::pickUp(Space* ptr, char direction)
{   
    char treat = '*';
    if(mouth.size() < maxCapacity)
    {
        switch(direction)
        {
            case 'a':
                if(ptr->getChar(this->row, this->col-1) == treat)
                {
                    ptr->removeChar(this->row, this->col-1);
                    mouth.push_back(treat);
                    hasItem = true;
                    // If target space is high space
                    if(ptr->onHighSpace(this->row, this->col-1))
                    {
                        ptr->popHighSpace();
                    }
                }
                break;
    
            case 'd':
                if(ptr->getChar(this->row, this->col+1) == treat)
                {
                    ptr->removeChar(this->row, this->col+1);
                    mouth.push_back(treat);
                    hasItem = true;
                    // If target space is high space
                    if(ptr->onHighSpace(this->row, this->col+1))
                    {
                        ptr->popHighSpace();
                    }
                }
                break;
    
            case 'w':
                if(ptr->getChar(this->row-1, this->col) == treat)
                {
                    ptr->removeChar(this->row-1, this->col);
                    mouth.push_back(treat);
                    hasItem = true;
                    // If target space is high space
                    if(ptr->onHighSpace(this->row-1, this->col))
                    {
                        ptr->popHighSpace();
                    }
                }
                break;
    
            case 's':
                if(ptr->getChar(this->row+1, this->col) == treat)
                {
                    ptr->removeChar(this->row+1, this->col);
                    mouth.push_back(treat);
                    hasItem = true;
                    // If target space is high space
                    if(ptr->onHighSpace(this->row+1, this->col))
                    {
                        ptr->popHighSpace();
                    }
                }
        }
    }
}

/*****************************************************************************
 ** drop(Space*, Dog*, char) 
 ** Description: Changes hasItem to false if was last item in mouth. If dropped
 **              on lure target space, dog comes in room and sleeps. If dropped
 **              in high space treat stays available
 *****************************************************************************/
void Cat::drop(Space* ptr, Dog* dog, char direction)
{     

    if(mouth.size() > 0)
    {
        char treat = mouth.back();

        switch(direction)
        {
            case 'a':
                // If target space is empty
                if(ptr->getChar(this->row, this->col-1) == ' ')
                {
                    mouth.pop_back();
                    // If target space is high space
                    if(ptr->onHighSpace(this->row, this->col-1))
                    {
                        ptr->addChar(this->row, this->col-1, treat);
                        ptr->pushHighSpace(treat);
                    }
                }
                // If target space is lure target
                else if(ptr->getChar(this->row, this->col-1) == 'O')
                {
                    mouth.pop_back();
                    dog->sleep(ptr);
                    ptr->removeChar(this->row, this->col-1);
                }
                break;
    
            case 'd':
                // If target space is empty
                if(ptr->getChar(this->row, this->col+1) == ' ')
                {
                    mouth.pop_back();
                    // If target is high space 
                    if(ptr->onHighSpace(this->row, this->col+1))
                    {
                        ptr->addChar(this->row, this->col+1, treat);
                        ptr->pushHighSpace(treat);
                    }
                }
                // If target space is lure target
                else if(ptr->getChar(this->row, this->col+1) == 'O')
                {
                    mouth.pop_back();
                    dog->sleep(ptr);
                    ptr->removeChar(this->row, this->col+1);
                }
                break;
    
            case 'w':
                // If target space is empty
                if(ptr->getChar(this->row-1, this->col) == ' ')
                {
                    mouth.pop_back();
                    // If target is high space 
                    if(ptr->onHighSpace(this->row-1, this->col))
                    {
                        ptr->addChar(this->row-1, this->col, treat);
                        ptr->pushHighSpace(treat);
                    }
                }
                // If target space is lure target
                else if(ptr->getChar(this->row-1, this->col) == 'O')
                {
                    mouth.pop_back();
                    dog->sleep(ptr);
                    ptr->removeChar(this->row-1, this->col);
                }
                break;
    
            case 's':
                // If target space is empty
                if(ptr->getChar(this->row+1, this->col) == ' ')
                {
                    mouth.pop_back();
                    // If target is high space 
                    if(ptr->onHighSpace(this->row+1, this->col))
                    {
                        ptr->addChar(this->row+1, this->col, treat);
                        ptr->pushHighSpace(treat);
                    }
                }
                // If target space is lure target
                else if(ptr->getChar(this->row+1, this->col) == 'O')
                {
                    mouth.pop_back();
                    dog->sleep(ptr);
                    ptr->removeChar(this->row+1, this->col);
                }
        }
    }
    if(mouth.size() == 0)
    {
        hasItem = false;
    }

}

/*****************************************************************************
 ** getHasItem() 
 ** Description: Returns true if cat is carrying item, empty if not
 *****************************************************************************/
bool Cat::getHasItem()
{
    return hasItem;
}

/*****************************************************************************
 ** getChaos() 
 ** Description: Returns chaos points
 *****************************************************************************/
int Cat::getChaos()
{
    return chaos;
}

/*****************************************************************************
 ** changeState() 
 ** Description: Changes cat avatar to caught 
 *****************************************************************************/
void Cat::changeState(Space* ptr)
{   
    avatar = 'x';  
    ptr->addChar(this->row, this->col, avatar);
}

/*****************************************************************************
 ** caught(Space*) 
 ** Description: Changes avatar on map to caught and human appears at door
 *****************************************************************************/
void Cat::caught(Space* ptr)
{
    std::string message = "The #@$%?!?! " + name + "!!!!\n" 
                        + "\n Your chaos needs practice.  Your human is home.\n"
                        + " Press enter to continue.\n";
    this->changeState(ptr);
    ptr->setMessage(message);
}

/*****************************************************************************
 ** printMouth() 
 ** Description: Prints contents of mouth
 *****************************************************************************/
void Cat::printMouth()
{   
    if(mouth.size() > 0)
    {
        auto pos = mouth.begin();
        while (pos != mouth.end())
        {
           std::cout << *pos << " ";
            pos++;
        }
    }
}
