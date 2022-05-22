//
// Created by Eddie Rudoy on 10/05/2022.
//

#pragma once
#include <iostream>

class Date
{
    static constexpr int DAY_MONTH[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int Day;
    int Month;
    int Year;

public:
    Date(int day, int month, int year);

    Date(const Date& other) = default;

    Date(Date&& other) noexcept = default;

    ~Date() = default;

    Date& operator=(const Date& other) = default;

    Date& operator=(Date&& other) noexcept = default;

    static const char* GetDate(const Date& date); // return string format of date (e.g dd/mm/yyyy)


    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};
