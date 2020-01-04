/******************************************************************************
** Game Class Implementation File 
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/6/19
** Description: This is the class implementation file for the Game Class.
******************************************************************************/
#include "Game.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ncurses.h>

/*****************************************************************************
 ** Game()
 ** Description: Default constructor.
 *****************************************************************************/
Game::Game()
{
    foyer = new BreakSpace("Foyer", -1, -1, 16, 76);
    livingDiningRoom = new BreakSpace("Living_and_Dining_Room", 1, 77, 15, 78);
    kitchen = new UseSpace("Kitchen", 15, 0, 1, 1);
    bathroom = new UseSpace("Bathroom", 16, 1, 1, 1);
    bedroom = new OpenSpace("Bedroom", 16, 0, 1, 0);
    garden = new OpenSpace("Garden", 16, 2, 1, 2);
    currRoom = foyer;
    cat = new Cat();
    dog = new Dog();
    instructions = "Instructions";
    chaosFactor = 1;
    userInput = '0';
    actionKey = '0'; 
    time = -1;
    status = PLAYING;
    actionKeyMode = false;
    // Set start menu members
    startMenu.setDisplayMenu
    ("Enter number of choice: \n1. Play \n2. Instructions \n3. Quit");
    startMenu.setNumChoices(3); 
}

/*****************************************************************************
 ** ~Game()
 ** Description: Default destructor.
 *****************************************************************************/
Game::~Game() 
{
    delete cat;
    delete dog;
    delete foyer;
    delete livingDiningRoom;
    delete kitchen;
    delete bathroom;
    delete bedroom;
    delete garden;
}

/*****************************************************************************
 ** runStartMenu() 
 ** Description: Runs play quit menu. Returns User Choice
 *****************************************************************************/
int Game::runStartMenu()
{         
    startMenu.runMenu();
    return startMenu.getChoice();
}

/*****************************************************************************
 ** runInstructions() 
 ** Description: Runs instructions.
 *****************************************************************************/
void Game::runInstructions()
{   
    char input;   
    std::ifstream fIn;
    fIn.open(instructions);

    printBuffer();

    if(fIn) 
    {
        while(fIn >> std::noskipws >> input)
        {
            std::cout << input;
        }
    }
    else
    {
        std::cout << "Error: Instruction file didn't open.\n";
    }
    fIn.close();

    std::cout << std::endl;
    std::cin.get(); // User press enter to continue back to menu
}

/*****************************************************************************
 ** runGame() 
 ** Description: Runs game from start until game over.
 *****************************************************************************/
void Game::runGame()
{
    buildHouse();         
    while(status == PLAYING)
    {
        runGamePlay();
    }
    runGameOver();
}

/*****************************************************************************
 ** runGameOver() 
 ** Description: Runs game over sequences.
 *****************************************************************************/
void Game::runGameOver()
{ 
    printBuffer();
    printBuffer();   
     
    switch(status)
    {
        case NOCHAOS:
            std::cout << "You lack chaos. The canine remains comfortable in "
                      << "your home.\nTrain your chaos skills and you may one "
                      << "day achieve your goals of Furry Chaotic Darkness.";
            std::cout << "\n\nGame Over.\n\n";
            break;

        case CAUGHT:
            std::cout << "\nGame Over.\n\n";
            break;

        case VICTORY:
            std::cout << "VICTORY! At last, the canine is free and you are free"
                  << " from the canine. You have ample chaos in your veins.\n"
                  << "May you continue to achieve all things Furry, Chaotic"
                  << " and Dark.\n\n";
                  break;

        case PLAYING:
                  std::cout << "Error: status shows playing in runGameOver.";
                  break;
        case QUIT:
                  std::cout << "Returning to main menu...\n\n";
    }
    std::cout << "Press enter to continue\n";
    std::cin.get();
}

/*****************************************************************************
 ** buildHouse() 
 ** Description: Links all of the rooms.  Sets room items.
 *****************************************************************************/
void Game::buildHouse()
{   
    linkFoyer();
    linkLivingDiningRoom();
    linkKitchen();
    linkBathroom();
    linkBedroom();
    linkGarden();

    kitchen->setHighSpace(2, 5, 71, 77);
    bathroom->setHighSpace(1, 4, 73, 77);

    foyer->setItem("family picture");
    livingDiningRoom->setItem("chandelier");
    kitchen->setItem("garbage disposal");
    bathroom->setItem("toilet");
    bedroom->setItem("doggie door");
    garden->setItem("gate");

    foyer->setRoomMap();
    livingDiningRoom->setRoomMap();
    kitchen->setRoomMap();
    bathroom->setRoomMap();
    bedroom->setRoomMap();
    garden->setRoomMap();

    foyer->setMessage("Channel your darkness. Bring the furry chaos!\n");
    livingDiningRoom->setMessage
            ("And what chaos will you bring to the living and dining room\n");
    kitchen->setMessage
    ("Let's see what kind of chaos you can cook up. The fridge is high.\n");
    bathroom->setMessage
    ("Toilet, toilet paper perfect for chaos! The shower caddy is high.\n");
    bedroom->setMessage("You have achieved so much little chaotic one!\n");
    garden->setMessage("You're nearly there! Rid your home of the canine!\n");

    dog->sleep(currRoom);
    currRoom->addChar(cat->getRow(), cat->getCol(), cat->getAvatar());
}

/*****************************************************************************
 ** linkFoyer() 
 ** Description: Links rooms 
 *****************************************************************************/
void Game::linkFoyer()
{ 

    foyer->setBottom(livingDiningRoom);
    foyer->setNext(livingDiningRoom);       
    
}

/*****************************************************************************
 ** linkLivingDiningRoom() 
 ** Description: Links rooms 
 *****************************************************************************/
void Game::linkLivingDiningRoom()
{         
    livingDiningRoom->setTop(foyer);
    livingDiningRoom->setRight(kitchen);
    livingDiningRoom->setPrev(foyer);
    livingDiningRoom->setNext(kitchen);
}

/*****************************************************************************
 ** linkKitchen() 
 ** Description: Links rooms 
 *****************************************************************************/
void Game::linkKitchen()
{         
    kitchen->setTop(bathroom);
    kitchen->setLeft(livingDiningRoom);
    kitchen->setPrev(livingDiningRoom);
    kitchen->setNext(bathroom);
}

/*****************************************************************************
 ** linkBathroom() 
 ** Description: Links rooms 
 *****************************************************************************/
void Game::linkBathroom()
{       
    bathroom->setTop(bedroom);
    bathroom->setBottom(kitchen);
    bathroom->setPrev(kitchen);
    bathroom->setNext(bedroom);
}

/*****************************************************************************
 ** linkBedroom() 
 ** Description: Links rooms 
 *****************************************************************************/
void Game::linkBedroom()
{         
    bedroom->setTop(garden);
    bedroom->setBottom(bathroom);
    bedroom->setPrev(bathroom);
    bedroom->setNext(garden);    
}
/*****************************************************************************
 ** linkGarden() 
 ** Description: Links rooms 
 *****************************************************************************/
void Game::linkGarden()
{
    garden->setBottom(bedroom);
    garden->setPrev(bedroom);   
}

/*****************************************************************************
 ** printChaos() 
 ** Description: Prints current room's name
 ** Credit: Reset ios flags https://stackoverflow.com/questions/9947336/
 **         formatting-the-output-stream-iosleft-and-iosright
 *****************************************************************************/
void Game::printChaos()
{   
    std::cout << std::setiosflags(std::ios::right); 
    std::cout.width(10);
    std::cout << "| Chaos Level: " << cat->getChaos() << " | ";     
    std::cout << std::resetiosflags(std::ios::adjustfield);  
}

/*****************************************************************************
 ** printCurrRoomName() 
 ** Description: Prints current room's name
 ** Credit: Reset ios flags https://stackoverflow.com/questions/9947336/
 **         formatting-the-output-stream-iosleft-and-iosright
 *****************************************************************************/
void Game::printCurrRoomName()
{   
    std::cout << std::setiosflags(std::ios::left); 
    std::cout.width(24);
    std::cout << currRoom->getMapName();
    std::cout << std::resetiosflags(std::ios::adjustfield);      
}

/*****************************************************************************
 ** printTimer() 
 ** Description: Calculates minutes and seconds and prints timer
 *****************************************************************************/
void Game::printTimer()
{
    int minutes = time / 60;
    int seconds = time % 60;
    std::cout.width(22);
    std::cout << "| Time Elapsed: " 
              << minutes << "min. " <<  seconds <<"sec. |\n";
}

/*****************************************************************************
 ** printBuffer() 
 ** Description: Prints extra lines as a buffer on the screen 
 *****************************************************************************/
void Game::printBuffer()
{
    for(int i = 0; i < 23; ++i)
    {
        std::cout << std::endl;
    }
}

/*****************************************************************************
 ** printContainers() 
 ** Description: Prints high space and mouth contents 
 *****************************************************************************/
void Game::printContainers()
{
    std::cout << "| High Space |   | Mouth |\n";
    std::cout.width(17);
    currRoom->printHighSpace();
    std::cout <<" | ";
    std::cout.width(7);
    cat->printMouth();
    std::cout << std::endl;
}
   
/*****************************************************************************
 ** updateScreen() 
 ** Description: Prints play screen
 *****************************************************************************/
void Game::updateScreen()
{   
    this->printBuffer();
    this->printCurrRoomName();
    this->printChaos();
    this->printTimer(); 
    currRoom->printRoomMap();
    this->printContainers();
    std::cout << currRoom->getMessage(); 

}

/*****************************************************************************
 ** runGamePlay() 
 ** Description: Runs game play loop for playing in rooms
 *****************************************************************************/
void Game::runGamePlay()
{
    while (userInput != 'q' && status == PLAYING)
    {
        initscr(); // Credit: https://jbwyatt.com/ncurses.html#input 
        halfdelay(10); // Credit: https://linux.die.net/man/3/halfdelay

        userInput = getch(); // Get input

        // If it has been 5 seconds since the player hit a valid key
        if ((!validInput() || userInput == ERR) && (time > 0 && time % 5 == 0))
        {
            cat->setChaos(cat->getChaos() - chaosFactor); // Deduct chaos
        }
        endwin(); // Credit: https://jbwyatt.com/ncurses.html#input 

        // If direction key is hit and action key was just before last input
        // do action in current input direction
        if(validDirection() && actionKeyMode)
        {
            this->doAction();
            actionKeyMode = false;
        }
        // If action key is hit set action key mode
        else if(validAction())
        {
            if(actionKeyMode)
            {
                actionKeyMode = false;
            }
            else
            {
                actionKeyMode = true;
                actionKey = userInput;
            }
        }
        // If input is direction and not action key mode cat in input direction
        else if(validDirection())
        {
            cat->move(currRoom, userInput, 1);
            actionKeyMode = false;
        }

        if(time >= 0)  // Start time at 0
        {
            this->updateScreen();
        }   
        ++time; // Update Time

        this->updateStatus();
        if(status == PLAYING && onNext() && userInput == 'j') 
        {
            this->checkNext(); // If cat on next door switch to next room
        }
        else if(status == PLAYING && onPrev() && userInput == 'j')
        {
             this->checkPrev(); // If cat is on Prev door switch to previous room
        }
    }

}

/*****************************************************************************
 ** doAction()
 ** Description: Calls method for cat action from user input
 *****************************************************************************/
void Game::doAction()
{
    switch(actionKey)   
    {
        case 'j': // Cat jumps a space
            cat->move(currRoom, userInput, 2);
            break;
        case 'k': // Cat bats an item or special item
            cat->bat(currRoom, dog, userInput);           
            break;
        case 'i':  // Cat drops item from mouth
            cat->drop(currRoom, dog, userInput);
            break;
        case 'l':  // Cat picks up an item from room
            cat->pickUp(currRoom, userInput);
            break;
        case '0': // Something went wrong with conditions in runGamePlay
            std::cout << "Error: actionKey has default value.\n";
    }
    actionKey = '0';
}

/*****************************************************************************
 ** updateStatus() 
 ** Description: checks if condition is met for game over
 *****************************************************************************/
void Game::updateStatus()
{
    if(time >= 1800)  // If total time is too long human comes home
    {
        cat->caught(currRoom);
        updateScreen();
        std::cin.get();
        status = CAUGHT;
    }
    else if(cat->getChaos() <= 0)
    {
        status = NOCHAOS;
    }
    else if((currRoom->getMapName() == "Garden") && 
           (cat->getRow() == currRoom->getNextRow() && 
            cat->getCol() == currRoom->getNextCol()))
    {
        currRoom->removeChar(dog->getRow(), dog->getCol());
        status = VICTORY;
    }
    else if(userInput == 'q')
    {
        status = QUIT;
    }
}

/*****************************************************************************
 ** checkNext() 
 ** Description: Changes current room to next room
 *****************************************************************************/
void Game::checkNext()
{
    if(onNext())
    {
        currRoom = currRoom->getNext();  
        cat->setRow(currRoom->getPrevRow());
        cat->setCol(currRoom->getPrevCol()); 
        currRoom->addChar(currRoom->getPrevRow(), currRoom->getPrevCol(), '%');
    }
}

/*****************************************************************************
 ** checkPrev() 
 ** Description: Changes current room to previous room
 *****************************************************************************/
void Game::checkPrev()
{

    if(onPrev())
    {
        currRoom = currRoom->getPrev();
        cat->setRow(currRoom->getNextRow());
        cat->setCol(currRoom->getNextCol()); 
        currRoom->addChar(currRoom->getNextRow(), currRoom->getNextCol(), '%');
    }
  
}
/*****************************************************************************
 ** onPrev() 
 ** Description: Returns true if cat is on door to previous rooom
 *****************************************************************************/
bool Game::onPrev()
{
    if((cat->getRow() == currRoom->getPrevRow()) && 
       (cat->getCol() == currRoom->getPrevCol()))
    {
        return true;
    }
    else
    {
        return false;
    } 
}

/*****************************************************************************
 ** onNext() 
 ** Description: Returns true if cat is on door to next rooom
 *****************************************************************************/
bool Game::onNext()
{
    if((cat->getRow() == currRoom->getNextRow()) && 
       (cat->getCol() == currRoom->getNextCol()))
    {
        return true;
    }
    else
    {
        return false;
    } 
}

/*****************************************************************************
 ** validInput() 
 ** Description: Returns true if valid input
 *****************************************************************************/
bool Game::validInput()
{
    if(userInput == 'a' || userInput == 's' || userInput == 'd' || 
       userInput == 'w' || userInput == 'q' || userInput == 'j' || 
       userInput == 'k' || userInput == 'l' || userInput == 'i')
    {
        return true;
    }
    else
    {
        return false;
    } 
}

/*****************************************************************************
 ** validDirection() 
 ** Description: Returns true if input is a valid direction
 *****************************************************************************/
bool Game::validDirection()
{
    if(userInput == 'a' || userInput == 's' || userInput == 'd' || 
       userInput == 'w')
    {
        return true;
    }
    else
    {
        return false;
    } 
}

/*****************************************************************************
 ** validAction() 
 ** Description: Returns true if valid input is action
 *****************************************************************************/
bool Game::validAction()
{
    if(userInput == 'j' || userInput == 'k' || userInput == 'l' || 
       userInput == 'i')
    {
        return true;
    }
    else
    {
        return false;
    } 
}

