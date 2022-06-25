#pragma once
#include "airportManager.h"
#include "command.h"
#include <string>

class AddAirportCommand final : Command
{
	AirportManager* Manager;
	std::string Name;
	std::string Iata;
	std::string City;
public:
	AddAirportCommand(AirportManager* manager, std::string iata, std::string name, std::string city);
	void Execute() override;
};

