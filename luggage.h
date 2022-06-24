//
// Created by Eddie Rudoy on 09/05/2022.
//
#pragma once
#include <iostream>

class Luggage
{
    int Id;
    double Weight;

public:
    Luggage(int id, double weight);

    int GetId() const;

    void SetId(int id);

    double GetWeight() const;

    void SetWeight(double weight);

    friend std::ostream& operator<<(std::ostream& os, const Luggage& luggage);
};
