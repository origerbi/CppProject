//
// Created by Eddie Rudoy on 09/05/2022.
//

#ifndef AIRPORTPROJECT_AIRLINE_H
#define AIRPORTPROJECT_AIRLINE_H

#include <iostream>
#include "plane.h"
#include "flight.h"
#include "flightAttendant.h"
#include "pilot.h"

class Airline
{
private:
    static constexpr int MAX_PLANES = 10;
    static constexpr int MAX_PILOTS = 10;
    static constexpr int MAX_CREW = 15;
    static int counter;

    int id;
    char* name;
    Plane* planes[MAX_PLANES];
    Pilot* pilots[MAX_PILOTS];
    FlightAttendant* flightAttendants[MAX_CREW];

    int numOfPlanes;
    int numOfPilots;
    int numOfFlightAttendants;

public:
    Airline(char* name);

    Airline(const Airline& other);

    Airline(Airline&& other);

    ~Airline();

    const Airline& operator=(const Airline& other);

    const Airline& operator=(Airline&& other);

    int getId() const;

    char* getName() const;

    void setName(char* name);

    Plane* const* getPlanes() const;

    Pilot* const* getPilots() const;

    FlightAttendant* const* getFlightAttendants() const;

    const Airline& operator+=(const Plane& plane); // add plane to airline
    const Airline& operator+=(const Pilot& pilot); // add pilot to flight
    const Airline& operator+=(const FlightAttendant& flightAttendants); // add flight attendant to flight

    friend ostream& operator<<(ostream& os, const Airline& airline);

    friend ostream& operator<<(ostream& os, const Flight** flights);

};


#endif //AIRPORTPROJECT_AIRLINE_H
