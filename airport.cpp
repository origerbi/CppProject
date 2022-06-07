#include "airport.h"

Airport::Airport(const char* iata, const char* name, const char* city)
{
    strcpy_s(Iata, iata);
    strcpy_s(Name, name);
    strcpy_s(City, city);
}

Airport::~Airport()
{
    for (int i = 0; i < NumOfFlights; i++)
    {
        if (strcmp(Flights[i]->GetSrc(), Iata) == 0)
        {
            delete Flights[i];
        }
    }
    for (int i = 0; i < NumOfCrew; i++)
    {
        delete GroundCrews[i];
    }
}

char* Airport::GetIata()
{
    return Iata;
}

void Airport::SetIata(const char* iata)
{
    strcpy_s(Iata, iata);
}

char* Airport::GetCity()
{
    return City;
}

void Airport::SetCity(const char* city)
{
    strcpy_s(City, city);
}

char* Airport::GetName()
{
    return Name;
}

void Airport::SetName(const char* name)
{
    strcpy_s(Name, name);
}

Flight* const* Airport::GetFlights()
{
    return Flights;
}

GroundCrew* const* Airport::GetGroundCrew() const
{
    return GroundCrews;
}

int Airport::GetNumOfFlights() const
{
    return NumOfFlights;
}

int Airport::GetNumOfCrew() const
{
    return NumOfCrew;
}

bool Airport::operator==(const Airport& airport) const
{
    return strcmp(Iata, airport.Iata) == 0;
}

Airport& Airport::operator+=(Flight* flight)
{
    if (NumOfFlights < MAX_FLIGHTS)
    {
        Flights[NumOfFlights] = flight;
        NumOfFlights++;
    }
    return *this;
}

Airport& Airport::operator+=(const GroundCrew& crew)
{
    if (NumOfCrew < MAX_CREW)
    {
        GroundCrews[NumOfCrew] = new GroundCrew(crew);
        NumOfCrew++;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Airport& airport)
{
    os << "Iata: " << airport.Iata << std::endl;
    os << "Name: " << airport.Name << std::endl;
    os << "City: " << airport.City << std::endl;
    os << "Flights: " << std::endl;
    for (int i = 0; i < airport.NumOfFlights; i++)
    {
        os << *airport.Flights[i] << std::endl;
    }
    os << "Ground Crews: " << std::endl;
    for (int i = 0; i < airport.NumOfCrew; i++)
    {
        os << *airport.GroundCrews[i] << std::endl;
    }
    return os;
}
