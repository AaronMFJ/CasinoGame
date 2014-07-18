//INCLUDES
#include <iostream>
#include <string>
#include <ctime>


//DECLARATIONS
using namespace std;


//GLOBAL VARIABLES
string playerName;			//string for player's name
int playerMoney = 20;		//variable for player's money. Re-factor to header with class later
int playerSelection = 0;	//choice player makes at each sequence
int playerGuess = 0;		//the player's number guess, between 0-101
int randNumber = 0;			//the randomly generated number from the house


//FUNCTIONS
int playerChoiceFunc(int playerSelection);
void selectionScreen();
int guessMath(int playerGuess);


int main()
{
	//initialize random seed off clock time
	srand(time(NULL));

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

	//display the selection screen and make a choice
	selectionScreen();

//	playerChoiceFunc(playerSelection);

	system("PAUSE");
	return 0;
}

//////////FUNCTION FOR PLAYER CHOICE LAYOUT//////////
void selectionScreen()
{
	//ask player what he wants to do
	cout << "\nWhat would you like to do?\n"
		<< "Press 1 for game rules.\n"
		<< "Press 2 to enter your guess.\n"
		<< "Press 3 to to access bank.\n"
		<< "Press 0 to quit.\n";
	
	//grab input
	cin >> playerSelection;
	
	//send player's selection to the choice function
	playerChoiceFunc(playerSelection);
	

}

//////////Function Call for what the player chooses to do//////////
int playerChoiceFunc(int playerSelection)
{
	//this function is where we take players input and match it to desired choice
	
	//if player presses 0, exit son!
	if (playerSelection == 0)
	{
		return -1;
	}
	
	//if player selects 1, display directions the get input again
	if (playerSelection == 1)
	{
		cout << "The point of the game is to guess a number and get as close as \
				possible to a randomly generated number. It costs $5 to guess.\n";
		selectionScreen();
	}

	//if player selects 2, let them guess!
	if (playerSelection == 2)
	{
		cout << "\nEnter your guess, between 0 and 101. ";
		cin >> playerGuess;

		//this is where we handle if player selects an out-of-range number
		while (playerGuess <= 0 || playerGuess >= 101)		 //remake this into declaration GUESS_MIN and GUESS_MAX
		{
			cout << playerGuess << "\nis not a valid choice. Try again.\n" << endl;
			cin >> playerGuess;
		}

		//This is where we send the player's guess to randomly generated number	
		cout << "\nYou guessed " << playerGuess << endl;
		guessMath(playerGuess);
	
	}
	return 0;
}

//////////Function for generating random number and comparing against player guess//////////
int guessMath(int playerGuess)
{
	int guessDifference = 0;

	playerGuess = playerGuess;						//just making sure playerGuess isn't lost

	randNumber = rand() % 101;						//randomly selects a number off rand. Revisit this -- allows 0 and shouldn't
	cout << "The random number is " << randNumber << endl;
	
	guessDifference = (randNumber - playerGuess);	//find the difference between the guess and the rand number
	
	guessDifference = abs(guessDifference);			//make it a positive if negative

	//if guess is more than 20 away from random
	if (guessDifference > 20)	
	{
		cout << "Sorry, your guess was " << guessDifference << " points away from the random number. You lose $20." << endl;
	}

	//if guess is between 10 and 20 away from the rand
	if (guessDifference <= 20 && guessDifference > 10)
	{
		cout << "Congrats! Your answer is within 20. You win $20." << endl;
	}

	//if guess is between 5 and 10 away from the rand
	if (guessDifference <= 10 && guessDifference > 5)
	{
		cout << "Congrats! Your answer is within 10. You win $30." << endl;
	}

	//if guess is between 0 and 5 away from the rand
	if (guessDifference < 5 && guessDifference != 0)
	{
		cout << "Congrats! Your answer is within 5. You win $50." << endl;
	}

	//if guess is spot on!
	if (randNumber == playerGuess)
	{
		cout << "SPOT ON! You win $100." << endl;
	}

	return randNumber;
}




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