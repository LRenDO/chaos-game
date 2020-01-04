/******************************************************************************
** Space Class Declaration File 
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/6/19
** Description: This is the class delcartion file for the Space class.
******************************************************************************/
#include <string>
#include <vector>

#ifndef SPACE_HPP
#define SPACE_HPP

// Space Class Declarations
class Space
{
    protected:
        char** roomMap; // 2D array where the room map is stored
        std::string mapName; // Map file name
        std::string message; // Room Message
        std::string item; // 
        int rows; // Number rows
        int cols; // Number columns
        int destRow; // Destination row
        int destCol; // Destination column
        int prevRow; // Door to prev room row
        int prevCol; // Door to prev room col
        int nextRow; // Door to prev room row
        int nextCol; // Door to prev room col     
        int startHSRow; // Start of high space row 
        int startHSCol; // Start of high space col
        int endHSRow; // End of high space row 
        int endHSCol; // End of high space col
        std::vector<char> highSpace; // Container for high space objects
        unsigned maxCapacity; // Maximum container capacity
        Space* top; // Points to adjacent space
        Space* right; // Points to adjacent space
        Space* left; // Points to adjacent space
        Space* bottom; // Points to adjacent space
        Space* next;  // Points to next room
        Space* prev;  // Points to previous room

    public:
        // Defaultructor
        Space();
        // Constructor takes mapName and positions of next and prev. Creates  
        // roomMap dynamically allocated array
        Space(std::string mapName, 
              int prevRow, int prevCol, int nextRow, int NextCol);
        virtual ~Space() = 0; // Destructor: frees allocated memory  

        void printRoomMap(); // Prints current state of space
        void printHighSpace(); // Prints what is in the high space container
        void removeChar(int row, int col); // Removes character from space 
        void addChar(int row, int col, char avatar); //Change Character on space
        void pushHighSpace(char item);  // Add item to high space
        void popHighSpace();  // Remove item from high space

        // Moves character up on room map
        bool moveUp(int startRow, int startCol, int numSpaces, char avatar);
        // Moves character down on room map
        bool moveDown(int startRow, int startCol, int numSpaces, char avatar); 
        // Moves character right on room map
        bool moveRight(int startRow, int startCol, int numSpaces, char avatar); 
        // Moves character left on room map
        bool moveLeft(int startRow, int startCol, int numSpaces, char avatar); 
        bool inRoom(); //Returns true if destination is in room
        bool validDest(); // Returns true if the destination is valid
        bool onHighSpace(int row, int col); // Returns true if in high space

        void setRoomMap(); // Sets room map from file (mapName)
        void setHighSpace(int startRow, int endRow, int startCol, int endCol);
        void setPrevDoor(int row, int col);
        void setNextDoor(int row, int col);
        void setMessage(std::string);
        void setItem(std::string item);
        void setNext(Space* roomPtr); 
        void setPrev(Space* roomPtr); 
        void setTop(Space* roomPtr); 
        void setRight(Space* roomPtr); 
        void setLeft(Space* roomPtr); 
        void setBottom(Space * roomPtr); 
        void setDestRow(int row); 
        void setDestCol(int col); 

        int getDestRow(); 
        int getDestCol(); 
        int getPrevRow();
        int getPrevCol();
        int getNextRow();
        int getNextCol();
        Space* getTop();
        Space* getRight();
        Space* getLeft();
        Space* getBottom();
        Space* getNext();
        Space* getPrev();
        char getChar(int row, int col);
        std::string getMessage();  
        std::string getMapName();

        // Special action for each space type
        virtual void interact(int row, int col) = 0; 
        virtual bool getStatus() = 0;
};

#endif
