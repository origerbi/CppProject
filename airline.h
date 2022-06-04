//
// Created by Eddie Rudoy on 09/05/2022.
//

// ReSharper disable CppClangTidyModernizeAvoidCArrays
#pragma once

#include "flightAttendant.h"
#include "pilot.h"
#include "plane.h"
#include <iostream>

class Airline
{
    static constexpr int MAX_PLANES = 10;
    static constexpr int MAX_PILOTS = 10;
    static constexpr int MAX_CREW = 15;
    static int Counter;

    int Id{};
    char* Name;
    Plane* Planes[MAX_PLANES]{};
    Pilot* Pilots[MAX_PILOTS]{};
    FlightAttendant* FlightAttendants[MAX_CREW]{};

    int NumOfPlanes{};
    int NumOfPilots{};
    int NumOfFlightAttendants{};

public:
    explicit Airline(char* name);

    Airline(const Airline& other) = default;

    Airline(Airline&& other) = default;

    ~Airline();

    Airline& operator=(const Airline& other) = default;

    Airline& operator=(Airline&& other) = default;

    int GetId() const;

    char* GetName() const;

    void SetName(char* name);

    Plane* const* GetPlanes() const;

    Pilot* const* GetPilots() const;

    FlightAttendant* const* GetFlightAttendants() const;

    const Airline& operator+=(const Plane& plane); // add plane to airline
    const Airline& operator+=(const Pilot& pilot); // add pilot to flight
    const Airline& operator+=(const FlightAttendant& flightAttendants); // add flight attendant to flight

    friend std::ostream& operator<<(std::ostream& os, const Airline& airline);
};
