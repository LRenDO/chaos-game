/******************************************************************************
** OpenSpace Class Declaration File 
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/7/19
** Descriptions: This is the class declartion file for the OpenSpace Class.
******************************************************************************/

#ifndef OPENSPACE_HPP
#define OPENSPACE_HPP

#include "Space.hpp"


// UseSpace Class Declarations
class OpenSpace : public Space
{
    protected:
        bool isOpen; 

    public:
        // Constructor 
        OpenSpace(std::string mapName, 
              int prevRow, int prevCol, int nextRow, int NextCol); 
        virtual ~OpenSpace() =  default; // Use default destructor
        virtual void interact(int row, int col);
        virtual bool getStatus();

};

#endif

