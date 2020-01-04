/******************************************************************************
** Animal Class Implementation File
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/5/19
** Description: This file contains the implementation of the Animal class.
******************************************************************************/
#include "Animal.hpp"
#include <string>
    
/*****************************************************************************
 ** setRow(int) 
 ** Description: Sets row position
 *****************************************************************************/
void Animal::setRow(int row)
{   
    this->row = row;
}
    
/*****************************************************************************
 ** setCol(int) 
 ** Description: Sets column position
 *****************************************************************************/
void Animal::setCol(int col)
{   
    this->col = col;
}

/*****************************************************************************
 ** setName(std::string) 
 ** Description: Sets name
 *****************************************************************************/
void Animal::setName(std::string name)
{   
    this->name = name;
}
/*****************************************************************************
 ** getRow() 
 ** Description: Returns row position
 *****************************************************************************/
int Animal::getRow()
{   
    return row;
}
    
/*****************************************************************************
 ** getCol() 
 ** Description: Returns column position
 *****************************************************************************/
int Animal::getCol()
{   
    return col;
}

/*****************************************************************************
 ** getName() 
 ** Description: Returns name
 *****************************************************************************/
std::string Animal::getName()
{   
    return name;
}

/*****************************************************************************
 ** getAvatar() 
 ** Description: Returns avatar
 *****************************************************************************/
char Animal::getAvatar()
{   
    return avatar;
}

/*****************************************************************************
 ** updatePos()
 ** Description: Updates row and col of animal and removes avatar from previous 
 **              position on map
 *****************************************************************************/
void Animal::updatePos(Space* ptr)
{
    ptr->removeChar(row, col);
    row = ptr->getDestRow();
    col = ptr->getDestCol();     
    
}

/*****************************************************************************
 ** move(Space*, char, int) 
 ** Description: Moves Avatar designated number of spaces to direction if
 **              move method is successful
 **              a = Left, d = Right, w = Up, and s = Down
 *****************************************************************************/
void Animal::move(Space* ptr, char direction, int numSpaces)
{   
    switch(direction)
    {
        case 'a':
            if(ptr->moveLeft(row, col, numSpaces, avatar))
            {
                this->updatePos(ptr);
            }
            break;

        case 'd':
            if(ptr->moveRight(row, col, numSpaces, avatar))
            {
                this->updatePos(ptr);
            }
            break;

        case 'w':
            if(ptr->moveUp(row, col, numSpaces, avatar))
            {
                this->updatePos(ptr);
            }
            break;

        case 's':
            if(ptr->moveDown(row, col, numSpaces, avatar))
            {
                this->updatePos(ptr);
            }
    }
}
