#ifndef MENU_H
#define MENU_H
#include "Player.h"//Player is defined here
#include <vector>
#include <string>
class StartingMenu// Interface to the game and it's options before entering
{
private:
	/*
	Displays art, gets user input, validates it, and creates and returns a new player object
	*/
	Player createPlayer();// creates a new player
	/*
	Gets a user choice as a single char string set to lower case
	*/
	std::string getChoice();// gets a user choice as a string
	/*
	args:
		string: Path to txt file for art
		string: Prompt for the user
		int: a maximum value
		int: a minnumim value
	returns:
		int: within the minnumim and maximum value 
	*/
	int getInt(const std::string&,const std::string&,const int&,const int&);// gets a user choice as a int and returns it
	/*
	Function: not yet definded
	*/
	void loadGame();
	/*
	args:
		const string refrence: string path to a txt file to display
	Function:
		Displays all text within the txt file thats given
	*/
	void displayArt(const std::string&);
	/*
	Function
		Creates a new vector of player objects to be passed to the Monopoly Constructor
	*/
	std::vector<Player> NewGame();
public:
	/*
	Function:
		Starts the menu process
			starts the game
		resizes window
	*/
	void Start();
};
#endif // !Monoply_Starting_Menu

