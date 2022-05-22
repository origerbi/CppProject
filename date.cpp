// ReSharper disable CppClangTidyBugproneNarrowingConversions
#include "date.h"

Date::Date(const int day, const int month, const int year) : Day(day), Month(month), Year(year)
{
}

const char* Date::GetDate(const Date& date)
{
    const auto dateString = new char[11];
    dateString[0] = date.Day / 10 + '0';
    dateString[1] = date.Day % 10 + '0';
    dateString[2] = '/';
    dateString[3] = date.Month / 10 + '0';
    dateString[4] = date.Month % 10 + '0';
    dateString[5] = '/';
    dateString[6] = date.Year / 1000 + '0';
    dateString[7] = date.Year / 100 % 10 + '0';
    dateString[8] = date.Year / 10 % 10 + '0';
    dateString[9] = date.Year % 10 + '0';
    dateString[10] = '\0';
    return dateString;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << Date::GetDate(date);
    return os;
}
