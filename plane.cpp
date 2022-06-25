#include "plane.h"

Plane::Plane(int id, int maxCapacity, EAircraft theAircraft) : Id(id), MaxCapacity(maxCapacity), TheAircraft(theAircraft)
{
}

int Plane::GetId() const
{
    return Id;
}

void Plane::SetId(int id)
{
    Id = id;
}

int Plane::GetMaxCapacity() const
{
    return MaxCapacity;
}

void Plane::SetMaxCapacity(int maxCapacity)
{
    MaxCapacity = maxCapacity;
}

Plane::EAircraft Plane::GetTheAircraft() const
{
    return TheAircraft;
}

void Plane::SetTheAircraft(EAircraft theAircraft)
{
    TheAircraft = theAircraft;
}

std::ostream& operator<<(std::ostream& os, const Plane::EAircraft& theAircraft)
{
    switch (theAircraft)
    {
    case Plane::EAircraft::Boeing737:
        os << "Boeing 737";
        break;
    case Plane::EAircraft::Boeing787:
        os << "Boeing 787";
        break;
    case Plane::EAircraft::AirbusA320:
        os << "Airbus A320";
        break;
    case Plane::EAircraft::AirbusA321:
        os << "Airbus A321";
        break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Plane& plane)
{
    os << "Id: " << plane.GetId() << std::endl;
    os << "MaxCapacity: " << plane.GetMaxCapacity() << std::endl;
    os << "TheAircraft: " << plane.GetTheAircraft() << std::endl;
    return os;
}
