//
// Created by Simon Bruno on 10/05/2022.
//

#ifndef AIRPORTPROJECT_PILOT_H
#define AIRPORTPROJECT_PILOT_H

#include "employee.h"
#include "airCrew.h"

class Pilot : public Employee, public AirCrew
{
public:
    enum class ePilotRank
    {
        CAPTAIN, FIRST_OFFICER
    };

private:
    ePilotRank pilotRank;

public:
    Pilot(const Employee& employee, const AirCrew& airCrew, ePilotRank pilotRank);

    Pilot(Employee&& employee, AirCrew&& airCrew, ePilotRank pilotRank);

    Pilot(const Pilot& other);

    Pilot(Pilot&& other);

    ~Pilot();

    void setPilotRank(ePilotRank pilotRank);

    ePilotRank getPilotRank();

    const Pilot& operator=(const Pilot& other);

    const Pilot& operator=(Pilot&& other);

    friend ostream& operator<<(ostream& os, const Pilot& pilot);

};

#endif //AIRPORTPROJECT_PILOT_H
