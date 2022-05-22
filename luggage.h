//
// Created by Eddie Rudoy on 09/05/2022.
//

#ifndef AIRPORTPROJECT_LUGGAGE_H
#define AIRPORTPROJECT_LUGGAGE_H

#include <iostream>

using namespace std;

class Luggage
{
private:
    int id;
    double weight;

public:
    Luggage(int id, double weight);

    Luggage(const Luggage& other);

    Luggage(Luggage&& other);

    ~Luggage();

    const Luggage& operator=(const Luggage& other);

    const Luggage& operator=(Luggage&& other);

    int getId();

    void setId(int id);

    double getWeight();

    void setWeight(double weight);

    friend ostream& operator<<(ostream& os, const Luggage& luggage);
};


#endif //AIRPORTPROJECT_LUGGAGE_H
