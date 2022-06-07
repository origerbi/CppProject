//
// Created by Eddie Rudoy on 09/05/2022.
//

// ReSharper disable CppClangTidyModernizeAvoidCArrays
#pragma once

#include "date.h"
#include <iostream>

class Person
{
protected:
    static int Counter;

    char FirstName[50];
    char LastName[50];
    int Id;
    Date BirthDate;

public:
    Person(const char* firstName, const char* lastName, Date birthDate);

    Person(const Person& other) = default;

    Person(Person&& other) noexcept = default;

    virtual ~Person() = default;

    Person& operator=(const Person& other) = default;

    Person& operator=(Person&& other) noexcept = default;

    void SetFirstName(const char* firstName);

    void SetLastName(const char* lastName);

    void SetId(int id);

    void SetBirthDate(int day, int month, int year);

    const char* GetFirstName() const;

    const char* GetLastName() const;

    const char* GetFullName() const;

    int GetId() const;

    Date GetBirthDate() const;

    friend std::ostream& operator<<(std::ostream& os, const Person& person);

};
