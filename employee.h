//
// Created by Simon Bruno on 09/05/2022.
//

#ifndef AIRPORTPROJECTCPP_EMPLOYEE_H
#define AIRPORTPROJECTCPP_EMPLOYEE_H

#include "person.h"
#include "date.h"

class Employee : virtual public Person
{
protected:
    int employeeId;
    double salary;
    Date startDate;
    bool isAvailable;

public:
    Employee(const Person& base, double salary, Date startDate, bool isAvailable = false);

    Employee(Person&& base, int employeeId, double salary, Date startDate, bool isAvailable);

    Employee(const Employee& other);

    Employee(Employee&& other);

    ~Employee();

    void setSalary(double salary);

    void setAvailability(bool availability);

    int getEmployeeId();

    double getSalary();

    Date getStartDate();

    bool getAvailability();

    const Employee& operator=(const Employee& other);

    const Employee& operator=(Employee&& other);

    friend ostream& operator<<(ostream& os, const Employee& employee);

};

#endif //AIRPORTPROJECTCPP_EMPLOYEE_H
