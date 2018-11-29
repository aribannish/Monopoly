#ifndef Monopoly_Board
#define Monopoly_Board
#include "property.h"
class Board
{
private:
	int numberOfPlayers;
	int playerPositions[2];	//keep track to draw player pieces on board
public:
	void updateBoard();	//call the constructor with the update data?
	void drawBoard();


};
#endif // !Monopoly_Board

