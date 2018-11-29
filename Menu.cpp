
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include <cctype>

#include "Player.h"// Player object
#include "Menu.h" // This class
#include "Game.h" // main game

using namespace std;

string StartingMenu::getChoice() // gets a single char string
{
	string temp;//to cin in to
	size_t zero{ 0 };// to compair size of temp to
	size_t one{ 1 };// to compair size of temp to

	while (temp.size() >= zero && temp.size() != one)// wwhile the size of the cin equals 0, and doesn't equal one
	{
		cin >> temp;// user input
		if (temp.size() > one)// if the string entered is greter than one
		{
			cin.ignore(64);// Ignore sixty four chars in the input stream cin
		}
	}
	temp.at(0) = tolower(temp.at(0));// set the one char within the string equal it's lowercase self 
	return temp;// return the one char as a string 
}
/*
	args
	file: is a string path to a file to be sent to the display member function
	prompt: just as the name suggests
	max: a max value that can be entered and returned
	min: a min value that can be returned
*/
int StartingMenu::getInt(const string& file, const std::string& prompt, const int& max, const int& min)//gets a int within min and max
{
	string enteredVal;// to cin in to

	int reTurnVal{ 0 };// for stoi to store a value into, and to check to see if it's within min and max

	bool done{ false };// for a while loop

	while (!done)// while not done
	{
		system("CLS");//clear screen
		this->displayArt(file);//display some nice art from txt
		cout << "\n\n" + prompt << "(" << min << "/" << max << ")" << ":";// display prompt to user and min and max that can be entered
		cin >> enteredVal;// get user input
		try// try me code----might break
		{
			reTurnVal = stoi(enteredVal);// try to convert to int
			if (reTurnVal >= min && reTurnVal <= max)// if reTurnVal is int, check if it's within max and min
			{
				done = true;// if entered value within max and min break out of loop
			}
		}
		catch (const std::invalid_argument&)// catch stoi error
		{
			cin.ignore(1);// ignore one char in the input stream cin
		}
		catch (const std::out_of_range&)// catch stoi error 
		{
			cin.ignore(1);// ignore one char in the input stream cin
		}
		catch (const std::exception&)// catch stoi error 
		{
			cin.ignore(1);// ignore one char in the input stream cin
		}//Yes three different exceptions can be thrown, user could do anything----Need to catch all
	}

	return reTurnVal;// if the varified int value
}

void StartingMenu::loadGame()//not yet defined
{
	system("pause");//stop here
}

/*
args:
	stringToFile: is a string path to a txt file
Function:
	Displays all the lines within the given txt file path
*/
void StartingMenu::displayArt(const std::string& stringToFile)// Use only for txt files--Don't add .txt
{
	string line;// to use to iterate through a txt files lines
	fstream tempFile{ stringToFile + ".txt" };// Create a new file stream object given the string file path with a concatnated .txt
	if (tempFile.is_open())/// if the file exists and is open--- Cool looking color, I like it
	{
		while (getline(tempFile, line))// while there's still lines to display within tempFile, assign each to line
		{
			cout << line<< endl;// display line of text from the file, and end the line
		}
		tempFile.close();// when getLine returns a false statement and we exit the while close the file
	}//end---
}///

/*
args
	None
Function
	To act as a initialize for the monopoly game
	Creates a vector of players to be passed to the game's constructor
*/
std::vector<Player> StartingMenu::NewGame()//Enter a new game 
{
	bool done{ false };// for while loop
	vector<Player> players;// to be passed to the new game
	int numPlayers = this->getInt("Art/Configuration","Enter amount of players:", 6, 1);// get the number of players playing

	for (int player{ 0 }; player <= numPlayers; ++player)//use a loop to get the number of players, and their slection
	{
		players.push_back(this->createPlayer());// creates a new player and appends it to the players vector
	}//Look at the createPlayer member function to see the inner workings---too long for here

	return players;//returns a vector of one to six players 
}
/*
	args
		None
	Function
		Acts as a hub of user options

*/
void StartingMenu::Start()//Entering the main window
{
	//this->reSizeWin(); Wanna up date it to this which will find the max window size and set to that 
	system("mode con: cols=185 lines=90");//Resize the window-----Don't like this
	
	bool done{ false };//To use for a while loop
	
	string temp;// String to assign the users choice into


	while (!done)// while still within the game 
	{
		this->displayArt("Art/Monopoly");// Display the art at Art/MMonopoly
		cout << "\n\nNew Game:  S\n\nexit:      X\n\nLoad Game: L\n\nEnter option:";// differing options 
		temp = this->getChoice();// gets a one char string set to lower case
		if (temp == "s")// if start do this
		{
			Monopoly newBoard{ this->NewGame() };// creates a new Monoply object with a 
			cout << endl << "About to enter game code ends here"<<endl;
			system("pause");
			//newBoard.start();
			done = true;// When the game is over exit the loop Game equals over 
		}
		else if (temp == "x")// x == exit 
		{
			this->displayArt("Art/Exit");//display art at Art/Exit.txt 
			system("pause");// Before exit pause 
			done = true;// exit game loop
		}
		else if (temp == "l")// if l load saved game
		{
			this->loadGame();// not defined 
			done = true;// exit loop
		}
		system("CLS");//clear the screen
	}

}//----
/*
	args
		None
	Function
		Creates player objects based on user input

*/
Player StartingMenu::createPlayer()// Create new players
{
	ostringstream charMenu;// Menu of charactors
	charMenu << "---Choose Your Character---" << "\n1) Goku" 
		<< "\n2)Shrek" << "\n3)Placeholder1" << "\n4)Placeholder2" 
		<< "\n5)Placeholder3" << "\n6)Placeholder4\n";

	string name;//Holder for slected name
	int choice;// Holder for slected user choice
	bool done = false;// Use for while loop
	while (!done) // while still slecting player names
	{
		system("CLS");// Clear the screen
		choice = this->getInt("Art/CreatePlayer",charMenu.str(), 6, 1);//Get a int from 1-Goku to 6-unknown and display menu and art
		switch (choice)//What name did you enter
		{
			case 1:
				name = "Goku";
				break;
			case 2:
				name = "Shrek";
				break;
			case 3:
				name = " ";
				break;
			case 4:
				name = " ";
				break;
			case 5:
				name = " ";
				break;
			case 6:
				name = "  ";
				break;
		}
		return Player(name);//Creates a new player object passing the entered name, and returns it
		done = true; // We're done
	}// end of while
}//end
