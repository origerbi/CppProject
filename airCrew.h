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
    explicit AirCrew(int airlineId);

    AirCrew(const AirCrew& other) = default;

    AirCrew(AirCrew&& other) noexcept = default;

    virtual ~AirCrew() = default;

    AirCrew& operator=(const AirCrew& other) = default;

    AirCrew& operator=(AirCrew&& other) noexcept = default;

    int GetAirlineId() const;

    virtual void Print(std::ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os, const AirCrew& airCrew);
};
