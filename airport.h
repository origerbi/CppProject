//
// Created by Eddie Rudoy on 09/05/2022.
//

#ifndef AIRPORTPROJECT_AIRPORT_H
#define AIRPORTPROJECT_AIRPORT_H

#include <iostream>
#include "flight.h"
#include "airline.h"
#include "groudCrew.h"

using namespace std;

class Airport
{
private:
    static constexpr int MAX_FLIGHTS = 10;
    static constexpr int MAX_CREW = 10;

    char* iata; // IATA- 3 letter airport code (eg. London Heathrow- LHR)
    char* name;
    char* city;
    Flight* flights[MAX_FLIGHTS];
    GroundCrew* groundCrew[MAX_CREW];
    int numOfFlights;
    int numOfCrew;

public:
    Airport(char* iata, char* name, char* city);

    Airport(const Airport& other);

    Airport(Airport&& other);

    ~Airport();

    const Airport& operator=(const Airport& other);

    const Airport& operator=(Airport&& other);

    char* getIata() const;

    void setIata(char* iata);

    char* getCity() const;

    void setCity(char* city);

    char* getName() const;

    void setName(char* name);

    Flight* const* getFlights();

    GroundCrew* const* getGroundCrew() const;

    int getNumOfFlights() const;

    int getNumOfCrew() const;

    bool operator==(const Airport& airport);

    friend ostream& operator<<(ostream& os, const Airport& airport);
};

#endif //AIRPORTPROJECT_AIRPORT_H
