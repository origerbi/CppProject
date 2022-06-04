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

class Flight
{
    static constexpr int MAX_CAPACITY = 20;
    static constexpr int MAX_AIRCREW = 5;

    int FlightNumber;
    char Src[4]; // From
    char Dst[4]; // To
    Date DateDeparture;
    Passenger* Passengers[MAX_CAPACITY]{};
    AirCrew* AirCrews[MAX_AIRCREW]{};
    Plane* ThePlane{};

    int NumOfPassengers{};
    int NumOfAirCrew{};

public:
    Flight(int flightNumber, char* src, char* dst, Date dateDeparture);

    Flight(const Flight& other) = default;

    Flight(Flight&& other) = default;

    ~Flight();

    Flight& operator=(const Flight& other) = default;

    Flight& operator=(Flight&& other) = default;

    int GetFlightNumber() const;

    void SetFlightNumber(int flightNumber);

    const char* GetSrc() const;

    void SetSrc(const char* src);

    const char* GetDst() const;

    void SetDst(const char* dst);

    Date GetDateDeparture() const;

    void SetDateDeparture(Date dateDeparture);

    Passenger* const* GetPassengers() const;

    AirCrew* const* GetAirCrew() const;

    Plane* GetPlane() const;

    void SetPlane(Plane* plane);

    const Flight& operator+=(const Passenger& passenger); // add passenger to flight
    const Flight& operator+=(const AirCrew& airCrew); // add air crew to flight
    bool operator<(int capacity) const; // check if there are available seats
    bool operator==(const Flight& flight) const; // check if same flight


    friend std::ostream& operator<<(std::ostream& os, const Flight& flight);
};
