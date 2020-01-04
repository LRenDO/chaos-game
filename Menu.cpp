/******************************************************************************
** Menu Class Implementation File
** Author: Lauren "Ren" Demeis-Ortiz
** Date: 10/8/19 Updated: 11/29/19
** Description: This file contains the implementation of the Menu class.  It
**               has functions that display a menu, get a user inputted choice,
**               validate the choice, and return the choice client program. 
******************************************************************************/
#include "Menu.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

/*****************************************************************************
 ** Menu() 
 ** Description: Default constructor sets displayMenu to "No menu available"
 **              and number of choices and choice are set to 0.
 *****************************************************************************/
Menu::Menu()
{   
    numChoices = 1;
    choice = 0;
    displayMenu = "No Menu Available. Enter 1 to exit.";
    type = 1;
}
    

/*****************************************************************************
 ** Menu(std::string, int) 
 ** Description: Constructor that takes a string and an integer parameter: 
 **              the menu to be displayed on the console and the number of 
 **              choices available for the menu. Choice is set to 0.
 **              
 *****************************************************************************/
Menu::Menu(std::string menu, int numChoices)
{   
    this -> numChoices = numChoices;
    displayMenu = menu;
    choice = 0;
    type = 1;
}
    
/*****************************************************************************
 ** Menu(std::string, std::string, int, int) 
 ** Description: Constructor that takes two string and two integer parameters: 
 **              the menu to be displayed on the console, the input category
 **              and the lower limit menu input and upper limit of menu input.
 **              Choice is set to 0.
 **              
 *****************************************************************************/
Menu::Menu
(std::string menu, std::string inputCategory, int lowerLimit, int numChoices)
{   
    this -> numChoices = numChoices;
    this -> inputCategory = inputCategory;
    this -> lowerLimit = lowerLimit;
    displayMenu = menu;
    choice = 0;
    type = 2;
}

/*****************************************************************************
 ** printMenu() 
 ** Description: Displays menu on console. 
 *****************************************************************************/
void Menu::printMenu()
{
    std::cout << displayMenu << std::endl;
}

/*****************************************************************************
 ** setNumChoices(int) 
 ** Description: Sets number of choices from an integer parameter.
 *****************************************************************************/
void Menu::setNumChoices(int num)
{
    numChoices = num;
}

/*****************************************************************************
 ** setChoice() 
 ** Description: Sets and validates choice from user input. 
 *****************************************************************************/
void Menu::setChoice()
{
    std::string strIntChoice; // Stores users choice as string for validation
    std::getline(std::cin, strIntChoice); // Get choice from user input
    if (type == 2)
    {
        // Validate choice is an integer.
        choice = this -> 
        isValid(strIntChoice, inputCategory, lowerLimit, numChoices);
    }
    else
    {
        // Validate choice is an integer.
        choice = this ->
        isValid(strIntChoice, "menu choice number", 1, numChoices);
    }
}

/*****************************************************************************
 ** setChoice(int) 
 ** Description: Sets choice to integer parameter. 
 *****************************************************************************/
void Menu::setChoice(int choice)
{
    this-> choice = choice;
}

/*****************************************************************************
 ** setStrChoice() 
 ** Description: Sets and validates to and from string user input including
 **              spaces. 
 ** Credit: https://www.geeksforgeeks.org/
 **         how-to-use-getline-in-c-when-there-are-black-lines-in-input/
 *****************************************************************************/
void Menu::setStrChoice()
{
    getline(std::cin, strChoice);
    while (strChoice.length() == 0)
        { 
        std::cout << 
        "Oops you hit enter without typing anything.  Please enter something."
        << std::endl;
        getline(std::cin, strChoice); 
        }
}

/*****************************************************************************
 ** setDisplayMenu(std::string) 
 ** description: Sets menu text to be displayed.
 *****************************************************************************/
void Menu::setDisplayMenu(std::string menu)
{
    displayMenu = menu;
}

/*****************************************************************************
 ** setType(int) 
 ** description: Sets type.
 *****************************************************************************/
void Menu::setType(int type)
{
    this-> type = type;
}

/*****************************************************************************
 ** getchoice() 
 ** description: returns choice.
 *****************************************************************************/
int Menu::getChoice()
{
    return choice;
}

/*****************************************************************************
 ** getStrChoice() 
 ** description: returns strChoice.
 *****************************************************************************/
std::string Menu::getStrChoice()
{
    return strChoice;
}

/*****************************************************************************
 ** runMenu() 
 ** description: runs menu.
 *****************************************************************************/
void Menu::runMenu()
{
    this->printMenu();
    this->setChoice();
}

/******************************************************************************
 ** isValid(string, string)
 ** Description:  This function validates parameter is an integer. It
 **               takes two string parameters: the user's input and input 
 **               category user is inputting. For example "choice" or 
 **               "row".   It does not test a valid range.
 ******************************************************************************/
int Menu::isValid(std::string userInput, std::string inputCat)
{   
    
    std::string strInput = userInput;
    bool testInt = 1;
                if (strInput.length() < 1)
                {
                    strInput = "\n";
                }
 
    // Validate that user input did not cause input error
    // Credit: Doug T. https://stackoverflow.com/questions/5864540/
    // infinite-loop-with-cin-when-typing-string-while-a-number-is-expected
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       
        // Prompt user and get new input
        std::cout << "Oops! Something went wrong. Try again.\n"
        "Please enter " << inputCat << "."<< std::endl;
        std::getline(std::cin, strInput);
        if (strInput.length() < 1)
        {
            strInput = "\n";
        }
    }
   
    // Check that number is an integer
    do
    {
        if(strInput[0] == '-' && strInput.length() > 1) // If negative ignore -
        {
            // Reset test for next input
            testInt = 1;
            
            for (unsigned i = 1; i < strInput.length(); ++i)
            {
                if (!isdigit(strInput[i]))
                {
                    testInt = 0;
                }
            }

            if (testInt == 0)
            {
                // Prompt user to enter an integer
                std::cout << "Oops! Try again. You must enter an integer.\n"
                "Please enter " << inputCat << "."<< std::endl;
            
                // Get new input from user
                std::getline(std::cin, strInput);
                if (strInput.length() < 1)
                {
                    strInput = "\n";
                }
            }
        }
        else
        {   
            // Reset test for next input
            testInt = 1;
            
            for (unsigned i = 0; i < strInput.length(); ++i)
            {
                if (!isdigit(strInput[i]))
                {
                    testInt = 0;
                }
            }
    
            if (testInt == 0)
            {
                // Prompt user to enter an integer
                std::cout << "Oops! Try again. You must enter an integer.\n"
                "Please enter " << inputCat << "."<< std::endl;
            
                // Get new input from user
                std::getline(std::cin, strInput);
                if (strInput.length() < 1)
                {
                    strInput = "\n";
                }
            }
        }
    } while (testInt == 0);

    // Convert string user input to an integer
    // Credit: https://www.geeksforgeeks.org/converting-strings-numbers-cc/
    std::stringstream inputStream(strInput);
    int input;
    inputStream >> input;

    return input;
}

/******************************************************************************
 ** isValid(string, string, int, int)
 ** Description:  This function validates user input from. It
 **               takes two string parameters: the user's input and input 
 **               category user is inputting. For example "choice" or 
 **               "row" and two integer parameters: lower limit of
 **               valid range and upper limit of valid range.
 ******************************************************************************/

int Menu::isValid
        (std::string userInput, std::string inputCat, int lowLim, int upLim)
{   
    
    std::string strInput = userInput;
    bool testInt = 1;
                if (strInput.length() < 1)
                {
                    strInput = "\n";
                }
    
    // Validate that user input did not cause input error
    // Credit: Doug T. https://stackoverflow.com/questions/5864540/
    // infinite-loop-with-cin-when-typing-string-while-a-number-is-expected
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       
        // Prompt user and get new input
        std::cout << "Oops! Something went wrong. Try again.\n"
        "Please enter " << inputCat << "."<< std::endl;
        std::getline(std::cin, strInput);
                if (strInput.length() < 1)
                {
                    strInput = "\n";
                }
    }
   
    // Check that number is an integer
    do
    {
        // Reset test for next input
        testInt = 1;
        
        for (unsigned i = 0; i < strInput.length(); ++i)
        {
            if (!isdigit(strInput[i]))
            {
                testInt = 0;
            }
        }

        if (testInt == 0)
        {
            // Prompt user to enter an integer
            std::cout << "Oops! Try again. You must enter an integer.\n"
            "Please enter " << inputCat << "."<< std::endl;
        
            // Get new input from user
            std::getline(std::cin, strInput);
                if (strInput.length() < 1)
                {
                    strInput = "\n";
                }
        }
    } while (testInt == 0);

    // Convert string user input to an integer
    // Credit: https://www.geeksforgeeks.org/converting-strings-numbers-cc/
    std::stringstream inputStream(strInput);
    int input;
    inputStream >> input;

    // Validate input is in proper range
    while (input < lowLim || input > upLim) 
    {
        // Prompt user and get new input 
        std::cout << 
        "Oops! Try again. You must enter a number between " << lowLim <<
        " and " << upLim << ". \n" 
        "Please enter the number of " << inputCat << "."
        << std::endl;
        std::getline(std::cin, strInput);
                if (strInput.length() < 1)
                {
                    strInput = "\n";
                }

    // Validate that user input did not cause input error
    // Credit: Doug T. https://stackoverflow.com/questions/5864540/
    // infinite-loop-with-cin-when-typing-string-while-a-number-is-expected
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       
        // Prompt user and get new input
        std::cout << "Oops! Something went wrong. Try again.\n"
        "Please enter " << inputCat << "."<< std::endl;
        std::getline(std::cin, strInput);
                if (strInput.length() < 1)
                {
                    strInput = "\n";
                }
    }

    // Check that number is an integer
    do
    {
        // Reset test for next input
        testInt = 1;
        
        for (unsigned i = 0; i < strInput.length(); ++i)
        {
            if (!isdigit(strInput[i]))
            {
                testInt = 0;
            }
        }

        if (testInt == 0)
        {
            // Prompt user to enter an integer
            std::cout << "Oops! Try again. You must enter an integer.\n"
            "Please enter " << inputCat << "."<< std::endl;
        
            // Get new input from user
            std::getline(std::cin, strInput);
                if (strInput.length() < 1)
                {
                    strInput = "\n";
                }
        }
    } while (testInt == 0);

    // Convert string user input to an integer
    // Credit: https://www.geeksforgeeks.org/converting-strings-numbers-cc/
    std::stringstream inputStream(strInput);
    inputStream >> input;
    }  

    return input;
}
