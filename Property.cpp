#include "Property.h"
#include <string>
#include <iostream>
using namespace std;

void Property::calculateNewRent()
{
	if (this->numHouses > 0 && this->numHotels == 0)
	{
		this->upgradeCost = 50*this->cost;
	}
	else if (this->numHouses == 3 && this->numHotels < 2)
	{
		this->upgradeCost = 60*this->cost;
	}
	else if (this->numHotels == 2 && this->numTurrets < 2)
	{
		this->upgradeCost = 70 * this->cost;
	}
}
void Property::calculateNewUpGradeCost()
{
	if (this->numHouses < 3 && this->numHotels == 0)
	{
		this->upgradeCost = 20 * this->cost;
	}
	else if (this->numHouses == 3 && this->numHotels < 2)
	{
		this->upgradeCost = 30 * this->cost;
	}
	else if (this->numHotels == 2 && this->numTurrets < 2)
	{
		this->upgradeCost = 40 * this->cost;
	}
}

void Property::calculateNewDefence(){this->defenceVal = this->numHouses + this->numHotels + (2 * this->numHotels);}

Property::Property(const std::string& name,const string& group, const int& cost,const int& rent):
	cost(cost),name(name), rent(rent)
{
	this->cost = cost;
	this->name = name;
	this->numHouses = 0;
	this->numHotels = 0;
	this->numTurrets = 0;
	this->defenceVal = 0;
	this->rent = rent;
	this->group = group;
}

int Property::getRent(){return this->rent;}

int Property::getCost(){return this->cost;}

int Property::getUpGradeCost(){return this->upgradeCost;}

int Property::getNumTurrets(){return this->getNumTurrets;}

int Property::getNumHouses() { return this->numHouses; }

int Property::getNumHotels(){return this->numHotels;}

int Property::getDefenceVal(){return this->defenceVal;}

std::string Property::getName(){return this->name;}

void Property::operator++()
{
	if (this->numHouses < 3 && this->numHotels == 0)
	{
		++this->getNumHouses;
		this->calculateNewUpGradeCost();
		this->calculateNewRent();
		this->calculateNewDefence();
	}
	else if (this->numHouses == 3 && this->numHotels < 2)
	{
		++this->getNumHotels;
		this->calculateNewUpGradeCost();
		this->calculateNewRent();
		this->calculateNewDefence();
	}
	else if (this->numHotels == 2 && this->getNumTurrets < 2)
	{
		++this->numTurrets;
		this->calculateNewUpGradeCost();
		this->calculateNewRent();
		this->calculateNewDefence();
	}
	else
	{
		cout << name + ":Max property in enhancements reached." << endl << "Super buffed property.";
	}
	this->calculateNewUpGradeCost();
}

int Property::operator--()
{
	int reimbursement{ 0 };
	if (this->numHouses > 0 && this->numHotels == 0 && this->numTurrets == 0)
	{
		--this->numHouses;
		reimbursement = this->upgradeCost;
		this->calculateNewUpGradeCost();
		this->calculateNewRent();
		this->calculateNewDefence();
	}
	else if (this->numHouses == 3 && this->numHotels > 0)
	{
		--this->numHotels;
		reimbursement = this->upgradeCost;
		this->calculateNewUpGradeCost();
		this->calculateNewRent();
		this->calculateNewDefence();
	}
	else if (this->numHotels == 2 && this->numTurrets > 0)
	{
		--this->numTurrets;
		reimbursement = this->upgradeCost;
		this->calculateNewUpGradeCost();
		this->calculateNewRent();
		this->calculateNewDefence();
	}
	else
	{
		cout << endl << "Property " + this->name+": Has zero buffs."<<endl;
	}
	return reimbursement;
}
