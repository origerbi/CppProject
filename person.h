//
// Created by Eddie Rudoy on 09/05/2022.
//

#ifndef AIRPORTPROJECT_PERSON_H
#define AIRPORTPROJECT_PERSON_H

#include <iostream>
#include "date.h"

using namespace std;

class Person
{
protected:
    static int counter;

    char* firstName;
    char* lastName;
    int id;
    Date birthDate;

public:
    Person(const char* firstName, const char* lastName, Date birthDate);

    Person(const Person& other);

    Person(Person&& other);

    ~Person();

    const Person& operator=(const Person& other);

    const Person& operator=(Person&& other);

    void setFirstName(const char* firstName);

    void setLastName(const char* lastName);

    void setId(int id);

    void setBirthDate(int day, int month, int year);

    const char* getFirstName();

    const char* getLastName();

    const char* getFullName();

    int getId();

    Date getBirthDate();

    friend ostream& operator<<(ostream& os, const Person& person);

};


#endif //AIRPORTPROJECT_PERSON_H
