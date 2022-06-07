//
// Created by Eddie Rudoy on 10/05/2022.
//

// ReSharper disable CppClangTidyModernizeAvoidCArrays
#pragma once

#include "airline.h"
#include "airport.h"
#include "flightAttendant.h"
#include "groundAttendant.h"
#include "pilot.h"
#include <iostream>

class AirportManager
{
    static constexpr int MAX_AIRPORTS = 5;
    static constexpr int MAX_AIRLINES = 10;

    Airport* Airports[MAX_AIRPORTS];
    Airline* Airlines[MAX_AIRLINES];

    int NumOfAirports;
    int NumOfAirlines;

public:
    AirportManager() = default;

    AirportManager(const AirportManager& other) = default;

    AirportManager(AirportManager&& other) = default;

    AirportManager& operator=(const AirportManager& other) = default;

    AirportManager& operator=(AirportManager&& other) = default;

    ~AirportManager();

    Airport* const* GetAirports() const;

    Airline* const* GetAirlines() const;

    int GetNumOfAirports() const;

    int GetNumOfAirlines() const;

    const AirportManager& operator+=(const Airport& airport); // add airport to airport manager
    const AirportManager& operator+=(const Airline& airline); // add airline to airport manager

    Airport* FindAirportByCode(const char* code) const;

    Airline* FindAirline(const char* name) const;

    void DisplayFilteredFlights(const char* src, const char* dest) const;

    bool RegisterFlight(const Flight& flight) const;

    bool AddPassengerToFlight(const Passenger& passenger, int flightNumber) const;

    bool AddEmployeeToAirport(const GroundAttendant& employee, const char* code) const;

    bool AddPilotToAirline(const Pilot& employee, int id) const;

    bool AddFlightAttendantToAirline(const FlightAttendant& employee, int id) const;

    Flight* FindFlight(int flightNumber) const;

    friend std::ostream& operator<<(std::ostream& os, const AirportManager& airportManager);
};
