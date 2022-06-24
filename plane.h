//
// Created by Eddie Rudoy on 09/05/2022.
//

#pragma once

#include <iostream>

class Plane
{
public:
    enum class EAircraft
    {
        AirbusA320,
        AirbusA321,
        Boeing737,
        Boeing787
    };

private:
    int Id;
    int MaxCapacity;
    EAircraft TheAircraft;

public:
    Plane(int id, int maxCapacity, EAircraft theAircraft);

    int GetId() const;

    void SetId(int id);

    int GetMaxCapacity() const;

    void SetMaxCapacity(int maxCapacity);

    EAircraft GetTheAircraft() const;

    void SetTheAircraft(EAircraft theAircraft);

    friend std::ostream& operator<<(std::ostream& os, const EAircraft& theAircraft);
    friend std::ostream& operator<<(std::ostream& os, const Plane& plane);
};
