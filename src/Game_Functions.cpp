#include "Game_Functions.h"

int getValue()
{
    // gives 3 attempts to enter correct number before shutdown

    for (int attempts = 3; attempts >= 1; --attempts)
    {
        std::cout << "This is number: ";

        int userNumber;
        std::cin >> userNumber;

        if (std::cin.fail())                // wrong type
        {
            std::cin.clear();               // reboot cin
            std::cin.ignore(32767, '\n');   // delete all wrong type values
            std::cout << "(" << attempts << ") ""Sorry, I cant anderstend :(\n";
        }
        else
        {
            std::cin.ignore(32767, '\n');   // ignore letters after num
            return userNumber;
        }
    }
    worksFine = false;                 // out of attempts
}

void giveAdvice(int generated_value, int input)
{
    int placeMatch = 0;
    int numberMatch = 0;
    while ((generated_value / 10 > 0))
    {
        generated_value / 10;
        std::cout << "LOOP\t" << generated_value*310 << "\n";
        
    }
}

int setDifficultyFactor()
{
    for (int attempts = 3; attempts >= 1; --attempts)
    {
        std::cout << "Choose difficulty ((e)asy | (m)edium | (h)ard)): ";

        char difficultyLvl;
        std::cin >> difficultyLvl;

        std::cin.ignore(32767, '\n'); // only first char needed

        if (difficultyLvl == 'e')
            return 100;
        else if (difficultyLvl == 'm')
            return 50;
        else if (difficultyLvl == 'h')
            return 1;
        else
            std::cout << "(" << attempts << ") " << "Sorry, I cant anderstend :(\n";
    }
    worksFine = false;
}

bool startRound(int randValue, int difficulty)
{
    using namespace std;
    for (int attempts = 7; attempts >= 1; --attempts)
    {
        cout << "At the moment you have " << attempts << " attempts!" << endl;

        int userValue = getValue();

        if (randValue == userValue)
            return true;
        else
            giveAdvice(randValue, userValue);
    }
    return false;
}

bool askToContinue()
{
    for (int attempts = 3; attempts >= 1; --attempts)
    {
        std::cout << "Do you want to play again? (y/n): ";

        char userChoise;
        std::cin >> userChoise;
        std::cin.ignore(32767, '\n'); // only first char needed

        if (userChoise == 'y')
            return true;
        else if (userChoise == 'n')
            return false;
        else
            std::cout << "(" << attempts << ") " << "Sorry, I cant anderstend :(\n";
    }
    worksFine = false;
}
