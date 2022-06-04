// ReSharper disable once CppInconsistentNaming
#define _CRT_SECURE_NO_WARNINGS
#include "person.h"

Person::Person(char* firstName, char* lastName, const Date birthDate) : FirstName(firstName), LastName(lastName),
                                                                        Id(Counter++), BirthDate(birthDate)
{
}

Person::~Person()
{
    delete[] FirstName;
    delete[] LastName;
}

void Person::SetFirstName(char* firstName)
{
    FirstName = firstName;
}

void Person::SetLastName(char* lastName)
{
    LastName = lastName;
}

void Person::SetId(const int id)
{
    Id = id;
}

void Person::SetBirthDate(const int day, const int month, const int year)
{
    BirthDate = Date(day, month, year);
}

char* Person::GetFirstName() const
{
    return FirstName;
}

char* Person::GetLastName() const
{
    return LastName;
}

const char* Person::GetFullName() const
{
    auto* const fullName = new char[strlen(FirstName) + strlen(LastName) + 1];
    strcpy(fullName, FirstName);
    strcpy(&fullName[strlen(FirstName)], LastName);
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
