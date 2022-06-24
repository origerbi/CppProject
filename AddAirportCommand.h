#pragma once
#include "command.h"
#include <string>
#include "airportManager.h"
class AddAirportCommand : Command
{
	AirportManager* Manager;
	std::string Name;
	std::string Iata;
	std::string City;
public:
	AddAirportCommand(AirportManager* manager, std::string& iata, std::string& name, std::string& city);
	void execute();
};

