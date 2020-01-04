/******************************************************************************
** UseSpace Class Implementation File
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/7/19
** Description: This is the class implementation file for the UseSpace class.
******************************************************************************/
#include "UseSpace.hpp"
#include <string>

/*****************************************************************************
 ** UseSpace() 
 ** Description: Constructor
 *****************************************************************************/
UseSpace::UseSpace(std::string mapName, int prevRow, int prevCol, 
    int nextRow, int NextCol): 
    Space(mapName, prevRow, prevCol, nextRow, NextCol)
{   
    inUse = false;
}

/*****************************************************************************
 ** interact(int, int) 
 ** Description: Uses the item.
 *****************************************************************************/
void UseSpace::interact(int row, int col)
{
    if(inUse)
    {
        message = "The " + item + " is already running.\n";
    }
    else
    {
        message = "Gurgle! Let the " + item + " bring chaos!\n";
        inUse = true;
     }

}

/*****************************************************************************
 ** getStatus() 
 ** Description: Returns inUse
 *****************************************************************************/
bool UseSpace::getStatus()
{
    return inUse;
}
