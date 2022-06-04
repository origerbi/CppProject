#include "groundAttendant.h"

GroundAttendant::GroundAttendant(const Employee& employee, const GroundCrew& groundCrew) : Person(employee.GetFirstName(), employee.GetLastName(), employee.GetBirthDate()), Employee(employee), GroundCrew(groundCrew), FlightNumber(0)
{
}

GroundAttendant::GroundAttendant(Employee&& employee, GroundCrew&& groundCrew) : GroundAttendant(employee, groundCrew)
{
}

void GroundAttendant::SetFlightNumber(const int flightNumber)
{
    FlightNumber = flightNumber;
}

int GroundAttendant::GetFlightNumber() const
{
    return FlightNumber;
}

std::ostream& operator<<(std::ostream& os, const GroundAttendant& groundAttendant)
{
    os << static_cast<const Employee&>(groundAttendant) << static_cast<const GroundCrew&>(groundAttendant) << "Flight number: " << groundAttendant.GetFlightNumber() << std::endl;
    return os;
}
