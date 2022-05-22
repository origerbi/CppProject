//
// Created by Eddie Rudoy on 10/05/2022.
//

#ifndef AIRPORTPROJECT_AIRPORTMANAGER_H
#define AIRPORTPROJECT_AIRPORTMANAGER_H

#include <iostream>
#include "airline.h"
#include "airport.h"
#include "employee.h"
#include "airCrew.h"
#include "groudCrew.h"
#include "groundAttendant.h"
#include "pilot.h"
#include "flightAttendant.h"

class AirportManager
{
private:
    static constexpr int MAX_AIRPORTS = 5;
    static constexpr int MAX_AIRLINES = 10;

    Airport* airports[MAX_AIRPORTS];
    Airline* airlines[MAX_AIRLINES];

    int numOfAirports;
    int numOfAirlines;

public:
    AirportManager();

    AirportManager(const AirportManager& other);

    AirportManager(AirportManager&& other);

    ~AirportManager();

    Airport* const* getAirports() const;

    Airline* const* getAirlines() const;

    int getNumOfAirports() const;

    int getNumOfAirlines() const;

    const AirportManager& operator+=(const Airport& airport); // add airport to airport manager
    const AirportManager& operator+=(const Airline& airline); // add airline to airport manager

    Airport* findAirportByCode(char* code);

    Airline* findAirline(char* name);

    void findFlights(char* src, char* dest);

    bool registerFlight(Airline& airline, const Flight& flight);

    bool addPassengerToFlight(Passenger& passenger, int flightNumber);

    bool addEmployeeToAirport(GroundAttendant& employee, char* code);

    bool addPilotToAirline(Pilot& employee, int id);

    bool addFlightAttendantToAirline(FlightAttendant& employee, int id);

    Flight& assembleCrew(int flightNumber);

    friend ostream& operator<<(ostream& os, const AirportManager& airportManager);

    friend ostream& operator<<(ostream& os, const Airport** airports);

    friend ostream& operator<<(ostream& os, const Airline** airlines);

};


#endif //AIRPORTPROJECT_AIRPORTMANAGER_H
