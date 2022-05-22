//
// Created by Eddie Rudoy on 09/05/2022.
//

#ifndef AIRPORTPROJECT_PLANE_H
#define AIRPORTPROJECT_PLANE_H

#include <iostream>

using namespace std;

class Plane
{
public:
    enum class eAircraft
    {
        AIRBUS_A320, AIRBUS_A321, BOEING_737, BOEING_787
    };

private:
    int id;
    int maxCapacity;
    eAircraft theAircraft;

public:
    Plane(int id, int maxCapacity, eAircraft theAircraft);

    Plane(const Plane& other);

    Plane(Plane&& other);

    ~Plane();

    const Plane& operator=(const Plane& other);

    const Plane& operator=(Plane&& other);

    int getId() const;

    void setId(int id);

    int getMaxCapacity() const;

    void setMaxCapacity(int maxCapacity);

    eAircraft getTheAircraft() const;

    void setTheAircraft(eAircraft theAircraft);

    friend ostream& operator<<(ostream& os, const Plane& plane);
};


#endif //AIRPORTPROJECT_PLANE_H
