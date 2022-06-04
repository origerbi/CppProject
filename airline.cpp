#include "airline.h"

int Airline::Counter = 0;

Airline::Airline(char* name) : Id(Counter++), Name(name)
{
}

Airline::~Airline()
{
    for (int i = 0; i < NumOfPlanes; i++)
    {
        delete Planes[i];
    }
    for (int i = 0; i < NumOfPilots; i++)
    {
        delete Pilots[i];
    }
    for (int i = 0; i < NumOfFlightAttendants; i++)
    {
        delete FlightAttendants[i];
    }
}

int Airline::GetId() const
{
    return Id;
}

char* Airline::GetName() const
{
    return Name;
}

void Airline::SetName(char* name)
{
    Name = name;
}

Plane* const* Airline::GetPlanes() const
{
    return Planes;
}

Pilot* const* Airline::GetPilots() const
{
    return Pilots;
}

FlightAttendant* const* Airline::GetFlightAttendants() const
{
    return FlightAttendants;
}

const Airline& Airline::operator+=(const Plane& plane)
{
    if (NumOfPlanes < MAX_PLANES)
    {
        Planes[NumOfPlanes++] = new Plane(plane); 
    }
    return *this;
}

const Airline& Airline::operator+=(const Pilot& pilot)
{
    if (NumOfPilots < MAX_PILOTS)
    {
        Pilots[NumOfPilots++] = new Pilot(pilot);
    }
    return *this;
}

const Airline& Airline::operator+=(const FlightAttendant& flightAttendants)
{
    if (NumOfFlightAttendants < MAX_CREW)
    {
        FlightAttendants[NumOfFlightAttendants++] = new FlightAttendant(flightAttendants);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Airline& airline)
{
    os << "Airline: " << airline.GetName() << std::endl;
    os << "Id: " << airline.GetId() << std::endl;
    os << "Planes: " << std::endl;
    for (int i = 0; i < airline.NumOfPlanes; i++)
    {
        os << *airline.Planes[i] << std::endl;
    }
    os << "Pilots: " << std::endl;
    for (int i = 0; i < airline.NumOfPilots; i++)
    {
        os << *airline.Pilots[i] << std::endl;
    }
    os << "Flight Attendants: " << std::endl;
    for (int i = 0; i < airline.NumOfFlightAttendants; i++)
    {
        os << *airline.FlightAttendants[i] << std::endl;
    }
    return os;
}
