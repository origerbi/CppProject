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
    Employee(const Person& base, double salary, Date startDate, bool isAvailable = false);

    Employee(Person&& base, int employeeId, double salary, Date startDate, bool isAvailable);

    Employee(const Employee& other);

    Employee(Employee&& other) noexcept = default;

    ~Employee() = default;

    void SetSalary(double salary);

    void SetAvailability(bool availability);

    int GetEmployeeId() const;

    double GetSalary() const;

    Date GetStartDate() const;

    bool GetAvailability() const;

    Employee& operator=(const Employee& other) = default;

    Employee& operator=(Employee&& other) noexcept = default;

    friend std::ostream& operator<<(std::ostream& os, const Employee& employee);

};
