#include "airportManager.h"

AirportManager::~AirportManager()
{
    for (int i = 0; i < NumOfAirports; i++)
    {
        delete Airports[i];
    }
    for (int i = 0; i < NumOfAirlines; i++)
    {
        delete Airlines[i];
    }
}

Airport* const* AirportManager::GetAirports() const
{
    return Airports;
}

Airline* const* AirportManager::GetAirlines() const
{
    return Airlines;
}

int AirportManager::GetNumOfAirports() const
{
    return NumOfAirports;
}

int AirportManager::GetNumOfAirlines() const
{
    return NumOfAirlines;
}

const AirportManager& AirportManager::operator+=(const Airport& airport)
{
    if (NumOfAirports < MAX_AIRPORTS)
    {
        Airports[NumOfAirports] = new Airport(airport);
        NumOfAirports++;
    }
    return *this;
}

const AirportManager& AirportManager::operator+=(const Airline& airline)
{
    if (NumOfAirlines < MAX_AIRLINES)
    {
        Airlines[NumOfAirlines] = new Airline(airline);
        NumOfAirlines++;
    }
    return *this;
}

Airport* AirportManager::FindAirportByCode(const char* code) const
{
    for (int i = 0; i < NumOfAirports; i++)
    {
        if (strcmp(Airports[i]->GetIata(), code) == 0)
        {
            return Airports[i];
        }
    }
    return nullptr;
}

Airline* AirportManager::FindAirline(const char* name) const
{
    for (int i = 0; i < NumOfAirlines; i++)
    {
        if (strcmp(Airlines[i]->GetName(), name) == 0)
        {
            return Airlines[i];
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

bool AirportManager::AddPassengerToFlight(const Passenger& passenger, int flightNumber) const
{
    for (int i = 0; i < NumOfAirports; i++)
    {
        Airport* airport = Airports[i];
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
    return false;
}

bool AirportManager::AddEmployeeToAirport(const GroundAttendant& employee, const char* code) const
{
    for (int i = 0; i < NumOfAirports; i++)
    {
        if (strcmp(Airports[i]->GetIata(), code) == 0)
        {
            *Airports[i] += employee;
            return true;
        }
    }
    return false;
}

bool AirportManager::AddPilotToAirline(const Pilot& employee, int id) const
{
    for (int i = 0; i < NumOfAirlines; i++)
    {
        if (Airlines[i]->GetId() == id)
        {
            *Airlines[i] += employee;
            return true;
        }
    }
    return false;
}

bool AirportManager::AddFlightAttendantToAirline(const FlightAttendant& employee, int id) const
{
    for (int i = 0; i < NumOfAirlines; i++)
    {
        if (Airlines[i]->GetId() == id)
        {
            *Airlines[i] += employee;
            return true;
        }
    }
    return false;
}

Flight* AirportManager::FindFlight(int flightNumber) const
{
    for (int i = 0; i < NumOfAirports; i++)
    {
        Airport* airport = Airports[i];
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
    return nullptr;
}
