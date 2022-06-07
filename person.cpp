// ReSharper disable once CppInconsistentNaming
#define _CRT_SECURE_NO_WARNINGS
#include "person.h"

Person::Person(const char* firstName, const char* lastName, const Date birthDate) : FirstName(), LastName(),
    Id(Counter++), BirthDate(birthDate)
{
    strcpy_s(FirstName, firstName);
    strcpy_s(LastName, lastName);
}

void Person::SetFirstName(const char* firstName)
{
    strcpy_s(FirstName, firstName);
}

void Person::SetLastName(const char* lastName)
{
    strcpy_s(LastName, lastName);
}

void Person::SetId(const int id)
{
    Id = id;
}

void Person::SetBirthDate(const int day, const int month, const int year)
{
    BirthDate = Date(day, month, year);
}

const char* Person::GetFirstName() const
{
    return FirstName;
}

const char* Person::GetLastName() const
{
    return LastName;
}

const char* Person::GetFullName() const
{
    auto* const fullName = new char[strlen(FirstName) + strlen(LastName) + 2];
    strcpy(fullName, FirstName);
    strcat(fullName, " ");
    strcpy(&fullName[strlen(FirstName) + 1], LastName);
    return fullName;
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
    const char* fullName = person.GetFullName();
    os << "Name: " << fullName << std::endl;
    os << "Id: " << person.GetId() << std::endl;
    os << "Birth date: " << person.GetBirthDate() << std::endl;
    delete[] fullName;
    return os;
}

int Person::Counter = 0;
