#include "groundCrew.h"

GroundCrew::GroundCrew(const char* airportId) : AirportId(airportId)
{
}

const char* GroundCrew::GetAirportId() const
{
    return AirportId;
}

std::ostream& operator<<(std::ostream& os, const GroundCrew& groundCrew)
{
    os << "AirportId: " << groundCrew.AirportId << std::endl;
    return os;
}
