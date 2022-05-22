//
// Created by Eddie Rudoy on 09/05/2022.
//

#pragma once

#include "person.h"
#include "luggage.h"

class Passenger : virtual public Person
{
protected:
    int FlightNumber;
    Luggage* PassengerLuggage;

public:
    Passenger(const Person& base, int flightNumber, Luggage& luggage);

    Passenger(Person&& base, int flightNumber, Luggage& luggage);

    Passenger(const Passenger& other) = default;

    Passenger(Passenger&& other) noexcept = default;

    ~Passenger() = default;

    Passenger& operator=(const Passenger& other) = default;

    Passenger& operator=(Passenger&& other) noexcept = default;

    void SetFlightNumber(int flightNumber);

    void SetLuggage(Luggage& luggage);

    int GetFlightNumber() const;

    const Luggage& GetLuggage() const;

    friend std::ostream& operator<<(std::ostream& os, const Passenger& passenger);

};
