/******************************************************************************
** Menu Class Declaration File 
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 10/8/19 Updated: 11/29/19
** Description: This is the class declaration file for the Menu Class.
******************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <string>

// Menu Class Declarations
class Menu
{
    private:

        int numChoices; // Number of choices on the menu
        int lowerLimit; // Lower limit on choice options
        int type; // If type 2 menu has a lower limit that is not 1
        std::string displayMenu; // Stores the menu options to prompt user
        std::string inputCategory; // Stores input category
        int choice; // User Choice
        std::string strChoice; // String User Choice Option

    public:
        // Default constructor: Sets displayMenu to "No menu available" and 
        // number of choices and choice are set to 0. Type is set to 1.
        Menu();

        // Constructor from client program. It takes a string parameter and
        // an integer parameter: menu to be displayed on console and number
        // of choices. Choice is set to 0. This is type 1 menu. starts at 1.
        Menu(std::string, int);

        // Constructor that takes two string parameters one for menu copy,
        // one for input category and two integers one for the lower input
        // limit and one for the upper limit. This is type 2 menu. Has a 
        // lower limit defined by second integer.
        Menu(std::string, std::string, int, int);
       
        void setDisplayMenu(std::string); // Sets display menu;
        void setNumChoices(int); // Sets number of choices
        void printMenu(); // Displays menu on console
        void setChoice(); // Sets choice to user input 
        void setChoice(int); // Sets choice to integer parameter
        void setStrChoice(); // Sets choice to a string input
        void setType(int); // Sets type to integer passed
        int getChoice(); // Returns choice 
        std::string getStrChoice(); // Returns strChoice
        void runMenu(); // Runs menu     
        int isValid(std::string, std::string); // Validates integer no range
        int isValid(std::string, std::string, int, int); // Validates positive 
                                                         // integer in a range
        
};

#endif
