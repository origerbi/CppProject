#include "airportManager.h"

AirportManager* AirportManager::instance = nullptr;

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
    Airlines.push_back(airline);
    return *this;
}

Airport* AirportManager::FindAirportByCode(const std::string& code) const
{
    const LinkedList<Airport>* temp = &Airports;
    if (!temp->HasNext())
    {
        return nullptr;
    }
    do
    {
        temp = temp->Next;
        if (temp->Value->GetIata() == code)
        {
            return temp->Value;
        }
    }
    while (temp->HasNext());
    return nullptr;
}

Airline* AirportManager::FindAirline(const std::string& name)
{
	for (auto& airline : Airlines) {
        if (airline.GetName() == name)
        {
            return &airline;
        }
    }
    return nullptr;
}

void AirportManager::DisplayFilteredFlights(const std::string& src, const std::string& dest) const
{
    Airport* srcAirport = FindAirportByCode(src);
    if (srcAirport != nullptr)
    {
        const std::vector<Flight>& flights = srcAirport->GetFlights();
		for (auto& flight : flights) {
            if (flight.GetDst() == dest)
            {
                std::cout << flight << std::endl;
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
        *srcAirport += flight;
        *destAirport += flight;
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
        std::vector<Flight>& flights = airport->GetFlights();
		for (Flight& flight : flights) {
            if (flight.GetFlightNumber() == flightNumber)
            {
                flight += passenger;
                return true;
            }
        }
    }
    while (temp->HasNext());
    return false;
}

bool AirportManager::AddEmployeeToAirport(const GroundAttendant& employee, const std::string& code) const
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
        std::vector<Flight> flights = airport->GetFlights();
		for (auto& flight : flights) {
            if (flight.GetFlightNumber() == flightNumber)
            {
                return &flight;
            }
        }
    }
    while (temp->HasNext());
    return nullptr;
}

AirportManager* AirportManager::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new AirportManager();
	}
    return instance;
}
