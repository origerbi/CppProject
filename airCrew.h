//
// Created by Simon Bruno on 10/05/2022.
//

#ifndef AIRPORTPROJECT_AIRCREW_H
#define AIRPORTPROJECT_AIRCREW_H

#include <iostream>

using namespace std;

class AirCrew
{
protected:
    int airlineId;

public:
    AirCrew(int airlineId);

    AirCrew(const AirCrew& other);

    AirCrew(AirCrew&& other);

    ~AirCrew();

    const AirCrew& operator=(const AirCrew& other);

    const AirCrew& operator=(AirCrew&& other);

    int getAirlineId();

    friend ostream& operator<<(ostream& os, const AirCrew& airCrew);
};

#endif //AIRPORTPROJECT_AIRCREW_H
