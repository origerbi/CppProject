#include "airport.h"

Airport::Airport(std::string iata, std::string name, std::string city) : Iata(std::move(iata)), Name(
                                                                             std::move(name)), City(std::move(city))
{
}

const std::string& Airport::GetIata() const
{
    return Iata;
}

void Airport::SetIata(const std::string& iata)
{
    Iata = iata;
}

const std::string& Airport::GetCity()
{
    return City;
}

void Airport::SetCity(const std::string& city)
{
    City = city;
}

const std::string& Airport::GetName()
{
    return Name;
}

void Airport::SetName(const std::string& name)
{
    Name = name;
}

std::vector<Flight>& Airport::GetFlights()
{
    return Flights;
}

const std::vector<GroundCrew>& Airport::GetGroundCrew() const
{
    return GroundCrews;
}

bool Airport::operator==(const Airport& airport) const
{
    return Iata == airport.Iata;
}

Airport& Airport::operator+=(const Flight& flight)
{
    Flights.push_back(flight);
    return *this;
}

Airport& Airport::operator+=(const GroundCrew& crew)
{
    GroundCrews.push_back(crew);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Airport& airport)
{
    os << "Iata: " << airport.Iata << std::endl;
    os << "Name: " << airport.Name << std::endl;
    os << "City: " << airport.City << std::endl;
    os << "Flights: " << std::endl;
    for (const Flight& flight : airport.Flights)
    {
        os << flight << std::endl;
    }
    os << "Ground Crews: " << std::endl;
    for (const GroundCrew& crew : airport.GroundCrews)
    {
        os << crew << std::endl;
    }
    return os;
}
