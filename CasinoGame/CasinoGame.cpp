//INCLUDES
#include <iostream>
#include <string>
#include <ctime>


//DECLARATIONS
using namespace std;

//GLOBAL VARIABLES
string playerName;				//string for player's name
double playerMoney  = 20;		//variable for player's money. Re-factor to header with class later
int playerSelection = 0;		//choice player makes at each sequence
int playerGuess     = 0;		//the player's number guess, between 0-101
int randNumber      = 0;		//the randomly generated number from the house
double bank         = 100;		//the bank. Careful, he'll break your fingers.
double owedMoney	= 0;		//how much you owe the bank, plus interest

//FUNCTIONS
int playerChoiceFunc(int playerSelection);
void selectionScreen();
int guessMath(int playerGuess);
void bankOverlord();
//int moneyCalculation(double playerMoney);


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
	cout << "\nYou have $" << playerMoney << endl;
	cout << "\nWhat would you like to do?\n"
		 << "\nPress 1 for game rules.\n"
		 << "Press 2 to enter your guess.\n"
		 << "Press 3 to to access bank.\n"
		 << "Press 0 to quit.\n";
	
	//grab input
	cin >> playerSelection;
	
	//send player's selection to the choice function
	playerChoiceFunc(playerSelection);
	
	//continue letting player play, until he exits out
	selectionScreen();
}

//////////Function Call for what the player chooses to do//////////
int playerChoiceFunc(int playerSelection)
{
	//this function is where we take players input and match it to desired choice
	
	int tempChoice = 0;

	//if player presses 0, exit son!
	if (playerSelection == 0)
	{
		return -1;			//need to figure out how to exit game. Maybe send to quit function?
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
		//borrow or quit if player has <5. 
		if (playerMoney < 5)										
		{
			cout << "Sorry, you have " << playerMoney << ", which is not enough money to play. Would you like to visit bank(1) or quit(0)?" << endl;
			cin >> tempChoice;
			if (tempChoice == 1)
			{
				bankOverlord();
				//cout << "The bank is currently under development. Exiting.";
			}
			else if (tempChoice == 0)
			{
				return -1;			//wtf to return here? Need an exit.
			}
		}
		cout << "\nYour money, " << playerMoney << " - $5 for guessing.";
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
	
	//if player selects 3, take to the bank!
	if (playerSelection == 3)
	{
		bankOverlord();
	}
	return 0;
}

//////////Function for generating random number and comparing against player guess//////////
int guessMath(int playerGuess)
{
	int guessDifference = 0;
	playerGuess = playerGuess;									//just making sure playerGuess isn't lost
	
	playerMoney = playerMoney - 5;								//subtract 5 for guessing

	randNumber = rand() % 100 + 1;								//randomly selects a number off rand. +1 so number is never 0.
	cout << "The random number is " << randNumber << endl;
	
	guessDifference = (randNumber - playerGuess);				//find the difference between the guess and the rand number
	
	guessDifference = abs(guessDifference);						//make it a positive if negative

	//if guess is spot on!
	if (randNumber == playerGuess)
	{
		cout << "SPOT ON! You win $100." << endl;
		playerMoney += 100;
	}

	//if guess is more than 20 but below 30 away from random
	else if (guessDifference > 20 && guessDifference < 30)
		{
		cout << "Sorry, your guess was " << guessDifference << " points away from the random number. You lose $5." << endl;
		playerMoney -= 5;
		}
	
	//if guess is more than 30 but below 40 away from random
	else if (guessDifference > 29 && guessDifference < 40)
		{
			cout << "Sorry, your guess was " << guessDifference << " points away from the random number. You lose $10." << endl;
			playerMoney -= 10;
		}

	//if guess is more than 40 but below 50 away from random
	else if (guessDifference > 39 && guessDifference < 50)
		{
		cout << "Sorry, your guess was " << guessDifference << " points away from the random number. You lose $15." << endl;
		playerMoney -= 15;
		}

	//if guess is more than 50 
	else if (guessDifference > 49)
		{
			cout << "Sorry, your guess was " << guessDifference << " points away from the random number. You lose $20." << endl;
			playerMoney -= 20;
		}

	//if guess is between 10 and 20 away from the rand. Include 20
	else if (guessDifference <= 20 && guessDifference > 10)
		{
			cout << "Congrats! Your answer is within 20. You win $20." << endl;
			playerMoney += 20;
		}

	//if guess is between 5 and 10 away from the rand. Include 10
	else if (guessDifference <= 10 && guessDifference > 5)
		{
			cout << "Congrats! Your answer is within 10. You win $30." << endl;
			playerMoney += 30;
		}

	//if guess is between 0 and 5 away from the rand. Include 5
	else if (guessDifference <= 5 && guessDifference != 0)
		{
			cout << "Congrats! Your answer is within 5. You win $50." << endl;
			playerMoney += 50;
		}

	//add player calculation moneys function here
	//moneyCalculation(playerMoney);
	
	return randNumber;
}

////////Bank money calculation. Need to pass some arguments here to keep track ///////
void bankOverlord()
{
	double borrowMoney = 0;

	cout << "\nWelcome to the bank! Remember whatever you borrow will need to be payed back, \
	plus 10%.\n";
	cout << "The bank has $" << bank << "." << endl;
	cout << "You owe the bank $" << owedMoney << "." << endl;
	
	cin >> borrowMoney;

	//While the bank doesn't have 0
	while (bank >= 0)
	{
		//If the bank is out of money, tell the player
		if (bank <= 0)						
		{
			cout << "You can't borrow more than the bank has.";
		}
		//If the bank has money, track how much borrowed and owed, plus interest
		else								
		{
			bank = bank - borrowMoney;
			borrowMoney = borrowMoney;
			playerMoney = playerMoney + borrowMoney;
			owedMoney = borrowMoney + (borrowMoney * .1);
		}
		break;
	}

	cout << "\nAmount borrowed: " << borrowMoney;
	cout << "\nAmount owed: " << owedMoney;
	cout << "\nAmount left in Bank: " << bank;
	
}


//////////Function for generating calculating player money//////////
//int moneyCalculation(playerMoney)
//{
//add winning and losing money here
//}


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