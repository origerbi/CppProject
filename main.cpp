// ReSharper disable CppClangTidyModernizeAvoidCArrays
#include "airportManager.h"
#include "airport.h"
#include "date.h"
#include <iostream>

void AddAirline(AirportManager* pManager);

void AddAirport(AirportManager* pManager);

Employee InitEmployee();

void AddEmployeeAirport(AirportManager* pManager);

void AddEmployeeAirline(AirportManager* pManager);

void RegisterFlight(AirportManager* pManager);

void AssembleCrew(AirportManager* pManager);

void FindFlights(AirportManager* pManager);

void DisplayFlights(const AirportManager* pManager);

void AddPassengerToFlight(const AirportManager* pManager);

void DisplayAirports(const AirportManager* pManager);

void DisplayAirlines(const AirportManager* pManager);


using namespace std;

int Menu()
{
    int option;
    cout << "Welcome to Airports System Manager\nPlease Make your choice:\n";
    cout << "1 - Add airport\n";
    cout << "2 - Add airline\n";
    cout << "3 - Add employee to Airport\n";
    cout << "4 - Add employee to Airline\n";
    cout << "5 - Register flight\n";
    cout << "6 - Add passenger to flight\n";
    cout << "7 - Assemble crew to flight\n";
    cout << "8 - Find flights - between 2 airports\n";
    cout << "9 - Display Flights\n";
    cout << "10 - EXIT\n";
    cin >> option;

    return option;
}


int main() // NOLINT(bugprone-exception-escape)
{
    AirportManager manager{};
    bool ok = true;

    do
    {
        Menu();
        const int option = Menu();
        switch (option)
        {
        case 1:
            AddAirport(&manager);
            break;
        case 2:
            AddAirline(&manager);
            break;
        case 3:
            AddEmployeeAirport(&manager);
            break;
        case 4:
            AddEmployeeAirline(&manager);
            break;
        case 5:
            RegisterFlight(&manager);
            break;
        case 6:
            AddPassengerToFlight(&manager);
            break;
        case 7:
            AssembleCrew(&manager);
            break;
        case 8:
            FindFlights(&manager);
            break;
        case 9:
            DisplayFlights(&manager);
            break;
        case 10: // exit
            ok = true;
            break;
        default:
            cout << "Wrong option\n";
            break;
        }
    }
    while (!ok);

    return 0;
}

void AddAirport(AirportManager* pManager)
{
    char iata[4];
    char name[50];
    char city[50];
    cout << "Add New Airport\n";
    cout << "Enter airport's IATA code (3 chars code, e.g London Heathrow- LHR)\n";
    cin >> iata;
    cout << "Enter airport's name (e.g London Heathrow)\n";
    cin >> name;
    cout << "Enter airport's city\n";
    cin >> city;
    const Airport airport{iata, name, city};

    *pManager += airport;
}

void AddAirline(AirportManager* pManager)
{
    char name[50];
    cout << "Add New Airline\n";
    cout << "Enter airline's name\n";
    cin >> name;

    const Airline airline{name};

    *pManager += airline;
}

Employee InitEmployee()
{
    char firstName[50];
    char lastName[50];
    int day;
    int month;
    int year;
    int dayStart;
    int monthStart;
    int yearStart;
    double salary;
    cin >> firstName;
    cout << "Enter Last Name\n";
    cin >> lastName;
    cout << "Enter birthdate\n";
    cin >> day >> month >> year;
    cout << "Enter Salary\n";
    cin >> salary;
    cout << "Enter date start work\n";
    cin >> dayStart >> monthStart >> yearStart;

    return {Person(firstName, lastName, Date(day, month, year)), salary, Date(dayStart, monthStart, yearStart)};
}

void AddEmployeeAirport(AirportManager* pManager)
{
    char code[4];
    cout << "Add employee to airport\n";
    const Employee employee = InitEmployee();

    cout << "Choose airport by code\n";
    DisplayAirports(pManager);
    cin >> code;

    GroundAttendant groundAttendant{employee, GroundCrew(code)};
    pManager->AddEmployeeToAirport(groundAttendant, code);
}

Pilot* InitPilot(const Employee& employee, const int airlineId)
{
    int rank;
    cout << "Choose pilots rank\n";
    cout << "0 - Captain\n1 - FIRST_OFFICER\n";
    cin >> rank;

    return new Pilot(employee, AirCrew(airlineId), static_cast<Pilot::EPilotRank>(rank));
}

FlightAttendant* InitFlightAttendant(const Employee& employee, const int airlineId)
{
    int rank;
    cout << "Choose Flight Attendant's rank\n";
    cout << "0 - Purser\n1 - Steward\n";
    cin >> rank;

    return new FlightAttendant(employee, AirCrew(airlineId), static_cast<FlightAttendant::EFlightAttendantRank>(rank));
}

void AddEmployeeAirline(AirportManager* pManager)
{
    int id;
    int choice;
    cout << "Add employee to airline\n";
    const Employee employee = InitEmployee();

    cout << "Choose airline by id\n";
    DisplayAirports(pManager);
    cin >> id;

    cout << "0 - Flight Attendant\n1 - Pilot\n";
    cin >> choice;

    if (choice == 1)
    {
        Pilot* pilot = InitPilot(employee, id);
        pManager->AddPilotToAirline(*pilot, id);
        delete pilot;
    }
    else
    {
        FlightAttendant* flightAttendant = InitFlightAttendant(employee, id);
        pManager->AddFlightAttendantToAirline(*flightAttendant, id);
        delete flightAttendant;
    }
}

void RegisterFlight(AirportManager* pManager)
{
    char airlineName[50];

    cout << "Register Flight\n";
    cout << "Choose airline:\n";
    cout << pManager->GetAirlines();
    cin >> airlineName;
    const Airline* airline = pManager->FindAirline(airlineName);
    if (airline != nullptr)
    {
        int month;
        int year;
        int day;
        char dest[4];
        char src[4];
        int flightNumber;
        cout << "Enter flight number\n";
        cin >> flightNumber;
        cout << "Enter airport departure\n";
        cin >> src;
        cout << "Enter airport arrival\n";
        cin >> dest;
        cout << "Enter day of departure(day month year)\n";
        cin >> day >> month >> year;
        const Flight flight{flightNumber, src, dest, Date(day, month, year)};
        pManager->RegisterFlight(*airline, flight);
    }
}


void AddPassengerToFlight(const AirportManager* pManager)
{
    char firstName[50];
    char lastName[50];
    int day;
    int month;
    int year;
    int flightNumber;
    double lWeight;
    cout << "Add passenger to flight\n";
    cout << "Enter First Name\n";
    cin >> firstName;
    cout << "Enter Last Name\n";
    cin >> lastName;
    cout << "Enter birthdate\n";
    cin >> day >> month >> year;
    cout << "Enter luggage weight\n";
    cin >> lWeight;
    cout << "Choose flight by number\n";
    DisplayFlights(pManager);
    cin >> flightNumber;

    const Passenger p{Person(firstName, lastName, Date(day, month, year)), flightNumber, Luggage(0, lWeight)};
    cout << "success: " << pManager->AddPassengerToFlight(p, flightNumber) << endl;
}

void AssembleCrew(AirportManager* pManager)
{
    int flightNumber;
    cout << "Choose flight to assign crew\n";
    DisplayFlights(pManager);
    cin >> flightNumber;

    pManager->AssembleCrew(flightNumber);
}

void FindFlights(AirportManager* pManager)
{
    char src[4];
    char dest[4];

    cout << "Find Flights between 2 airports\n";
    cout << "Enter Source Airport code (IATA)\n";
    cin >> src;
    cout << "Enter Destination Airport code (IATA)\n";
    cin >> dest;

    pManager->FindFlights(src, dest);
}

void DisplayFlights(const AirportManager* pManager)
{
    cout << "Display Flight Board\n";
    for (int i = 0; i < pManager->GetNumOfAirports(); ++i)
    {
        cout << pManager->GetAirports()[i]->GetFlights();
    }
}

void DisplayAirports(const AirportManager* pManager)
{
    cout << "Display Airports\n";
    cout << pManager->GetAirports();
}

void DisplayAirlines(const AirportManager* pManager)
{
    cout << "Display Airlines\n";
    cout << pManager->GetAirlines();
}