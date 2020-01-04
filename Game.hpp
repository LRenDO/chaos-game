/******************************************************************************
** Game Class Declaration File 
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/6/19
** Description: This is the class declaration file for the Game Class.
******************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "Menu.hpp"
#include "Space.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "BreakSpace.hpp"
#include "OpenSpace.hpp"
#include "UseSpace.hpp"

#include <string>

enum GameState{PLAYING, NOCHAOS, CAUGHT, VICTORY, QUIT};

// Game Class Declarations
class Game
{
    private:
        Menu startMenu;
        Space* currRoom;
        BreakSpace* foyer;
        BreakSpace* livingDiningRoom;
        UseSpace* kitchen;
        UseSpace* bathroom;
        OpenSpace* bedroom;
        OpenSpace* garden;
        Dog* dog;
        Cat* cat;
        GameState status;
        char userInput;
        char actionKey;
        int time;
        int chaosFactor;
        bool actionKeyMode;
        std::string instructions;

    public:
        Game(); // Constructor
        ~Game(); // Destructor
        int runStartMenu(); // Runs play/quit menu. Returns user choice.
        void runInstructions(); // Runs instruction process
        void runGame(); // Runs from instructions to game over
        void runGameOver(); // Runs game over sequence
        void buildHouse();  // Links roooms
        void linkFoyer();
        void linkLivingDiningRoom();
        void linkKitchen();
        void linkBathroom();
        void linkBedroom();
        void linkGarden();
        void printChaos(); // Prints Chaos points
        void printCurrRoomName(); // Prints current room's name
        void printTimer(); // Calculates minutes and seconds and prints timer
        void printBuffer(); // Prints extra lines as a buffer on the screen
        void printContainers(); // Prints high space and mouth contents 
        void updateScreen();  // Prints play screen
        void runGamePlay(); // Runs loop for gameplay for room
        void doAction(); // Does action for action key mode
        void updateStatus(); // Returns true if game over conditions are met
        void checkNext(); // If onNext changes current room to previous room
        void checkPrev(); // If onPrev changes current room to previous room
        bool onPrev(); // Returns true if cat is at door to previous room
        bool onNext(); // Returns true if cat is at door to next room
        bool validInput(); // Returns true if input is valid
        bool validDirection(); // Returns true if input is a valid direction
        bool validAction(); // Returns true if input is a valid action

};

#endif
