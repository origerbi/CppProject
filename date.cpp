// ReSharper disable CppClangTidyBugproneNarrowingConversions
#include "date.h"

Date::Date(const int day, const int month, const int year) : Day(day), Month(month), Year(year)
{
}

const std::string Date::GetDate(const Date& date)
{
    std::string dateString;
    dateString  += date.Day / 10 + '0';
    dateString  += date.Day % 10 + '0';
    dateString  += '/';
    dateString  += date.Month / 10 + '0';
    dateString  += date.Month % 10 + '0';
    dateString  += '/';
    dateString  += date.Year / 1000 + '0';
    dateString  += date.Year / 100 % 10 + '0';
    dateString  += date.Year / 10 % 10 + '0';
    dateString  += date.Year % 10 + '0';
    return dateString;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << Date::GetDate(date);
    return os;
}
