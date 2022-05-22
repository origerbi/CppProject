//
// Created by Eddie Rudoy on 10/05/2022.
//

#ifndef AIRPORTPROJECT_DATE_H
#define AIRPORTPROJECT_DATE_H

#include <iostream>

using namespace std;

class Date
{
private:
    static constexpr int DAY_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year);

    Date(const Date& other);

    Date(Date&& other);

    ~Date();

    const Date& operator=(const Date& other);

    const Date& operator=(Date&& other);

    const char* getDate(const Date& date); // return string format of date (e.g dd/mm/yyyy)


    friend ostream& operator<<(ostream& os, const Date& date);
};


#endif //AIRPORTPROJECT_DATE_H
