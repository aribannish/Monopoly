#ifndef PROPERTY_H
#define PROPERTY_H
#include <string>
class Property
{
private:
	int upgradeCost;
	int cost;
	int numTurrets;
	int numHouses;
	int numHotels;
	int rent;
	int defenceVal;
	std::string name;
	void calculateNewRent();
	void calculateNewUpGradeCost();
	void calculateNewDefence();
	std::string group;
public:

	Property(const std::string&,const std::string&,const int&, const int&);
	//-----------getters-------------
	int getRent();
	int getCost();
	int getUpGradeCost();
	int getNumTurrets();
	int getNumHouses();
	int getNumHotels();
	int getDefenceVal();
	std::string getName();
	//--------operators-------
	void operator++();
	int operator--();
};
#endif // !PROPERTY_H

