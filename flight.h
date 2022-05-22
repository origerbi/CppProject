//
// Created by Eddie Rudoy on 09/05/2022.
//

#ifndef AIRPORTPROJECT_FLIGHT_H
#define AIRPORTPROJECT_FLIGHT_H

#include <iostream>
#include <ctime>
#include "passenger.h"
#include "plane.h"
#include "date.h"

using namespace std;

class AirCrew;

class Flight
{
private:
    static constexpr int MAX_CAPACITY = 20;
    static constexpr int MAX_AIRCREW = 5;

    int flightNumber;
    char* src; // From
    char* dst; // To
    Date dateDeparture;
    Passenger* passengers[MAX_CAPACITY];
    AirCrew* airCrew[MAX_AIRCREW];
    Plane* plane;

    int numOfPassengers;
    int numOfAirCrew;

public:
    Flight(int flightNumber, char* src, char* dst, Date dateDeparture);

    Flight(const Flight& other);

    Flight(Flight&& other);

    ~Flight();

    const Flight& operator=(const Flight& other);

    const Flight& operator=(Flight&& other);

    int getFlightNumber() const;

    void setFlightNumber(int flightNumber);

    char* getSrc() const;

    void setSrc(char* src);

    char* getDst() const;

    void setDst(char* dst);

    Date getDateDeparture();

    void setDateDeparture(Date dateDeparture);

    Passenger* const* getPassengers() const;

    AirCrew* const* getAirCrew() const;

    Plane* getPlane() const;

    void setPlane(Plane* plane);

    const Flight& operator+=(const Passenger& passenger); // add passenger to flight
    const Flight& operator+=(const AirCrew& airCrew); // add air crew to flight
    bool operator<(int capacity); // check if there are available seats
    bool operator==(const Flight& flight); // check if same flight


    friend ostream& operator<<(ostream& os, const Flight& flight);
};


#endif //AIRPORTPROJECT_FLIGHT_H
