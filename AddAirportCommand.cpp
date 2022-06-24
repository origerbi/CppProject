#include "AddAirportCommand.h"

AddAirportCommand::AddAirportCommand(AirportManager* manager, std::string& iata, std::string& name, std::string& city) : Manager(manager), Iata(iata), Name(name), City(city)
{
}

void AddAirportCommand::execute()
{
	*Manager += {Iata, Name, City};
}
