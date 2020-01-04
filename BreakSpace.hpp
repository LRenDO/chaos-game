/******************************************************************************
** BreakSpace Class Declaration File 
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/7/19
** Descriptions: This is the class declartion file for the BreakSpace Class.
******************************************************************************/

#ifndef BREAKSPACE_HPP
#define BREAKSPACE_HPP

#include "Space.hpp"


// UseSpace Class Declarations
class BreakSpace : public Space
{
    protected:
        bool isBroken;

    public:
        // Constructor 
        BreakSpace(std::string mapName, 
              int prevRow, int prevCol, int nextRow, int NextCol); 
        virtual ~BreakSpace() =  default; // Use default destructor
        virtual void interact(int row, int col);
        virtual bool getStatus();
};

#endif
