/******************************************************************************
** Program Name: Furry Chaotic Darkness
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 12/4/19
** Description: This is a game where the user is a cat that is trying to lure
**              the dog out of the house before it's human comes home. User 
**              must move quickly or they lose points.
** Credit: Ideas for using files for maps and ncurses came from Jacob Leno's 
**         final project on code sharing page. 
**         https://oregonstate.instructure.com/courses/1738874/pages/
**         code-sharing?module_item_id=18940565           
******************************************************************************/
#include "Menu.hpp"
#include "Game.hpp"
#include <iostream>
#include <string>

//remove#include <ncurses.h>

int main()
{
    int userChoice = 0;

//    Menu startMenu
//        ("Enter number of choice: \n1. Play \n2. Instructions \n3. Quit", 4);
//    startMenu.runMenu();
//    int userChoice = startMenu.getChoice();
    while (userChoice != 3)
    {
        Game g1;
        userChoice = g1.runStartMenu();
        switch(userChoice)
        {
            case 1: 
                g1.runGame();
//std::cout << "chose1";
                break;
            case 2:
//std::cout << "chose22";
                g1.runInstructions();
                break;
            case 3:
                std::cout << "Quitting...\n\n";
        }


//remove        char charInput = '0';
//remove        int time = -1;
//remove        int score = 100;
//remove
//remove        while (charInput != 'q')
//remove        {
//remove        initscr(); // https://jbwyatt.com/ncurses.html#input 
//remove        halfdelay(10);// https://linux.die.net/man/3/halfdelay
//remove        // Get and validate input
//remove        std::cout << "Enter Command:" ; 
//remove        charInput = getch();
//remove        if (charInput == ERR && time > 5)
//remove        {
//remove            std::cout << "point deducted: " << --score;
//remove        }
//remove        endwin();// https://jbwyatt.com/ncurses.html#input 
//remove        if(time >= 0)
//remove        {
//remove
//remove        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" 
//remove                   << "\ntest\ntest\ntest\ntest\ntest\ntest\ntest\n";
//remove        }
//remove        std::cout << "second timer: " << ++time <<"\n\n";
//remove        std::cout << "score: " << score << "\n\n";      
//remove        }
//remove        // Run start menu
//        startMenu.runMenu();
//        userChoice = startMenu.getChoice();
    }

    return 0;
}
