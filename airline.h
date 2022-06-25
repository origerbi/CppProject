//
// Created by Eddie Rudoy on 09/05/2022.
//

// ReSharper disable CppClangTidyModernizeAvoidCArrays
#pragma once

#include "flightAttendant.h"
#include "pilot.h"
#include "plane.h"
#include <iostream>
#include <vector>

class Airline
{
    static int Counter;

    int Id{};
    std::string Name;
    std::vector<Plane> Planes;
    std::vector<Pilot> Pilots;
    std::vector<FlightAttendant> FlightAttendants;

public:
    explicit Airline(std::string name);

    int GetId() const;

    const std::string& GetName() const;

    void SetName(const std::string& name);

    std::vector<Plane>& GetPlanes();

    std::vector<Pilot>& GetPilots();

    std::vector<FlightAttendant>& GetFlightAttendants();

    const Airline& operator+=(const Plane& plane); // add plane to airline
    const Airline& operator+=(const Pilot& pilot); // add pilot to flight
    const Airline& operator+=(const FlightAttendant& flightAttendant); // add flight attendant to flight

    friend std::ostream& operator<<(std::ostream& os, Airline& airline);
};
