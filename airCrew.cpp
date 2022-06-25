#include "airCrew.h"

AirCrew::AirCrew(int airlineId) : AirlineId(airlineId)
{
}

int AirCrew::GetAirlineId() const
{
    return AirlineId;
}

void AirCrew::Print(std::ostream& /*os*/) const
{
}

std::ostream& operator<<(std::ostream& os, const AirCrew& airCrew)
{
    os << "Airline Id: " << airCrew.GetAirlineId() << std::endl;
    airCrew.Print(os);
    return os;
}
