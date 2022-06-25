#include "luggage.h"

Luggage::Luggage(int id, double weight) : Id(id), Weight(weight)
{
}

int Luggage::GetId() const
{
    return Id;
}

void Luggage::SetId(int id)
{
    Id = id;
}

double Luggage::GetWeight() const
{
    return Weight;
}

void Luggage::SetWeight(double weight)
{
    Weight = weight;
}

std::ostream& operator<<(std::ostream& os, const Luggage& luggage)
{
    os << "Luggage id: " << luggage.GetId() << "; weight: " << luggage.GetWeight() << " kg";
    return os;
}
