//
// Created by Eddie Rudoy on 09/05/2022.
//

#ifndef AIRPORTPROJECT_PASSENGER_H
#define AIRPORTPROJECT_PASSENGER_H

#include "person.h"
#include "luggage.h"

class Passenger : virtual public Person
{
protected:
    int flightNumber;
    Luggage* luggage;

public:
    Passenger(const Person& base, int flightNumber, const Luggage& luggage);

    Passenger(Person&& base, int flightNumber, Luggage& luggage);

    Passenger(const Passenger& other);

    Passenger(Passenger&& other);

    ~Passenger();

    const Passenger& operator=(const Passenger& other);

    const Passenger& operator=(Passenger&& other);

    void setFlightNumber(int flightNumber);

    void setLuggage(const Luggage& luggage);

    int getFlightNumber();

    const Luggage& getLuggage();

    friend ostream& operator<<(ostream& os, const Passenger& passenger);

};


#endif //AIRPORTPROJECT_PASSENGER_H
