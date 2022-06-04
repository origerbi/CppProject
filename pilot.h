//
// Created by Simon Bruno on 10/05/2022.
//

#pragma once

#include "airCrew.h"
#include "employee.h"

class Pilot : public Employee, public AirCrew
{
public:
    enum class EPilotRank
    {
        Captain,
        FirstOfficer
    };

private:
    EPilotRank PilotRank;

public:
    Pilot(const Employee& employee, const AirCrew& airCrew, EPilotRank pilotRank);

    Pilot(Employee&& employee, AirCrew&& airCrew, EPilotRank pilotRank);

    Pilot(const Pilot& other) = default;

    Pilot(Pilot&& other) noexcept = default;

    ~Pilot() = default;

    void SetPilotRank(EPilotRank pilotRank);

    EPilotRank GetPilotRank() const;

    Pilot& operator=(const Pilot& other) = default;

    Pilot& operator=(Pilot&& other) noexcept = default;

    friend std::ostream& operator<<(std::ostream& os, const EPilotRank& pilotRank)
    {
        switch (pilotRank)
        {
        case EPilotRank::Captain:
            os << "Captain";
            break;
        case EPilotRank::FirstOfficer:
            os << "First Officer";
            break;
        }
        return os;
    }

    friend std::ostream& operator<<(std::ostream& os, const Pilot& pilot);
};
