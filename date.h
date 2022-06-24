//
// Created by Eddie Rudoy on 10/05/2022.
//

#pragma once
#include <array>
#include <iostream>

class Date
{
    static constexpr std::array<int,12> DAY_MONTH = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int Day;
    int Month;
    int Year;

public:
    Date(int day, int month, int year);

    static const std::string GetDate(const Date& date); // return string format of date (e.g dd/mm/yyyy)


    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};
