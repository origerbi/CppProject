//
// Created by Simon Bruno on 09/05/2022.
//

#ifndef AIRPORTPROJECTCPP_GROUDCREW_H
#define AIRPORTPROJECTCPP_GROUDCREW_H

#include <iostream>

using namespace std;

class GroundCrew
{
protected:
    char* airportId;

public:
    GroundCrew(const char* airportId);

    GroundCrew(const GroundCrew& other);

    GroundCrew(GroundCrew&& other);

    ~GroundCrew();

    const GroundCrew& operator=(const GroundCrew& other);

    const GroundCrew& operator=(GroundCrew&& other);

    char* getAirportId();

    friend ostream& operator<<(ostream& os, const GroundCrew& groundCrew);
};

#endif //AIRPORTPROJECTCPP_GROUDCREW_H
