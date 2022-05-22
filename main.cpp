#include <iostream>
#include "airportManager.h"
#include "airport.h"
#include "date.h"

void addAirline(AirportManager* pManager);

void addAirport(AirportManager* pManager);

Employee initEmployee();

void addEmployeeAirport(AirportManager* pManager);

void addEmployeeAirline(AirportManager* pManager);

void registerFlight(AirportManager* pManager);

void assembleCrew(AirportManager* pManager);

void findFlights(AirportManager* pManager);

void displayFlights(AirportManager* pManager);

void addPassangerToFlight(AirportManager* pManager);

void displayAirports(AirportManager* pManager);

void displayAirlines(AirportManager* pManager);


using namespace std;

int menu()
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


int main()
{
    AirportManager manager;
    bool ok = true;
    int option = 0;

    do {
        menu();
        option = menu();
        switch (option) {
            case 1:
                addAirport(&manager);
                break;
            case 2:
                addAirline(&manager);
                break;
            case 3:
                addEmployeeAirport(&manager);
                break;
            case 4:
                addEmployeeAirline(&manager);
                break;
            case 5:
                registerFlight(&manager);
                break;
            case 6:
                addPassangerToFlight(&manager);
                break;
            case 7:
                assembleCrew(&manager);
                break;
            case 8:
                findFlights(&manager);
                break;
            case 9:
                displayFlights(&manager);
                break;
            case 10: // exit
                ok = true;
                break;
            default:
                cout << "Wrong option\n";
                break;
        }
    } while (!ok);

    return 0;
}

void addAirport(AirportManager* pManager)
{
    char* iata;
    char* name;
    char* city;
    cout << "Add New Airport\n";
    cout << "Enter airport's IATA code (3 chars code, e.g London Heathrow- LHR)\n";
    cin >> iata;
    cout << "Enter airport's name (e.g London Heathrow)\n";
    cin >> name;
    cout << "Enter airport's city\n";
    cin >> city;
    Airport* airport = new Airport(iata, name, city);

    *pManager += *airport;
}

void addAirline(AirportManager* pManager)
{
    char* name;
    cout << "Add New Airline\n";
    cout << "Enter airline's name\n";
    cin >> name;

    Airline* airline = new Airline(name);

    *pManager += *airline;
}

Employee initEmployee()
{
    char* firstName;
    char* lastName;
    int day, month, year;
    int dayStart, monthStart, yearStart;
    int salary;
    cin >> firstName;
    cout << "Enter Last Name\n";
    cin >> lastName;
    cout << "Enter birthdate\n";
    cin >> day >> month >> year;
    cout << "Enter Salary\n";
    cin >> salary;
    cout << "Enter date start work\n";
    cin >> dayStart >> monthStart >> yearStart;

    return Employee(Person(firstName, lastName, Date(day, month, year)), salary, Date(dayStart, monthStart, yearStart));
}

void addEmployeeAirport(AirportManager* pManager)
{
    char* code;
    cout << "Add employee to airport\n";
    Employee employee = initEmployee();

    cout << "Choose airport by code\n";
    displayAirports(pManager);
    cin >> code;

    GroundAttendant* groundAttendant = new GroundAttendant(employee, GroundCrew(code));
    pManager->addEmployeeToAirport(*groundAttendant, code);

}

Pilot* initPilot(Employee& employee, int airlineId)
{
    int rank;
    cout << "Choose pilots rank\n";
    cout << "0 - Captain\n1 - FIRST_OFFICER\n";
    cin >> rank;

    return new Pilot(employee, AirCrew(airlineId), static_cast<Pilot::ePilotRank>(rank));
}

FlightAttendant* initFlightAttendant(Employee& employee, int airlineId)
{
    int rank;
    cout << "Choose Flight Attendant's rank\n";
    cout << "0 - Purser\n1 - Steward\n";
    cin >> rank;

    return new FlightAttendant(employee, AirCrew(airlineId), static_cast<FlightAttendant::eFlightAttendantRank>(rank));
}

void addEmployeeAirline(AirportManager* pManager)
{
    int id;
    bool isPilot = false;
    int choice;
    Pilot* pilot;
    FlightAttendant* flightAttendant;
    cout << "Add employee to airline\n";
    Employee employee = initEmployee();

    cout << "Choose airline by id\n";
    displayAirports(pManager);
    cin >> id;

    cout << "0 - Flight Attendant\n1 - Pilot\n";
    cin >> choice;
    isPilot = (choice == 0) ? false : true;

    if (isPilot) {
        pilot = initPilot(employee, id);
        pManager->addPilotToAirline(*pilot, id);
    } else {
        flightAttendant = initFlightAttendant(employee, id);
        pManager->addFlightAttendantToAirline(*flightAttendant, id);
    }
}

void registerFlight(AirportManager* pManager)
{
    int flightNumber;
    char* src;
    char* dest;
    int day, month, year;
    char* airlineName;
    Airline* airline;

    cout << "Register Flight\n";
    cout << "Choose airline:\n";
    cout << pManager->getAirlines();
    cin >> airlineName;
    airline = pManager->findAirline(airlineName);
    if (airline != nullptr) {
        cout << "Enter flight number\n";
        cin >> flightNumber;
        cout << "Enter airport departure\n";
        cin >> src;
        cout << "Enter airport arrival\n";
        cin >> dest;
        cout << "Enter day of departure(day month year)\n";
        cin >> day >> month >> year;
        Flight* flight = new Flight(flightNumber, src, dest, Date(day, month, year));
        pManager->registerFlight(*airline, *flight);
    }
}


void addPassangerToFlight(AirportManager* pManager)
{
    char* firstName;
    char* lastName;
    int day, month, year;
    int flightNumber;
    double lWeight;
    cout << "Add passenger to flight\n";
    cout << "Enter First Name\n";
    cin >> firstName;
    cout << "Enter Last Name\n";
    cin >> lastName;
    cout << "Enter birthdate\n";
    cin >> day >> month >> year;
    cout << "Choose flight by number\n";
    displayFlights(pManager);
    cin >> flightNumber;

    Passenger* p = new Passenger(Person(firstName, lastName, Date(day, month, year)), flightNumber,
                                 Luggage(0, lWeight));
    pManager->addPassengerToFlight(*p, flightNumber);
}

void assembleCrew(AirportManager* pManager)
{
    int flightNumber;
    cout << "Choose flight to assign crew\n";
    displayFlights(pManager);
    cin >> flightNumber;

    pManager->assembleCrew(flightNumber);

}

void findFlights(AirportManager* pManager)
{
    char* src;
    char* dest;

    cout << "Find Flights between 2 airports\n";
    cout << "Enter Source Airport code (IATA)\n";
    cin >> src;
    cout << "Enter Destination Airport code (IATA)\n";
    cin >> dest;

    pManager->findFlights(src, dest);
}

void displayFlights(AirportManager* pManager)
{
    cout << "Display Flight Board\n";
    for (int i = 0; i < pManager->getNumOfAirports(); ++i) {
        cout << pManager->getAirports()[i]->getFlights();
    }
}

void displayAirports(AirportManager* pManager)
{
    cout << "Display Airports\n";
    cout << pManager->getAirports();
}

void displayAirlines(AirportManager* pManager)
{
    cout << "Display Airlines\n";
    cout << pManager->getAirlines();
}