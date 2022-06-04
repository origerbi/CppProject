//
// Created by Simon Bruno on 10/05/2022.
//

#pragma once

#include "airCrew.h"
#include "employee.h"

class FlightAttendant : public Employee, public AirCrew
{
public:
    enum class EFlightAttendantRank
    {
        Pursers,
        Stewards
    };

private:
    EFlightAttendantRank FlightAttendantRank;

public:
    FlightAttendant(const Employee& employee, const AirCrew& airCrew, EFlightAttendantRank flightAttendantRank);

    FlightAttendant(Employee&& employee, AirCrew&& airCrew, EFlightAttendantRank flightAttendantRank);

    FlightAttendant(const FlightAttendant& other) = default;

    FlightAttendant(FlightAttendant&& other) noexcept = default;

    ~FlightAttendant() = default;

    void SetAttendantRank(EFlightAttendantRank flightAttendantRank);

    EFlightAttendantRank GetAttendantRank() const;

    FlightAttendant& operator=(const FlightAttendant& other) = default;

    FlightAttendant& operator=(FlightAttendant&& other) noexcept = default;

    friend std::ostream& operator<<(std::ostream& os, const EFlightAttendantRank& flightAttendantRank)
    {
        switch (flightAttendantRank)
        {
        case EFlightAttendantRank::Pursers:
            os << "Pursers";
            break;
        case EFlightAttendantRank::Stewards:
            os << "Stewards";
            break;
        }
        return os;
    }

    friend std::ostream& operator<<(std::ostream& os, const FlightAttendant& flightAttendant);
};
