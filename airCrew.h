//
// Created by Simon Bruno on 10/05/2022.
//

#pragma once

#include <iostream>

class AirCrew
{
protected:
    int AirlineId;

public:
    virtual ~AirCrew() = default;
    AirCrew& operator=(const AirCrew&) = delete;
    AirCrew& operator=(AirCrew&&) = delete;
    AirCrew(AirCrew&&) = default;
    AirCrew(const AirCrew&) = default;
    explicit AirCrew(int airlineId);

    int GetAirlineId() const;

    virtual void Print(std::ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os, const AirCrew& airCrew);
};
