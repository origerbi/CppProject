#include "employee.h"

Employee::Employee(const Person& base, const double salary, const Date startDate, const bool isAvailable) : Person(base), EmployeeId(),
    Salary(salary), StartDate(startDate), IsAvailable(isAvailable)
{
}

Employee::Employee(Person&& base, int employeeId, double salary, const Date startDate, bool isAvailable) : Person(base), EmployeeId(employeeId),
    Salary(salary), StartDate(startDate), IsAvailable(isAvailable)
{
}

void Employee::SetSalary(double salary)
{
    Salary = salary;
}

void Employee::SetAvailability(bool availability)
{
    IsAvailable = availability;
}

int Employee::GetEmployeeId() const
{
    return EmployeeId;
}

double Employee::GetSalary() const
{
    return Salary;
}

Date Employee::GetStartDate() const
{
    return StartDate;
}

bool Employee::GetAvailability() const
{
    return IsAvailable;
}

std::ostream& operator<<(std::ostream& os, const Employee& employee)
{
    os << static_cast<const Person&>(employee) << "Employee Id: " << employee.GetEmployeeId() << std::endl;
    os << "Salary: " << employee.GetSalary() << std::endl;
    os << "Start date: " << employee.GetStartDate() << std::endl;
    os << "Is available: " << employee.GetAvailability() << std::endl;
    return os;
}
