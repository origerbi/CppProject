//
// Created by Eddie Rudoy on 09/05/2022.
//

#pragma once

#include <iostream>
#include "date.h"

class Person
{
protected:
    static int Counter;

    char* FirstName;
    char* LastName;
    int Id;
    Date BirthDate;

public:
    Person(char* firstName, char* lastName, Date birthDate);

    Person(const Person& other) = default;

    Person(Person&& other) noexcept = default;

    ~Person() = default;

    Person& operator=(const Person& other) = default;

    Person& operator=(Person&& other) noexcept = default;

    void SetFirstName(char* firstName);

    void SetLastName(char* lastName);

    void SetId(int id);

    void SetBirthDate(int day, int month, int year);

    const char* GetFirstName() const;

    const char* GetLastName() const;

    const char* GetFullName() const;

    int GetId() const;

    Date GetBirthDate() const;

    friend std::ostream& operator<<(std::ostream& os, const Person& person);

};
