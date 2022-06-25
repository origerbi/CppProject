// ReSharper disable CppClangTidyModernizeAvoidCArrays
#include "airportManager.h"
#include "airport.h"
#include "date.h"
#include <iostream>

void AddAirline(AirportManager* pManager);

void AddAirport(AirportManager* pManager);

Employee InitEmployee();

void AddEmployeeAirport(const AirportManager* pManager);

void AddEmployeeAirline(const AirportManager* pManager);

void RegisterFlight(const AirportManager* pManager);

void AssembleCrew(const AirportManager* pManager);

void DisplayFilteredFlights(const AirportManager* pManager);

void DisplayFlights(const AirportManager* pManager);

void AddPassengerToFlight(const AirportManager* pManager);

void DisplayAirports(const AirportManager* pManager);

void DisplayAirlines(const AirportManager* pManager);

void AddPlaneToAirline(const AirportManager* pManager);

void AssemblePilots(Flight* flight);

void AssembleFlightAttendants(Flight* flight);

Plane::EAircraft GetAircraftTypeFromUser();


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
    cout << "10 - Add plane to airline\n";
    cout << "11 - EXIT\n";
    cin >> option;

    return option;
}


int main() // NOLINT(bugprone-exception-escape)
{
    AirportManager manager{};
    bool ok = false;

    do
    {
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
            DisplayFilteredFlights(&manager);
            break;
        case 9:
            DisplayFlights(&manager);
            break;
        case 10:
            AddPlaneToAirline(&manager);
            break;
        case 11: // exit
            ok = true;
            break;
        default:
            cout << "Wrong option\n";
            break;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    cout << "Enter employee's first name\n";
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

void AddEmployeeAirport(const AirportManager* pManager)
{
    char code[4];
    cout << "Add employee to airport\n";
    const Employee employee = InitEmployee();

    cout << "Choose airport by code\n";
    DisplayAirports(pManager);
    cin >> code;

    const GroundAttendant groundAttendant{employee, GroundCrew(code)};
    if (pManager->AddEmployeeToAirport(groundAttendant, code))
    {
        cout << "Employee added\n";
    }
    else
    {
        cout << "Employee failed to add\n";
    }
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

void AddEmployeeAirline(const AirportManager* pManager)
{
    int id;
    int choice;
    cout << "Add employee to airline\n";
    const Employee employee = InitEmployee();

    cout << "Choose airline by id\n";
    DisplayAirlines(pManager);
    cin >> id;

    cout << "0 - Flight Attendant\n1 - Pilot\n";
    cin >> choice;

    if (choice == 1)
    {
        const Pilot* pilot = InitPilot(employee, id);
        if (pManager->AddPilotToAirline(*pilot, id))
        {
            cout << "Pilot added\n";
        }
        else
        {
            cout << "Pilot failed to add\n";
        }
        delete pilot;
    }
    else
    {
        const FlightAttendant* flightAttendant = InitFlightAttendant(employee, id);
        if (pManager->AddFlightAttendantToAirline(*flightAttendant, id))
        {
            cout << "Flight Attendant added successfully\n";
        }
        else
        {
            cout << "Flight Attendant failed to add\n";
        }
        delete flightAttendant;
    }
}

void RegisterFlight(const AirportManager* pManager)
{
    char airlineName[50];

    cout << "Register Flight\n";
    cout << "Choose airline by name:\n";
    DisplayAirlines(pManager);
    cin >> airlineName;
    Airline* airline = pManager->FindAirline(airlineName);
    if (airline != nullptr && airline->GetNumOfPlanes() > 0)
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
        Plane* const* planes = airline->GetPlanes();
        const int numPlanes = airline->GetNumOfPlanes();
        cout << "Choose plane\n";
        for (int i = 0; i < numPlanes; i++)
        {
            cout << i << " - " << *planes[i] << endl;
        }
        int planeId;
        cin >> planeId;
        Plane* plane = planes[planeId];
        const Flight flight{flightNumber, src, dest, Date(day, month, year), airline, plane};
        if (pManager->RegisterFlight(flight))
        {
            cout << "Flight registered\n";
        }
        else
        {
            cout << "Flight failed to register\n";
        }
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

void AssembleCrew(const AirportManager* pManager)
{
    int flightNumber;
    cout << "Choose flight to assign crew\n";
    DisplayFlights(pManager);
    cin >> flightNumber;
    Flight* flight = pManager->FindFlight(flightNumber);
    if (flight != nullptr)
    {
        AssemblePilots(flight);
        AssembleFlightAttendants(flight);
    }
    else
    {
        cout << "Flight not found\n";
    }
}

void DisplayFilteredFlights(const AirportManager* pManager)
{
    char src[4];
    char dest[4];

    cout << "Find Flights between 2 airports\n";
    cout << "Enter Source Airport code (IATA)\n";
    cin >> src;
    cout << "Enter Destination Airport code (IATA)\n";
    cin >> dest;

    pManager->DisplayFilteredFlights(src, dest);
}

void DisplayFlights(const AirportManager* pManager)
{
    for (int i = 0; i < pManager->GetNumOfAirports(); ++i)
    {
        Flight* const* flights = pManager->GetAirports()[i]->GetFlights();
        const int numFlights = pManager->GetAirports()[i]->GetNumOfFlights();
        for (int j = 0; j < numFlights; ++j)
        {
            cout << *flights[j] << endl;
        }
    }
}

void DisplayAirports(const AirportManager* pManager)
{
    for (int i = 0; i < pManager->GetNumOfAirports(); ++i)
    {
        cout << i << " - " << *pManager->GetAirports()[i] << endl;
    }
}

void DisplayAirlines(const AirportManager* pManager)
{
    for (int i = 0; i < pManager->GetNumOfAirlines(); ++i)
    {
        cout << i << " - " << *pManager->GetAirlines()[i] << endl;
    }
}

void AddPlaneToAirline(const AirportManager* pManager)
{
    Airline* const* airlines = pManager->GetAirlines();
    cout << "Choose airline:\n";
    for (int i = 0; i < pManager->GetNumOfAirlines(); i++)
    {
        cout << i << " - " << *airlines[i] << endl;
    }
    int airlineId;
    cin >> airlineId;
    Airline* airline = airlines[airlineId];
    if (airline != nullptr)
    {
        cout << "Enter plane ID\n";
        int planeId;
        cin >> planeId;
        cout << "Enter plane capacity\n";
        int capacity;
        cin >> capacity;
        const Plane::EAircraft type = GetAircraftTypeFromUser();
        *airline += Plane(planeId, capacity, type);
    }
}

void AssemblePilots(Flight* flight)
{
    int result;
    Pilot* const* pilots = flight->GetAirline()->GetPilots();
    const int numPilots = flight->GetAirline()->GetNumPilots();
    auto* chosenNumbers = new int[static_cast<size_t>(numPilots)];
    int counter = 0;
    do
    {
        cout << "Choose pilots to assign, press -1 to continue\n";
        for (int i = 0; i < numPilots; i++)
        {
            if (pilots[i]->GetAvailability())
            {
                cout << i << " - " << *pilots[i] << endl;
            }
        }
        cin >> result;
        bool found = false;
        if (result < -1 || result >= numPilots)
        {
            cout << "Invalid input\n";
            continue;
        }
        for (int i = 0; i < counter; i++)
        {
            if (result == chosenNumbers[i])
            {
                found = true;
                break;
            }
        }
        if (!found && result != -1 && pilots[result]->GetAvailability())
        {
            pilots[result]->SetAvailability(false);
            counter++;
            chosenNumbers[counter - 1] = result;
        }
        else if (result != -1)
        {
            cout << "This pilot already been added or is not avaliable\n";
        }
    }
    while (result != -1);
    for (int i = 0; i < counter; i++)
    {
        *flight += pilots[chosenNumbers[i]];
    }
    delete[] chosenNumbers;
}

void AssembleFlightAttendants(Flight* flight)
{
    int result;
    FlightAttendant* const* flightAttendants = flight->GetAirline()->GetFlightAttendants();
    const int numFlightAttendants = flight->GetAirline()->GetNumFlightAttendants();
    auto* chosenNumbers = new int[static_cast<size_t>(numFlightAttendants)];
    int counter = 0;
    do
    {
        cout << "Choose flight attendants to assign, press -1 to continue\n";
        for (int i = 0; i < numFlightAttendants; i++)
        {
            if (flightAttendants[i]->GetAvailability())
            {
                cout << i << " - " << *flightAttendants[i] << endl;
            }
        }
        cin >> result;
        bool found = false;
        if (result < -1 || result >= numFlightAttendants)
        {
            cout << "Invalid input\n";
            continue;
        }
        for (int i = 0; i < counter; i++)
        {
            if (result == chosenNumbers[i])
            {
                found = true;
                break;
            }
        }
        if (!found && result != -1 && flightAttendants[result]->GetAvailability())
        {
            flightAttendants[result]->SetAvailability(false);
            counter++;
            chosenNumbers[counter - 1] = result;
        }
        else if (result != -1)
        {
            cout << "This flight attendant already been added\n";
        }
    }
    while (result != -1);
    for (int i = 0; i < counter; i++)
    {
        *flight += flightAttendants[chosenNumbers[i]];
    }
    delete[] chosenNumbers;
}

Plane::EAircraft GetAircraftTypeFromUser()
{
    cout << "Enter plane type\n";
    cout << "0 - AirbusA320\n";
    cout << "1 - AirbusA321\n";
    cout << "2 - Boeing737\n";
    cout << "3 - Boeing787\n";
    do
    {
        int type;
        cin >> type;
        switch (type)
        {
        case 0:
            return Plane::EAircraft::AirbusA320;
        case 1:
            return Plane::EAircraft::AirbusA321;
        case 2:
            return Plane::EAircraft::Boeing737;
        case 3:
            return Plane::EAircraft::Boeing787;
        default:
            cout << "Invalid input try again\n";
        }
    }
    while (true);
}
