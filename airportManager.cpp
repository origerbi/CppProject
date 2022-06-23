#include "airportManager.h"

LinkedList<Airport>* AirportManager::GetAirports()
{
    return &Airports;
}

std::vector<Airline>& AirportManager::GetAirlines()
{
    return Airlines;
}

const AirportManager& AirportManager::operator+=(const Airport& airport)
{
    Airports.AddItem(airport);
    return *this;
}

const AirportManager& AirportManager::operator+=(const Airline& airline)
{
    Airlines.emplace_back(airline);
    return *this;
}

Airport* AirportManager::FindAirportByCode(const char* code) const
{
    const LinkedList<Airport>* temp = &Airports;
    if (!temp->HasNext())
    {
        return nullptr;
    }
    do
    {
        temp = temp->Next;
        if (strcmp(temp->Value->GetIata(), code) == 0)
        {
            return temp->Value;
        }
    }
    while (temp->HasNext());
    return nullptr;
}

Airline* AirportManager::FindAirline(const char* name) const
{
    for (auto iterator = Airlines.begin(); iterator != Airlines.end(); ++iterator)
    {
        if (strcmp(iterator->GetName(), name) == 0)
        {
            return iterator._Ptr;
        }
    }
    return nullptr;
}

void AirportManager::DisplayFilteredFlights(const char* src, const char* dest) const
{
    Airport* srcAirport = FindAirportByCode(src);
    if (srcAirport != nullptr)
    {
        Flight* const* flights = srcAirport->GetFlights();
        const int numFlights = srcAirport->GetNumOfFlights();
        for (int i = 0; i < numFlights; i++)
        {
            if (strcmp(flights[i]->GetDst(), dest) == 0)
            {
                std::cout << *flights[i] << std::endl;
            }
        }
    }
}

bool AirportManager::RegisterFlight(const Flight& flight) const
{
    Airport* srcAirport = FindAirportByCode(flight.GetSrc());
    Airport* destAirport = FindAirportByCode(flight.GetDst());
    if (srcAirport != nullptr && destAirport != nullptr)
    {
        auto* const f = new Flight(flight);
        *srcAirport += f;
        *destAirport += f;
        return true;
    }
    return false;
}

bool AirportManager::AddPassengerToFlight(const Passenger& passenger, const int flightNumber) const
{
    const LinkedList<Airport>* temp = &Airports;
    if (!temp->HasNext())
    {
        return false;
    }
    do
    {
        temp = temp->Next;
        Airport* airport = temp->Value;
        Flight* const* flights = airport->GetFlights();
        for (int j = 0; j < airport->GetNumOfFlights(); j++)
        {
            Flight* flight = flights[j];
            if (flight->GetFlightNumber() == flightNumber)
            {
                *flight += passenger;
                return true;
            }
        }
    }
    while (temp->HasNext());
    return false;
}

bool AirportManager::AddEmployeeToAirport(const GroundAttendant& employee, const char* code) const
{
    Airport* airport = FindAirportByCode(code);
    if (airport == nullptr)
    {
        return false;
    }
    *airport += employee;
    return true;
}

bool AirportManager::AddPilotToAirline(const Pilot& employee, const int id) const
{
    for (auto iterator = Airlines.begin(); iterator != Airlines.end(); ++iterator)
    {
        if (iterator->GetId() == id)
        {
            *iterator._Ptr += employee;
            return true;
        }
    }
    return false;
}

bool AirportManager::AddFlightAttendantToAirline(const FlightAttendant& employee, const int id) const
{
    for (auto iterator = Airlines.begin(); iterator != Airlines.end(); ++iterator)
    {
        if (iterator->GetId() == id)
        {
            *iterator._Ptr += employee;
            return true;
        }
    }
    return false;
}

Flight* AirportManager::FindFlight(const int flightNumber) const
{
    const LinkedList<Airport>* temp = &Airports;
    if (!temp->HasNext())
    {
        return nullptr;
    }
    do
    {
        temp = temp->Next;
        Airport* airport = temp->Value;
        Flight* const* flights = airport->GetFlights();
        for (int j = 0; j < airport->GetNumOfFlights(); j++)
        {
            Flight* flight = flights[j];
            if (flight->GetFlightNumber() == flightNumber)
            {
                return flight;
            }
        }
    }
    while (temp->HasNext());
    return nullptr;
}
