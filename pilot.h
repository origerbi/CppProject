//
// Created by Simon Bruno on 10/05/2022.
//

#pragma once

#include "airCrew.h"
#include "employee.h"

class Pilot final : public Employee, public AirCrew
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

    void SetPilotRank(EPilotRank pilotRank);

    EPilotRank GetPilotRank() const;

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

    void Print(std::ostream& os) const override;

    friend std::ostream& operator<<(std::ostream& os, const Pilot& pilot);
};
