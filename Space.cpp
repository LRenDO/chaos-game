/******************************************************************************
** Space Class Implementation File
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/6/19
** Description: This is the Space class implementation file.
******************************************************************************/
#include "Space.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

/*****************************************************************************
 ** Space() 
 ** Description: 
 *****************************************************************************/
Space::Space()
{   
    rows = 5;
    cols = 5;
    destRow = 0;
    destCol = 0;
    mapName = "";
    prevRow = 0;
    prevCol = 0; 
    nextRow = 0;
    nextCol = 0;   
    startHSRow = 0;
    startHSCol = 0;
    endHSRow = 0;
    endHSCol = 0;
    maxCapacity = 3;
    top = nullptr;
    right = nullptr;
    left = nullptr;
    bottom = nullptr;
    prev = nullptr;
    next = nullptr;

     //Allocate memory for the space to be stored
     roomMap = new char* [rows];

    for (int i = 0; i < rows; ++i)
    {
        roomMap[i] = new char[cols];
    }

}
    

/*****************************************************************************
 ** Space(std::string, int, int, int, int) 
 ** Description: Constructor that takes the room/map name, number rows and 
 **              columns
 *****************************************************************************/
Space::Space
      (std::string mapName, int prevRow, int prevCol, int nextRow, int nextCol)
{   
    rows = 18;
    cols = 81;
    this -> mapName = mapName;
    this->prevRow = prevRow;
    this->prevCol = prevCol; 
    this->nextRow = nextRow;
    this->nextCol = nextCol;   
    startHSRow = 0;
    startHSCol = 0;
    endHSRow = 0;
    endHSCol = 0;
    this -> maxCapacity = 3;
    destRow = 0;
    destCol = 0;
    top = nullptr;
    right = nullptr;
    left = nullptr;
    bottom = nullptr;
    prev = nullptr;
    next = nullptr;

    // Allocate memory for the space to be stored
    roomMap = new char* [rows];

    for (int i = 0; i < rows; ++i)
    {
        roomMap[i] = new char[cols];
    }
}
 /*****************************************************************************
 ** ~Space() 
 ** Description: Deletes space.  Frees allocated memory. 
 *****************************************************************************/
Space::~Space()
{
    for (int i = 0; i < rows; ++i)
    {
        delete [] roomMap[i];
        roomMap[i] = nullptr;
    }
    
    delete [] roomMap;
    roomMap = nullptr;
}
 
/*****************************************************************************
 ** printRoomMap() 
 ** Description: Prints the room in current state. 
 *****************************************************************************/
void Space::printRoomMap()
{
 
        for (int r = 0; r < rows; ++r) 
        {
            for (int c = 0; c < cols; ++c)
            {
                std::cout << roomMap[r][c];
            }   
        }
}

/*****************************************************************************
 ** printHighSpace() 
 ** Description: Prints contents of highSpace container
 *****************************************************************************/
void Space::printHighSpace()
{   
    if(highSpace.size() > 0)
    {
        auto pos = highSpace.begin();
        while (pos != highSpace.end())
        {
            std::cout << *pos << " ";
            pos++;
        }
    }
}

/****************************************************************************
 ** removeChar(int, int) 
 ** Description: Removes character from space
 *****************************************************************************/
void Space::removeChar(int row, int col)
{
    roomMap[row][col] = ' ';
}

/****************************************************************************
 ** addChar(int, int, avatar) 
 ** Description: Changes character on space
 *****************************************************************************/
void Space::addChar(int row, int col, char avatar)
{
    roomMap[row][col] = avatar;
}

/*****************************************************************************
 ** pushHighSpace(char) 
 ** Description: Adds item to high space container
 *****************************************************************************/
void Space::pushHighSpace(char item)
{   
    if(highSpace.size() < maxCapacity)
    {
        highSpace.push_back(item);
    }
}

/*****************************************************************************
 ** popHighSpace() 
 ** Description: Removes and returns item from high space container
 *****************************************************************************/
void Space::popHighSpace()
{     
    if(highSpace.size() > 0)
    {
        highSpace.pop_back();
    }

}

/*****************************************************************************
 ** moveUp(int, int, int, int, char) 
 ** Description: Moves character up on roomMap
 *****************************************************************************/
bool Space::moveUp(int startRow, int startCol, int numSpaces, char avatar)
{
    destRow = startRow - numSpaces;
    destCol = startCol;
    if(this->validDest())
    {
        roomMap[destRow][destCol] = avatar;
        return true;
    }
    else
    {
        return false;
    }
}

/*****************************************************************************
 ** moveDown(int, int, int, char) 
 ** Description: Moves character down on roomMap
 *****************************************************************************/
bool Space::moveDown(int startRow, int startCol, int numSpaces, char avatar)
{
    destRow = startRow + numSpaces;
    destCol = startCol;
    if(this->validDest())
    {
        roomMap[destRow][destCol] = avatar;
        return true;
    }
    else
    {
        return false;
    }
}


/*****************************************************************************
 ** moveRight(int, int, int, char)
 ** Description: Moves character right on roomMap
 *****************************************************************************/
bool Space::moveRight(int startRow, int startCol, int numSpaces, char avatar)
{
    destRow = startRow;
    destCol = startCol + numSpaces;
    if(this->validDest())
    {
        roomMap[destRow][destCol] = avatar;
        return true;
    }
    else
    {
        return false;
    }
}

/*****************************************************************************
 ** moveLeft(int, int, char)
 ** Description: Moves character left on roomMap
 *****************************************************************************/
bool Space::moveLeft(int startRow, int startCol, int numSpaces, char avatar)
{
    destRow = startRow;
    destCol = startCol - numSpaces;
    if(this->validDest())
    {
        roomMap[destRow][destCol] = avatar;
        return true;
    }
    else
    {
        return false;
    }
}

/****************************************************************************
 ** inRoom() 
 ** Description:  Returns true if destination is in room
 *****************************************************************************/
bool Space::inRoom()
{   
    if((destRow >= 0 && destRow < rows) && (destCol >= 0 && destCol < cols))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/****************************************************************************
 ** validDest() 
 ** Description:  Returns true if the destination is valid
 *****************************************************************************/
bool Space::validDest()
{   
    if(inRoom() && 
      (roomMap[destRow][destCol] == ' ') && (roomMap[destRow][destCol] == ' '))
    {    
        return true;
    }
    else
    {
        return false;
    }
}

/****************************************************************************
 ** onHighSpace() 
 ** Description:  Returns true if the oarameters are within highSpace
 *****************************************************************************/
bool Space::onHighSpace(int row, int col)
{
    if((row > startHSRow && row < endHSRow) && 
      (col > startHSCol && col < endHSCol))
    {
        return true;
    }
    else 
    {
        return false;
    }
}

/*****************************************************************************
 ** setRoomMap() 
 ** Description: Sets room map from mapName file
 ** Credit: https://stackoverflow.com/questions/33415446/
 **         how-to-read-a-matrix-from-text-file-and-store-it-into-2d-array
 *****************************************************************************/
void Space::setRoomMap()
{
    std::ifstream fIn;
    fIn.open(mapName);

    char input;
    int r = 0;
    int c = 0;
        // Assign current character input in to roomMap
        while(r < rows) 
        {
            while(c < cols)
            {
                    fIn.get(input);
                    if(input!='\r')
                    {
                        roomMap[r][c] = input;
//remove                        std::cout << r <<" "<< c << roomMap[r][c];
                        c++;
                    }
           }
           c = 0;
           r++;
        }
    

    fIn.close();
}

/*****************************************************************************
 ** setHigSpace(int, int, int, int)
 ** Description: Sets startHSRow, endHSRow, startHSCol, endHSCol 
 *****************************************************************************/
void Space::setHighSpace(int startRow, int endRow, int startCol, int endCol)
{
    startHSRow = startRow;
    startHSCol = startCol;
    endHSRow = endRow;
    endHSCol = endCol;
}

/*****************************************************************************
 ** setPrevDoor(int, int)
 ** Description: Sets prevRow and prevCol to parameters. 
 *****************************************************************************/
void Space::setPrevDoor(int row, int col)
{
    prevRow = row;
    prevCol = col;
}

/*****************************************************************************
 ** setNextDoor(int, int)
 ** Description: Sets nextRow and nextCol to parameters. 
 *****************************************************************************/
void Space::setNextDoor(int row, int col)
{
    nextRow = row;
    nextCol = col;
}

/*****************************************************************************
 ** setMessage(std::string)
 ** Description: Sets message to parameter. 
 *****************************************************************************/
void Space::setMessage(std::string message)
{
    this-> message = message;
}

/*****************************************************************************
 ** setItem(std::string)
 ** Description: Sets message to parameter. 
 *****************************************************************************/
void Space::setItem(std::string item)
{
    this-> item = item;
}

/*****************************************************************************
 ** setNext(Space*)
 ** Description: Sets next. 
 *****************************************************************************/
void Space::setNext(Space * roomPtr)
{
    next = roomPtr;
}

/*****************************************************************************
 ** setPrev(Space*)
 ** Description: Sets prev. 
 *****************************************************************************/
void Space::setPrev(Space * roomPtr)
{
    prev = roomPtr;
}

/*****************************************************************************
 ** setTop(Space*)
 ** Description: Sets top. 
 *****************************************************************************/
void Space::setTop(Space * roomPtr)
{
    top = roomPtr;
}

/*****************************************************************************
 ** setRight(Space*)
 ** Description: Sets right. 
 *****************************************************************************/
void Space::setRight(Space * roomPtr)
{
    right = roomPtr;
}

/*****************************************************************************
 ** setLeft(Space*)
 ** Description: Sets left.
 *****************************************************************************/
void Space::setLeft(Space * roomPtr)
{
    left = roomPtr;
}

/*****************************************************************************
 ** setBottom(Space*)
 ** Description: Sets bottom. 
 *****************************************************************************/
void Space::setBottom(Space * roomPtr)
{
    bottom = roomPtr;
}

/*****************************************************************************
 ** setDestRow(int) 
 ** Description: Sets the destination row. 
 *****************************************************************************/
void Space::setDestRow(int r)
{
    destRow = r;
}

/*****************************************************************************
 ** setDestCol(int) 
 ** Description: Sets the destination column. 
 *****************************************************************************/
void Space::setDestCol(int c)
{
    destCol = c;
}

/*****************************************************************************
 ** getDestRow() 
 ** Description: Gets the destination row. 
 *****************************************************************************/
int Space::getDestRow()
{
    return destRow;
}

/*****************************************************************************
 ** getDestCol() 
 ** Description: Gets the destination column.
 *****************************************************************************/
int Space::getDestCol()
{
    return destCol;
}

/*****************************************************************************
 ** getPrevRow() 
 ** Description: Gets the previous room door row.
 *****************************************************************************/
int Space::getPrevRow()
{
    return prevRow;
}

/*****************************************************************************
 ** getPrevCol() 
 ** Description: Gets the previous room door column.
 *****************************************************************************/
int Space::getPrevCol()
{
    return prevCol;
}

/*****************************************************************************
 ** getNextCol() 
 ** Description: Gets the next room door column.
 *****************************************************************************/
int Space::getNextCol()
{
    return nextCol;
}

/*****************************************************************************
 ** getNextRow() 
 ** Description: Gets the next room door row.
 *****************************************************************************/
int Space::getNextRow()
{
    return nextRow;
}

/*****************************************************************************
 ** getTop() 
 ** Description: Gets pointer to top space
 *****************************************************************************/
Space* Space::getTop()
{
    return top;
}

/*****************************************************************************
 ** getRight() 
 ** Description: Gets pointer to right space
 *****************************************************************************/
Space* Space::getRight()
{
    return right;
}

/*****************************************************************************
 ** getLeft() 
 ** Description: Gets pointer to left space
 *****************************************************************************/
Space* Space::getLeft()
{
    return left;
}     

/*****************************************************************************
 ** getBottom() 
 ** Description: Gets pointer to bottom space
 *****************************************************************************/
Space* Space::getBottom()
{
    return bottom;
}

/*****************************************************************************
 ** getNext() 
 ** Description: Gets pointer to next space
 *****************************************************************************/
Space* Space::getNext()
{
    return next;
}


/*****************************************************************************
 ** getPrev() 
 ** Description: Gets pointer to prev space
 *****************************************************************************/
Space* Space::getPrev()
{
    return prev;
}

/*****************************************************************************
 ** getChar(int, int) 
 ** Description: Gets character at row and column parameter
 *****************************************************************************/
char Space::getChar(int row, int col)
{
    return roomMap[row][col];
}

/*****************************************************************************
 ** getMapName() 
 ** Description: Gets map name
 *****************************************************************************/
std::string Space::getMapName()
{
    return mapName;
}

/*****************************************************************************
 ** getMessage() 
 ** Description: Gets message
 *****************************************************************************/
std::string Space::getMessage()
{
    return message;
}
