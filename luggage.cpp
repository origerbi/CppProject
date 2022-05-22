#include "luggage.h"

Luggage::Luggage(const int id, const double weight) : Id(id), Weight(weight)
{
}

int Luggage::GetId() const
{
    return Id;
}

void Luggage::SetId(const int id)
{
    Id = id;
}

double Luggage::GetWeight() const
{
    return Weight;
}

void Luggage::SetWeight(const double weight)
{
    Weight = weight;
}

std::ostream& operator<<(std::ostream& os, const Luggage& luggage)
{
    os << "Luggage id: " << luggage.GetId() << "; weight: " << luggage.GetWeight() << " kg";
    return os;
}
