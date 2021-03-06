#include "passenger.h"

Passenger::Passenger(const Person& base, int flightNumber, const Luggage& luggage) : Person(base), FlightNumber(flightNumber), PassengerLuggage(new Luggage(luggage))
{
}

Passenger::Passenger(Person&& base, int flightNumber, const Luggage& luggage) : Person(base), FlightNumber(flightNumber), PassengerLuggage(new Luggage(luggage))
{
}

Passenger::Passenger(const Passenger& other) : Person(other), FlightNumber(other.GetFlightNumber()),
                                               PassengerLuggage(new Luggage(other.GetLuggage()))
{
}

Passenger::~Passenger()
{
    delete PassengerLuggage;
}

void Passenger::SetFlightNumber(int flightNumber)
{
    FlightNumber = flightNumber;
}

void Passenger::SetLuggage(const Luggage& luggage) const
{
    *PassengerLuggage = luggage;
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
