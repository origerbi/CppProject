//
// Created by Simon Bruno on 09/05/2022.
//

#pragma once

#include <iostream>

class GroundCrew
{
protected:
    const char* AirportId;

public:
    explicit GroundCrew(const char* airportId);

    GroundCrew(const GroundCrew& other) = default;

    GroundCrew(GroundCrew&& other) noexcept = default;

    ~GroundCrew() = default;

    GroundCrew& operator=(const GroundCrew& other) = default;

    GroundCrew& operator=(GroundCrew&& other) = default;

    const char* GetAirportId() const;

    friend std::ostream& operator<<(std::ostream& os, const GroundCrew& groundCrew);
};
