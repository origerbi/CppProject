//
// Created by Simon Bruno on 09/05/2022.
//

#pragma once

#include <iostream>

class GroundCrew
{
protected:
    std::string AirportId;

public:
    explicit GroundCrew(std::string airportId);

    const std::string& GetAirportId() const;

    friend std::ostream& operator<<(std::ostream& os, const GroundCrew& groundCrew);
};
