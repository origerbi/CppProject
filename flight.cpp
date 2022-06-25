#include "flight.h"

Flight::Flight(int flightNumber, std::string src, std::string dst, Date dateDeparture, Airline* airline, Plane* plane) : FlightNumber(flightNumber), Src(
    std::move(src)), Dst(std::move(dst)), DateDeparture(dateDeparture), TheAirline(airline), ThePlane(plane)
{
}


int Flight::GetFlightNumber() const
{
    return FlightNumber;
}

Airline* Flight::GetAirline() const
{
    return TheAirline;
}

void Flight::SetFlightNumber(int flightNumber)
{
    FlightNumber = flightNumber;
}

const std::string& Flight::GetSrc() const
{
    return Src;
}

void Flight::SetSrc(const std::string& src)
{
    Src = src;
}

const std::string& Flight::GetDst() const
{
    return Dst;
}

void Flight::SetDst(const std::string& dst)
{
    Dst = dst;
}

Date Flight::GetDateDeparture() const
{
    return DateDeparture;
}

void Flight::SetDateDeparture(const Date dateDeparture)
{
    DateDeparture = dateDeparture;
}

const std::vector<Passenger>& Flight::GetPassengers() const
{
    return Passengers;
}

const std::vector<AirCrew>& Flight::GetAirCrew() const
{
    return AirCrews;
}

Plane* Flight::GetPlane() const
{
    return ThePlane;
}

void Flight::SetPlane(Plane* plane)
{
    ThePlane = plane;
}

const Flight& Flight::operator+=(const Passenger& passenger)
{
    Passengers.push_back(passenger);
    return *this;
}

const Flight& Flight::operator+=(const AirCrew& airCrew)
{
    AirCrews.push_back(airCrew);
    return *this;
}

bool Flight::operator<(size_t capacity) const
{
    return Passengers.size() < capacity;
}

bool Flight::operator==(const Flight& flight) const
{
    return flight.GetFlightNumber() == FlightNumber;
}

std::ostream& operator<<(std::ostream& os, const Flight& flight)
{
    os << "Flight number: " << flight.GetFlightNumber() << std::endl;
    os << "Source: " << flight.GetSrc() << std::endl;
    os << "Destination: " << flight.GetDst() << std::endl;
    os << "Date of departure: " << flight.GetDateDeparture() << std::endl;
    os << "Plane: " << *flight.GetPlane() << std::endl;
    os << "Passengers: " << std::endl;
    for (const Passenger& passenger : flight.GetPassengers())
    {
        os << passenger << std::endl;
    }
    os << "Air crew: " << std::endl;
    for (const AirCrew& airCrew : flight.GetAirCrew())
    {
        os << airCrew << std::endl;
    }
    return os;
}
