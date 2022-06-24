//
// Created by Simon Bruno on 09/05/2022.
//

#pragma once

#include "date.h"
#include "person.h"

class Employee : virtual public Person
{
protected:
    int EmployeeId;
    double Salary;
    Date StartDate;
    bool IsAvailable;

public:
    Employee(const Person& base, double salary, Date startDate, bool isAvailable = true);

    Employee(Person&& base, int employeeId, double salary, Date startDate, bool isAvailable);

    Employee(const Employee& other);

    void SetSalary(double salary);

    void SetAvailability(bool availability);

    int GetEmployeeId() const;

    double GetSalary() const;

    Date GetStartDate() const;

    bool GetAvailability() const;

    friend std::ostream& operator<<(std::ostream& os, const Employee& employee);

};
