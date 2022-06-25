// ReSharper disable once CppInconsistentNaming
#define _CRT_SECURE_NO_WARNINGS
#include "person.h"

Person::Person(std::string firstName, std::string lastName, const Date birthDate) : FirstName(std::move(firstName)), LastName(
        std::move(lastName)),
    Id(Counter++), BirthDate(birthDate)
{
}

void Person::SetFirstName(const std::string& firstName)
{
    FirstName = firstName;
}

void Person::SetLastName(const std::string& lastName)
{
    LastName = lastName;
}

void Person::SetId(int id)
{
    Id = id;
}

void Person::SetBirthDate(int day, int month, int year)
{
    BirthDate = Date(day, month, year);
}

const std::string& Person::GetFirstName() const
{
    return FirstName;
}

const std::string& Person::GetLastName() const
{
    return LastName;
}

std::string Person::GetFullName() const
{
    return FirstName + " " + LastName;
}

int Person::GetId() const
{
    return Id;
}

Date Person::GetBirthDate() const
{
    return BirthDate;
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
    os << "Name: " << person.GetFullName() << std::endl;
    os << "Id: " << person.GetId() << std::endl;
    os << "Birth date: " << person.GetBirthDate() << std::endl;
    return os;
}

int Person::Counter = 0;
