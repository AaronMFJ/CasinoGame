//INCLUDES
#include <iostream>
#include <string>



//DECLARATIONS
using namespace std;



//GLOBAL VARIABLES
string playerName;			//string for player's name
int playerMoney = 20;		//variable for player's money. Refactor to header with class later
int playerSelection = 0;	//choice player makes at each sequence
int playerGuess = 0;

int main()
{
	//Introduction and get player's name
	cout << "Welcome to Guessing Game!\n";
	cout << "\n Please enter your name. ";
	getline(cin, playerName);
	cout << "\nGreat! Welcome " << playerName;

					//			FUTURE UPDATE
					//This is where we will check a file for
					// the player's name, and load any stats
	
	//Display starting amount, or amount in file
	cout << ". You have $" << playerMoney << endl;
	cout << "\nWhat would you like to do?\n"		//refactor this into the selection function
		<< "Press 1 for game rules.\n"
		<< "Press 2 to enter your guess.\n"
		<< "Press 3 to to access bank.\n"
		<< "Press 0 to quit.\n";
	cin >> playerSelection;

					//			FUTURE UPDATE
					//This is going to be handled in a function
					// for player selection choices
	if (playerSelection == 0)
		{
			return -1;
		}
	if (playerSelection == 1)
		{
			//refactor to playerSelection function
			cout << "directions!"; 
			cout << "\nWhat would you like to do?\n"		//refactor this into the selection function
				<< "Press 1 for game rules.\n"
				<< "Press 2 to enter your guess.\n"
				<< "Press 3 to to access bank.\n"
				<< "Press 0 to quit.\n";
			cin >> playerSelection;
		}
	if (playerSelection == 2)
	{
		cout << "Enter your guess, between 0 and 101. ";
		cin >> playerGuess;
		if (playerGuess <= 0)
			{
				cout << playerGuess << "is not a valid choice. Try again. ";
				cin >> playerGuess;			//consider making the statement a while loop for multiple wrong choices
			}
	}

	system("PAUSE");
	return 0;
}

/////////////FUNTION FOR THE DICE ROLL GOES HERE//////////////////


//////////////////////////////////////////////////////////////////

//////////FUNTION FOR THE playerSelection goes here///////////////


//////////////////////////////////////////////////////////////////



/*
---Features
Store player info in file
	Name
	Count wins
	Count loses
Read/write to file
Banker has set amount
Banker takes money
Banker gives money

---Game Details
-Ask player for name
-Store the name somewhere
-Check file for existing player 
-If exists, bring up stats, money
-Pick a number between 1 and 100
	-Player starts with $20
	-Costs $5 to guess a number
	-If within 20, win $20
	-If within 10, win $30
	-If withing 5, win $50
	-If exact, win $100
	-If over 20, lose $20.
-Goal of the game is to get to $100
-You can ask banker for $5, $10, or $30
	-Bank only has $50
	-Player must pay back banker amount borrowed +10%
	-Game must be won with <$100 - borrowed amount


	*/