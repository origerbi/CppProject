#include "flight.h"

Flight::Flight(int flightNumber, const char* src, const char* dst, Date dateDeparture, Airline* airline, Plane* plane) : FlightNumber(flightNumber), Src{},
    Dst{}, DateDeparture(dateDeparture), TheAirline(airline), ThePlane(plane)
{
    strcpy_s(Src, src);
    strcpy_s(Dst, dst);
}

Flight::~Flight()
{
    for (int i = 0; i < NumOfPassengers; i++)
    {
        delete Passengers[i];
    }
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

const char* Flight::GetSrc() const
{
    return Src;
}

void Flight::SetSrc(const char* src)
{
    strcpy_s(Src, src);
}

const char* Flight::GetDst() const
{
    return Dst;
}

void Flight::SetDst(const char* dst)
{
    strcpy_s(Dst, dst);
}

Date Flight::GetDateDeparture() const
{
    return DateDeparture;
}

void Flight::SetDateDeparture(Date dateDeparture)
{
    DateDeparture = dateDeparture;
}

Passenger* const* Flight::GetPassengers() const
{
    return Passengers;
}

AirCrew* const* Flight::GetAirCrew() const
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
    if (NumOfPassengers < MAX_CAPACITY)
    {
        Passengers[NumOfPassengers] = new Passenger(passenger);
        NumOfPassengers++;
    }
    return *this;
}

const Flight& Flight::operator+=(AirCrew* airCrew)
{
    if (NumOfAirCrew < MAX_AIRCREW)
    {
        AirCrews[NumOfAirCrew] = airCrew;
        NumOfAirCrew++;
    }
    return *this;
}

bool Flight::operator<(int capacity) const
{
    return NumOfPassengers < capacity;
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
    for (int i = 0; i < flight.NumOfPassengers; i++)
    {
        os << *flight.Passengers[i] << std::endl;
    }
    os << "Air crew: " << std::endl;
    for (int i = 0; i < flight.NumOfAirCrew; i++)
    {
        os << *flight.AirCrews[i] << std::endl;
    }
    return os;
}
