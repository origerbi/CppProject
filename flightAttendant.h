//
// Created by Simon Bruno on 10/05/2022.
//

#ifndef AIRPORTPROJECT_FLIGHTATTENDANT_H
#define AIRPORTPROJECT_FLIGHTATTENDANT_H

#include "employee.h"
#include "airCrew.h"

class FlightAttendant : public Employee, public AirCrew
{
public:
    enum class eFlightAttendantRank
    {
        PURSERS, STEWARDS
    };

private:
    eFlightAttendantRank flightAttendantRank;

public:
    FlightAttendant(const Employee& employee, const AirCrew& airCrew, eFlightAttendantRank flightAttendantRank);

    FlightAttendant(Employee&& employee, AirCrew&& airCrew, eFlightAttendantRank flightAttendantRank);

    FlightAttendant(const FlightAttendant& other);

    FlightAttendant(FlightAttendant&& other);

    ~FlightAttendant();

    void setAttendantRank(eFlightAttendantRank flightAttendantRank);

    eFlightAttendantRank getAttendantRank();

    const FlightAttendant& operator=(const FlightAttendant& other);

    const FlightAttendant& operator=(FlightAttendant&& other);

    friend ostream& operator<<(ostream& os, const FlightAttendant& flightAttendant);
};

#endif //AIRPORTPROJECT_FLIGHTATTENDANT_H
