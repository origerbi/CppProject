#include "employee.h"

Employee::Employee(const Person& base, double salary, Date startDate, bool isAvailable) : Person(base), Salary(salary), StartDate(startDate), IsAvailable(isAvailable), EmployeeId()
{
}
