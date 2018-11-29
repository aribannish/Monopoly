#ifndef Monoply_Game
#define Monoply_Game
#include "Menu.h"
#include "Property.h"
#include <vector>
#include <array>
class Monopoly
{
private:
	std::vector<std::string> getPropertyInformation(const std::string&);
	std::array<std::array<Property, 10>, 10> board;
public:
	Monopoly(std::vector<Player>);
	void start();
	
};

#endif