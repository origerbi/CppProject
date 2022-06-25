//
// Created by Eddie Rudoy on 10/05/2022.
//

// ReSharper disable CppClangTidyModernizeAvoidCArrays
#pragma once

#include <vector>

#include "airline.h"
#include "airport.h"
#include "flightAttendant.h"
#include "groundAttendant.h"
#include "pilot.h"

#include "linkedList.h"

class AirportManager
{
	LinkedList<Airport> Airports;
	std::vector<Airline> Airlines;
	static AirportManager* Instance;
	AirportManager() = default;
	~AirportManager() = default;

public:
	AirportManager(AirportManager& other) = delete;
	AirportManager(AirportManager&& other) = delete;
	AirportManager& operator=(AirportManager& other) = delete;
	AirportManager& operator=(AirportManager&& other) = delete;
	LinkedList<Airport>* GetAirports();

	std::vector<Airline>& GetAirlines();

	const AirportManager& operator+=(const Airport& airport); // add airport to airport manager
	const AirportManager& operator+=(const Airline& airline); // add airline to airport manager

	Airport* FindAirportByCode(const std::string& code) const;

	Airline* FindAirline(const std::string& name);

	void DisplayFilteredFlights(const std::string& src, const std::string& dest) const;

	bool RegisterFlight(const Flight& flight) const;

	bool AddPassengerToFlight(const Passenger& passenger, int flightNumber) const;

	bool AddEmployeeToAirport(const GroundAttendant& employee, const std::string& code) const;

	bool AddPilotToAirline(const Pilot& employee, int id) const;

	bool AddFlightAttendantToAirline(const FlightAttendant& employee, int id) const;

	Flight* FindFlight(int flightNumber) const;

	static AirportManager* GetInstance();
};
