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

    std::string FirstName;
    std::string LastName;
    int Id;
    Date BirthDate;

public:
    virtual ~Person() = default;
    Person(const Person&) = default;
    Person& operator=(const Person&) = delete;
    Person& operator=(Person&&) = delete;
    Person(Person&&) = default;
    Person(std::string firstName, std::string lastName, Date birthDate);

    void SetFirstName(const std::string& firstName);

    void SetLastName(const std::string& lastName);

    void SetId(int id);

    void SetBirthDate(int day, int month, int year);

    const std::string& GetFirstName() const;

    const std::string& GetLastName() const;

    std::string GetFullName() const;

    int GetId() const;

    Date GetBirthDate() const;

    friend std::ostream& operator<<(std::ostream& os, const Person& person);
};
