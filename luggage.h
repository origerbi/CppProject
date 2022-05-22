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

    Luggage(const Luggage& other) = default;

    Luggage(Luggage&& other) noexcept = default;

    ~Luggage() = default;

    Luggage& operator=(const Luggage& other) = default;

    Luggage& operator=(Luggage&& other) = default;

    int GetId() const;

    void SetId(int id);

    double GetWeight() const;

    void SetWeight(double weight);

    friend std::ostream& operator<<(std::ostream& os, const Luggage& luggage);
};
