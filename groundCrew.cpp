#include "groundCrew.h"

GroundCrew::GroundCrew(const std::string& airportId) : AirportId(airportId)
{
}

const std::string& GroundCrew::GetAirportId() const
{
    return AirportId;
}

std::ostream& operator<<(std::ostream& os, const GroundCrew& groundCrew)
{
    os << "AirportId: " << groundCrew.AirportId << std::endl;
    return os;
}
