#include "AddAirportCommand.h"

AddAirportCommand::AddAirportCommand(AirportManager* manager, std::string iata, std::string name,
                                     std::string city) : Manager(manager), Name(std::move(name)), Iata(std::move(iata)), City(std::move(city))
{
}

void AddAirportCommand::Execute()
{
	*Manager += {Iata, Name, City};
}
