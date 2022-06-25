#include "pilot.h"

Pilot::Pilot(const Employee& employee, const AirCrew& airCrew, EPilotRank pilotRank) : Person(employee.GetFirstName(), employee.GetLastName(), employee.GetBirthDate()), Employee(employee), AirCrew(airCrew), PilotRank(pilotRank)
{
}

Pilot::Pilot(Employee&& employee, AirCrew&& airCrew, EPilotRank pilotRank) : Pilot(employee, airCrew, pilotRank)
{
}

void Pilot::SetPilotRank(EPilotRank pilotRank)
{
    PilotRank = pilotRank;
}

Pilot::EPilotRank Pilot::GetPilotRank() const
{
    return PilotRank;
}

void Pilot::Print(std::ostream& os) const
{
    os << *this;
}

std::ostream& operator<<(std::ostream& os, const Pilot& pilot)
{
    os << static_cast<const Employee&>(pilot) << "Pilot rank: " << pilot.GetPilotRank() << std::endl;
    return os;
}
