#ifndef MONOPOLY_PLAYER
#define MONOPOLY_PLAYER
#include<vector>
#include<array>
#include<string>
#include<iostream>
class Player
{
public:
	Player();
	Player(std::string&);
	void updatePos(int&);
	void setPlayerName(std::string&);
	void loadCharArt();
	std::string getPlayerName();
	std::string getRandName();
private:
	int curPos;
	std::string name;
	std::string charPiece;
	//both vectors are being fucking stupid lol
	std::vector<std::string>charArt;
	//this vector is being stupid
	static std::vector<std::string>names;	//add in goku shrek and other names
	
	


};
#endif // !Monopoly_Player

