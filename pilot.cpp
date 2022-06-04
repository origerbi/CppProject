﻿#include "pilot.h"

Pilot::Pilot(const Employee& employee, const AirCrew& airCrew, const EPilotRank pilotRank) : Person(employee.GetFirstName(), employee.GetLastName(), employee.GetBirthDate()), Employee(employee), AirCrew(airCrew), PilotRank(pilotRank)
{
}

Pilot::Pilot(Employee&& employee, AirCrew&& airCrew, const EPilotRank pilotRank) : Pilot(employee, airCrew, pilotRank)
{
}

void Pilot::SetPilotRank(const EPilotRank pilotRank)
{
    PilotRank = pilotRank;
}

Pilot::EPilotRank Pilot::GetPilotRank() const
{
    return PilotRank;
}

std::ostream& operator<<(std::ostream& os, const Pilot& pilot)
{
    os << static_cast<const Employee&>(pilot) << static_cast<const AirCrew&>(pilot) << "Pilot rank: " << pilot.GetPilotRank() << std::endl;
    return os;
}