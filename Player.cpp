#include"Player.h"
#include<sstream>
#include<random>
#include<vector>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

//default constructor will generate a random name
vector<string> Player::names = {"Goku", "Shrek"};
Player::Player()
{
	
	this->curPos = 0;
	this->name = "";
	
}
//
Player::Player(string& name) :
	name{ name } {this->curPos = 0;} 

void Player::setPlayerName(string& name) 
{
	this->name = name;
}

//dont use this pointer to return
string Player::getPlayerName() 
{
	return name;
}

void Player::updatePos(int& roll) 
{
	if (roll > 0 && roll <= 12) 
	{
		this->curPos += roll;
	}
}

//have to fix vector with names to finish this method
string Player::getRandName()
{
	string randomName;
	default_random_engine generator;
	uniform_int_distribution<int>randInt(0, size(names));
	int namePos = randInt(generator);
	this->name = names[namePos];
	names.erase(names.begin() + namePos);	//removes name from vector 
	return randomName;
}

void Player::loadCharArt() 
{
	string curLine;
	string fileName = this->getPlayerName() + ".txt";
	ifstream artFile(fileName);
	if (artFile.is_open()) 
	{
		while (getline(artFile, curLine)) 
		{
			charArt.push_back(curLine);
		}
		artFile.close();
	}
}
