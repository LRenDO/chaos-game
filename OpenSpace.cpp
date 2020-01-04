/******************************************************************************
** OpenSpace Class Implementation File
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/7/19
** Description: This is the class implementation file for the OpenSpace class.
******************************************************************************/
#include "OpenSpace.hpp"
#include <string>

/*****************************************************************************
 ** OpenSpace() 
 ** Description: Constructor
 *****************************************************************************/
OpenSpace::OpenSpace(std::string mapName, int prevRow, int prevCol, 
    int nextRow, int NextCol): 
    Space(mapName, prevRow, prevCol, nextRow, NextCol)
{   
    isOpen = false;
}

/*****************************************************************************
 ** interact(int, int) 
 ** Description: Returns message depending on interaction.
 *****************************************************************************/
void OpenSpace::interact(int row, int col)
{
    if(isOpen)
    {
        message = "The " + item + " is already open.\n";
    }
    else
    {
        message = "Fwop! The " + item + " is open.";
        this->removeChar(row, col);
        isOpen = true;
    }
}

/*****************************************************************************
 ** getStatus() 
 ** Description: Returns isOpen
 *****************************************************************************/
bool OpenSpace::getStatus()
{
    return isOpen;
}
