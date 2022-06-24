//
// Created by Simon Bruno on 09/05/2022.
//

#pragma once

#include "employee.h"
#include "groundCrew.h"

class GroundAttendant : public Employee, public GroundCrew
{
    int FlightNumber;

public:
    GroundAttendant(const Employee& employee, const GroundCrew& groundCrew);

    GroundAttendant(Employee&& employee, GroundCrew&& groundCrew);

    void SetFlightNumber(int flightNumber);

    int GetFlightNumber() const;

    friend std::ostream& operator<<(std::ostream& os, const GroundAttendant& groundAttendant);
};
