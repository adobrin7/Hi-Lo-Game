/*
* This game generates random number and gives few attempts for user to guess it,
* in case of failure, gives advice how close was the given answer,
* and than, when attempts are left, names the conceived value
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Game_Functions.h"

bool worksFine(true);

int main()
{
	/*
	* Using std::rand() to create uniq numbers.
	* The outer loop is responsible for continuing the program as long as required,
	* the inner loop is designed to control the difficulty level by providing attempts
	*/
	
	srand(time(NULL));
	using std::cout;
	using std::endl;

	do
	{
		cout << "Welcome to the Hi-Lo Game!\n" <<
			"Try to guess my magic number, but remember, the number of attempts is limited ^.^" << endl;

		int difficultyFactor = setDifficultyFactor();
		if (!worksFine)
			break;

		int randValue = rand() % (999 - difficultyFactor * 7) + 1;

		cout << "I guessed the number in range from 1 to " << (999 - difficultyFactor * 7) + 1 << endl;

		bool won = startRound(randValue, difficultyFactor);

		if(won)
			cout << "Wow!! You guessed my number!" << endl;
		else
			cout << "My magic number was: " << randValue << "\nUnfortunately you have no more attempts...\n" <<
			"Don't be upset, yeah, this battle is lost, but the war is not lost!" << endl;
		
	} while (askToContinue() && worksFine == true);

	cout << "Shutting down, see you soon ;)" << endl;
}