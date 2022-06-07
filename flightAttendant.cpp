#include "flightAttendant.h"

FlightAttendant::FlightAttendant(const Employee& employee, const AirCrew& airCrew,
                                 const EFlightAttendantRank flightAttendantRank) : Person(employee.GetFirstName(), employee.GetLastName(), employee.GetBirthDate()), Employee(employee), AirCrew(airCrew), FlightAttendantRank(flightAttendantRank)
{
}

FlightAttendant::FlightAttendant(Employee&& employee, AirCrew&& airCrew, const EFlightAttendantRank flightAttendantRank) : FlightAttendant(employee, airCrew, flightAttendantRank)
{
}

void FlightAttendant::SetAttendantRank(const EFlightAttendantRank flightAttendantRank)
{
    FlightAttendantRank = flightAttendantRank;
}

FlightAttendant::EFlightAttendantRank FlightAttendant::GetAttendantRank() const
{
    return FlightAttendantRank;
}

void FlightAttendant::Print(std::ostream& os) const
{
    os << *this;
}

std::ostream& operator<<(std::ostream& os, const FlightAttendant& flightAttendant)
{
    os << static_cast<const Employee&>(flightAttendant) << "Flight attendant rank: " << flightAttendant.GetAttendantRank() << std::endl;
    return os;
}
