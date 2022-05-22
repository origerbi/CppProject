#include "passenger.h"

Passenger::Passenger(const Person& base, const int flightNumber, Luggage& luggage) : Person(base), FlightNumber(flightNumber), PassengerLuggage(&luggage)
{
}

Passenger::Passenger(Person&& base, const int flightNumber, Luggage& luggage) : Person(base), FlightNumber(flightNumber), PassengerLuggage(&luggage)
{
}

void Passenger::SetFlightNumber(const int flightNumber)
{
    FlightNumber = flightNumber;
}

void Passenger::SetLuggage(Luggage& luggage)
{
    PassengerLuggage = &luggage;
}

int Passenger::GetFlightNumber() const
{
    return FlightNumber;
}

const Luggage& Passenger::GetLuggage() const
{
    return *PassengerLuggage;
}

std::ostream& operator<<(std::ostream& os, const Passenger& passenger)
{
    os << "Name: " << passenger.GetFullName() << std::endl;
    os << "Flight number: " << passenger.GetFlightNumber() << std::endl;
    os << "Luggage: " << passenger.GetLuggage() << std::endl;
    return os;
}
