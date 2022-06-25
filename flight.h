//
// Created by Eddie Rudoy on 09/05/2022.
//

// ReSharper disable CppClangTidyModernizeAvoidCArrays
#pragma once

#include "airCrew.h"
#include "date.h"
#include "passenger.h"
#include "plane.h"
#include <iostream>

#include "airline.h"

class Flight
{
    int FlightNumber;
    std::string Src; // From
    std::string Dst; // To
    Date DateDeparture;
    Airline* TheAirline;
    std::vector<Passenger> Passengers;
    std::vector<AirCrew> AirCrews;
    Plane* ThePlane{};

public:
    Flight(int flightNumber, std::string src, std::string dst, Date dateDeparture, Airline* airline, Plane* plane);

    int GetFlightNumber() const;

    Airline* GetAirline() const;

    void SetFlightNumber(int flightNumber);

    const std::string& GetSrc() const;

    void SetSrc(const std::string& src);

    const std::string& GetDst() const;

    void SetDst(const std::string& dst);

    Date GetDateDeparture() const;

    void SetDateDeparture(Date dateDeparture);

    const std::vector<Passenger>& GetPassengers() const;

    const std::vector<AirCrew>& GetAirCrew() const;

    Plane* GetPlane() const;

    void SetPlane(Plane* plane);

    const Flight& operator+=(const Passenger& passenger); // add passenger to flight
    const Flight& operator+=(const AirCrew& airCrew); // add air crew to flight
    bool operator<(size_t capacity) const; // check if there are available seats
    bool operator==(const Flight& flight) const; // check if same flight


    friend std::ostream& operator<<(std::ostream& os, const Flight& flight);
};
