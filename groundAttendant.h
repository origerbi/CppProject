//
// Created by Simon Bruno on 09/05/2022.
//

#ifndef AIRPORTPROJECT_GROUNDATTENDANT_H
#define AIRPORTPROJECT_GROUNDATTENDANT_H

#include "employee.h"
#include "groudCrew.h"

class GroundAttendant : public Employee, public GroundCrew
{
private:
    int flightNumber;

public:
    GroundAttendant(const Employee& employee, const GroundCrew& groundCrew);

    GroundAttendant(Employee&& employee, GroundCrew&& groundCrew);

    GroundAttendant(const GroundAttendant& other);

    GroundAttendant(GroundAttendant&& other);

    ~GroundAttendant();

    void setFlightNumber(int flightNumber);

    int getFlightNumber();

    const GroundAttendant& operator=(const GroundAttendant& other);

    const GroundAttendant& operator=(GroundAttendant&& other);

    friend ostream& operator<<(ostream& os, const GroundAttendant& groundAttendant);
};

#endif //AIRPORTPROJECT_GROUNDATTENDANT_H
