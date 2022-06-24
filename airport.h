//
// Created by Eddie Rudoy on 09/05/2022.
//

// ReSharper disable CppClangTidyModernizeAvoidCArrays
#pragma once

#include "flight.h"
#include "groundCrew.h"
#include <iostream>

class Airport
{

    std::string Iata; // IATA- 3 letter airport code (eg. London Heathrow- LHR)
    std::string Name;
    std::string City;
    std::vector<Flight> Flights;
    std::vector<GroundCrew> GroundCrews;

public:
    Airport(const std::string& iata, const std::string& name, const std::string& city);

    const std::string& GetIata() const;

    void SetIata(const std::string& iata);

    const std::string& GetCity();
	
    void SetCity(const std::string& city);

    const std::string& GetName();

    void SetName(const std::string& name);

    std::vector<Flight>& GetFlights();

    const std::vector<GroundCrew>& GetGroundCrew() const;

    bool operator==(const Airport& airport) const;

    friend std::ostream& operator<<(std::ostream& os, const Airport& airport);
    Airport& operator+=(const Flight& flight);
    Airport& operator+=(const GroundCrew& crew);
};
