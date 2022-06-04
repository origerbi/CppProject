#include "airCrew.h"

AirCrew::AirCrew(const int airlineId) : AirlineId(airlineId)
{
}

int AirCrew::GetAirlineId() const
{
    return AirlineId;
}

std::ostream& operator<<(std::ostream& os, const AirCrew& airCrew)
{
    os << "Airline Id: " << airCrew.GetAirlineId() << std::endl;
    return os;
}
