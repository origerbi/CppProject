//
// Created by Eddie Rudoy on 09/05/2022.
//

#pragma once

#include "luggage.h"
#include "person.h"

class Passenger final : virtual public Person
{
protected:
    int FlightNumber;
    Luggage* PassengerLuggage;

public:
    Passenger(const Person& base, int flightNumber, const Luggage& luggage);

    Passenger(Person&& base, int flightNumber, const Luggage& luggage);

    Passenger(const Passenger& other);

    Passenger(Passenger&& other) noexcept = default;

    ~Passenger() override;

    Passenger& operator=(const Passenger& other) = default;

    Passenger& operator=(Passenger&& other) noexcept = default;

    void SetFlightNumber(int flightNumber);

    void SetLuggage(const Luggage& luggage) const;

    int GetFlightNumber() const;

    const Luggage& GetLuggage() const;

    friend std::ostream& operator<<(std::ostream& os, const Passenger& passenger);
};
