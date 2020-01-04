/******************************************************************************
** UseSpace Class Declaration File 
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/7/19
** Descriptions: This is the class declartion file for the UseSpace Class.
******************************************************************************/

#ifndef USESPACE_HPP
#define USESPACE_HPP

#include "Space.hpp"


// UseSpace Class Declarations
class UseSpace : public Space
{
    protected:
        bool inUse;

    public:
        // Constructor 
        UseSpace(std::string mapName, 
              int prevRow, int prevCol, int nextRow, int NextCol); 
        virtual ~UseSpace() =  default; // Use default destructor
        virtual void interact(int row, int col);
        virtual bool getStatus();

};

#endif
