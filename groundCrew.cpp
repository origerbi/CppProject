#include "groundCrew.h"

GroundCrew::GroundCrew(std::string airportId) : AirportId(std::move(airportId))
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
