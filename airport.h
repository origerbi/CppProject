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
    static constexpr int MAX_FLIGHTS = 10;
    static constexpr int MAX_CREW = 10;

    char Iata[4]{}; // IATA- 3 letter airport code (eg. London Heathrow- LHR)
    char Name[50]{};
    char City[50]{};
    Flight* Flights[MAX_FLIGHTS]{};
    GroundCrew* GroundCrews[MAX_CREW]{};
    int NumOfFlights{};
    int NumOfCrew{};

public:
    Airport(const char* iata, const char* name, const char* city);

    Airport(const Airport& other) = default;

    Airport(Airport&& other) = default;

    ~Airport();

    Airport& operator=(const Airport& other) = default;

    Airport& operator=(Airport&& other) = default;

    const char* GetIata() const;

    void SetIata(const char* iata);

    char* GetCity();

    void SetCity(const char* city);

    char* GetName();

    void SetName(const char* name);

    Flight* const* GetFlights();

    GroundCrew* const* GetGroundCrew() const;

    int GetNumOfFlights() const;

    int GetNumOfCrew() const;

    bool operator==(const Airport& airport) const;

    friend std::ostream& operator<<(std::ostream& os, const Airport& airport);
    Airport& operator+=(Flight* flight);
    Airport& operator+=(const GroundCrew& crew);
};
