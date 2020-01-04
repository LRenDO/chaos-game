/******************************************************************************
** BreakSpace Class Implementation File
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/7/19
** Description: This is the class implementation file for the BreakSpace class.
******************************************************************************/
#include "BreakSpace.hpp"
#include <string>

/*****************************************************************************
 ** BreakSpace() 
 ** Description: Constructor
 *****************************************************************************/
BreakSpace::BreakSpace(std::string mapName, int prevRow, int prevCol, 
    int nextRow, int NextCol) :
    Space(mapName, prevRow, prevCol, nextRow, NextCol)
{   
    isBroken = false;
}

/*****************************************************************************
 ** interact(int, int) 
 ** Description: Returns message depending on interaction.
 *****************************************************************************/
void BreakSpace::interact(int row, int col)
{
    if(isBroken)
    {
        message = "Crash! Another bat at the " + item + 
                  " and more shattered glass\n";
    }
    else
    {
        message = "Crash!!"
        "No glass will survive your chaos! At least not this " + item + ".\n";
        isBroken = true;
    }

}

/*****************************************************************************
 ** getStatus() 
 ** Description: Returns isBroken
 *****************************************************************************/
bool BreakSpace::getStatus()
{
    return isBroken;
}
