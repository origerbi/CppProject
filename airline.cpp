#include "airline.h"

int Airline::Counter = 0;

Airline::Airline(std::string name) : Id(Counter++), Name(std::move(name))
{
}

int Airline::GetId() const
{
    return Id;
}

const std::string& Airline::GetName() const
{
    return Name;
}

void Airline::SetName(const std::string& name)
{
    Name = name;
}

std::vector<Plane>& Airline::GetPlanes()
{
    return Planes;
}

std::vector<Pilot>& Airline::GetPilots()
{
    return Pilots;
}

std::vector<FlightAttendant>& Airline::GetFlightAttendants()
{
    return FlightAttendants;
}

const Airline& Airline::operator+=(const Plane& plane)
{
    Planes.push_back(plane);
    return *this;
}

const Airline& Airline::operator+=(const Pilot& pilot)
{
    Pilots.push_back(pilot);
    return *this;
}

const Airline& Airline::operator+=(const FlightAttendant& flightAttendant)
{
    FlightAttendants.push_back(flightAttendant);
    return *this;
}

std::ostream& operator<<(std::ostream& os, Airline& airline)
{
    os << "Airline: " << airline.GetName() << std::endl;
    os << "Id: " << airline.GetId() << std::endl;
    os << "Planes: " << std::endl;
    for (const Plane& plane : airline.GetPlanes())
    {
        os << plane << std::endl;
    }
    os << "Pilots: " << std::endl;
    for (const Pilot& pilot : airline.GetPilots())
    {
        os << pilot << std::endl;
    }
    os << "Flight Attendants: " << std::endl;
    for (const FlightAttendant& flightAttendant : airline.GetFlightAttendants())
    {
        os << flightAttendant << std::endl;
    }
    return os;
}
