//
// Created by Simon Bruno on 09/05/2022.
//

#pragma once

#include "person.h"
#include "date.h"

class Employee : virtual public Person
{
protected:
    int EmployeeId;
    double Salary;
    Date StartDate;
    bool IsAvailable;

public:
    Employee(const Person& base, double salary, Date startDate, bool isAvailable = false);

    Employee(Person&& base, int employeeId, double salary, Date startDate, bool isAvailable);

    Employee(const Employee& other);

    Employee(Employee&& other) noexcept;

    ~Employee();

    void SetSalary(double salary);

    void SetAvailability(bool availability);

    int GetEmployeeId();

    double GetSalary();

    Date GetStartDate();

    bool GetAvailability();

    Employee& operator=(const Employee& other);

    Employee& operator=(Employee&& other) noexcept;

    friend ostream& operator<<(ostream& os, const Employee& employee);

};
