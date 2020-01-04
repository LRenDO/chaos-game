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

int main()
{
    int userChoice = 0;

    while (userChoice != 3)
    {
        Game g1;
        userChoice = g1.runStartMenu();
        switch(userChoice)
        {
            case 1: 
                g1.runGame();

                break;
            case 2:

                g1.runInstructions();
                break;
            case 3:
                std::cout << "Quitting...\n\n";
        }

    }

    return 0;
}
