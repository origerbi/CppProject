// ReSharper disable CppClangTidyBugproneNarrowingConversions
#include "date.h"

#include <string>

Date::Date(int day, int month, int year) : Day(day), Month(month), Year(year)
{
}

std::string Date::GetDate(const Date& date)
{
    std::string dateString;
    dateString += std::to_string(date.Day);
    dateString += '/';
    dateString += std::to_string(date.Month);
    dateString += '/';
    dateString += std::to_string(date.Year);
    return dateString;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << Date::GetDate(date);
    return os;
}
