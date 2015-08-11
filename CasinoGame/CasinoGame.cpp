//INCLUDES
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

//DECLARATIONS and DEFINES
using namespace std;
#define GUESS_MIN 0
#define GUESS_MAX 101


//GLOBAL VARIABLES
string playerName;				//string for player's name
double playerMoney  = 50;		//variable for player's money. Re-factor to header with class later
int randNumber      = 0;		//the randomly generated number from the house
double bank         = 100;		//the bank. Careful, he'll break your fingers.
double owedMoney	= 0;		//how much player owes the bank, plus interest
double bankPayment  = 0;		//how much player has paid back to the bank


//FUNCTIONS
int playerChoiceFunc(int playerSelection);
void selectionScreen();
int guessMath(int playerGuess);
void bankOverlord();


int main()
{
	//initialize random seed off clock time
	srand(time(NULL));

	//Introduction and get player's name
	cout << "Welcome to Guessing Game!\n";
	cout << "\n Please enter your name. ";
	getline(cin, playerName);
	cout << "\nGreat! Welcome " << playerName;

	//WIP creating a save file for the player//
	ofstream savedGame;
	savedGame.open ("SAVEFILE.txt", ios::app);
	savedGame << "Writing this to a file.\n" << playerName;
	savedGame.close();
	///////////////////////////////////////////

	//display the selection screen and make a choice
	selectionScreen();

	system("PAUSE");
	return 0;
}

//////////FUNCTION FOR PLAYER CHOICE LAYOUT//////////
/////////////////////////////////////////////////////

void selectionScreen()
{
	int playerSelection = 0;		//choice player makes at each sequence

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

////////FUNCTION FOR CREATING AND SAVING TO FILE/////////
/////////////////////////////////////////////////////////


//////////Function Call for what the player chooses to do//////////
///////////////////////////////////////////////////////////////////

int playerChoiceFunc(int playerSelection)
{
	//this function is where we take players input and match it to desired choice
	int playerGuess = 0;		//the player's number guess, between 0-101
	int tempChoice = 0;         //a temp decision to make if you try to guess without having money - leave or bank.

	//if player presses 0, exit son!
	if (playerSelection == 0)
	{
		exit(0);			//need to figure out how to exit game. This may not be a good way to do it
	}
	
	//if player selects 1, display directions the get input again
	if (playerSelection == 1)
	{
		cout << "\nThe point of the game is to guess a number and get as close as possible to a randomly generated number. It costs $5 to guess.\n"
				"\nIf you run out of money, you can borrow some from the bank. You must repay the bank the amount owed plus interest.\n"
				"\nIf you cannot pay the bank back, they will break your knees and pass the burden on to your children. They will never live a normal life.\n"
				"Have fun!\n";
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
		cout << "\nYour money, $" << playerMoney << " - $5 for guessing.";
		cout << "\nEnter your guess, between 0 and 101. ";
		cin >> playerGuess;

		//this is where we handle if player selects an out-of-range number
		while (playerGuess <= GUESS_MIN || playerGuess >= GUESS_MAX)
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
////////////////////////////////////////////////////////////////////////////////////////////

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
//////////////////////////////////////////////////////////////////////////////////////

void bankOverlord()
{
	int borrowMoney = 0;
	bool validNumber = false;
	int bankChoice = 0;

	//if the bank has 0 or less, tell player the bank is out.
	if (bank <= 0)
		{
			cout << "You have borrowed your limit. Please repay the bank.";     //need to remove options for borrowing money when bank is out
		}

	//state how much the bank has and how much you owe
	cout << "\nWelcome to the bank! Remember whatever you borrow will need to be payed back, plus 10%.\n";
	cout << "The bank has $" << bank << "." << endl;
	cout << "You owe the bank $" << owedMoney << "." << endl;
	cout << "\nWhat would you like to do?" << endl;
	cout << "\nBorrow from the bank (press 1)." << endl;
	cout << "Pay the bank back (press 2)." << endl;
	cout << "Exit the bank and return to game. (press 3)." << endl;
	cout << "Save game and exit to desktop (press 0)." << endl;		//furture addition-player management and saving/reading from log.
	cin >> bankChoice;

	//this is where we deal with how much money to borrow from the bank
	if (bankChoice == 1)
	{
		//ask player how much to borrow and check the input for a number and not a string
		cout << "\nHow much would you like to borrow? ";
		while (validNumber == false)
		{
			cin >> borrowMoney;
			if (cin.good() != 1)		//is cin a number? If not, returns 0(false). If it is a number, return true.
			{
				//clear and flush. Without these two cin. it goes into infinite loop with borrowMoney stored in buffer
				cin.clear();			//clear error flags
				cin.sync();				//flush the input buffer. 
				cout << "Please enter a valid number" << endl;
			}
			else
			{
				validNumber = true;
			}

		}
	}
	
	//this is where we will deal with how to pay the bank back
	if (bankChoice == 2)
	{
		cout << "You owe the bank $" << owedMoney << endl;
		cout << "How much would you like to pay back?\n";
		cin >> bankPayment;
		bankPayment = bankPayment;
		owedMoney = owedMoney - bankPayment;
		bank = bank + bankPayment;
		playerMoney = playerMoney - bankPayment;
		cout << "You paid $" << bankPayment << " and owe the bank $" << owedMoney << endl;
	}

	//this is where we send player back to selection screen
	if (bankChoice == 0)
	{
		selectionScreen();
	}

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
			bank = bank - borrowMoney;					//subtract what player wnts from the bank
			borrowMoney = borrowMoney;					//set borrowmoney to borrowmoney. Was having problems with it getting lost
			playerMoney = playerMoney + borrowMoney;	//add the borrowed money to the players money
			owedMoney = owedMoney + borrowMoney + ceil((borrowMoney * .1));	//owed money from previous borrows adds to what you're currently borrowing plus interest. ceil() rounds up
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