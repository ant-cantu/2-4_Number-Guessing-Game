
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool guessGame(int guess, int num);

int main()
{
	int num,			//The number to guess.
		guess,			//The users guessed input.
		tries;			//How many tries to give the user.

	bool isGuessed;		//boolean for if number is guessed correctly

	char q;

	srand(time(0));
	num = rand() % 100;	//Set random number to be guessed.

	isGuessed = false;	//Set guessed correctly to false.
	tries = 5;			//How many tries to give the user.

	cout << "Anthony Cantu\t" << "L2-4\t" << "L2-4.exe" << endl;

	while (!isGuessed)
	{
		cout << "Enter an integer greater"
			 << " than or equal to 0 and "
			 << "less than 100: ";

		cin >> guess;
		cout << endl;
		if (cin)
		{
			if (tries != 1)
			{
				if (guess >= 0 && guess <= 99)
				{
					if (guessGame(guess, num) == true) //User guessed correctly
					{
						cout << "Winner! You guessed the correct number." << endl
							 << "Press any key to Exit.";
						isGuessed = true;
						cin.ignore(2, '\n');
						cin.get(q);

						return 0;
					}
					else //User guessed wrong
					{
						tries -= 1;
					}
				}
				else //User did not enter a numeric value between 0 and 99
				{
					cout << "ERROR: Please enter a numeric value between 0 and 99.";
				}
			}
			else //Ran out of tries
			{
				cout << "You have ran out of tries!" << endl
					 << "The correct number was: " << num << endl
					 << "Press any key to Exit.";
				cin.ignore(2, '\n');
				cin.get(q);
				return 0;
			}
		}
		else //User did not enter a numeric value
		{
			cin.clear();
			cin.ignore(200, '\n');
			cout << "ERROR: Please enter a numeric value between 0 and 99.";
		}
		cout << endl; //Line Break
	}
	return 0;
}

bool guessGame(int guess, int num)
{
	int diff; //Difference between the guess and the random number

	diff = abs(num - guess);

	if (diff >= 50)
	{
		if (guess > num)
		{
			cout << "Your guess is very high." << endl
				 << "Guess again!";
		}
		else if (guess < num)
		{
			cout << "Your guess is very low." << endl
				 << "Guess again!";
		}
		return false; //Incorrect guess
	}
	else if (diff >= 30 && diff <= 50)
	{
		if (guess > num)
		{
			cout << "Your guess is high." << endl
				 << "Guess again!.";
		}
		else if (guess < num)
		{
			cout << "Your guess is low." << endl
				 << "Guess again!.";
		}
		return false; //Incorrect guess
	}
	else if (diff >= 15 && diff <= 30)
	{
		if (guess > num)
		{
			cout << "Your guess is moderately high." << endl
				 << "Guess again!.";
		}
		else if (guess < num)
		{
			cout << "Your guess is moderately low." << endl
				 << "Guess again!.";
		}
		return false; //Incorrect guess
	}
	else if (diff > 0 && diff < 15)
	{
		if (guess > num)
		{
			cout << "Your guess is somewhat high." << endl
				 << "Guess again!.";
		}
		else if (guess < num)
		{
			cout << "Your guess is somewhat low." << endl
				 << "Guess again!.";
		}
		return false; //Incorrect guess
	}
	else if (diff == 0)
		return true; //Correct guess
}