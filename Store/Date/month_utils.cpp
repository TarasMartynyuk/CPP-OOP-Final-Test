//
// Created by Taras Martynyuk on 3/9/18.
//
#include <cassert>
#include <stdexcept>
#include "month_utils.h"
using namespace std;

//region defs

bool leapYear(int year);

const string kMonthNames[] =
    {
            "January", "February", "March", "April",
            "May", "June", "July", "August",
            "September", "October", "November", "December"
    };
//endregion

string monthToName(int month)
{
    return kMonthNames[month];
}

unsigned daysInMonth(int month, int year)
{
    if(month == 1)
        { return leapYear(year) ? 29 : 28; }
    if(month < 8)
        { return month % 2 == 0 ? 31 : 30; }
    if (month <= 11)
        { return month % 2 == 0 ? 30 : 31; }
    else
        { throw std::invalid_argument(
            "month must be in range (0, 11)"); }
}

bool leapYear(int year)
{
    if(year % 4 != 0)
    {
        return false;
    }
    if(year % 100 != 0)
    {
        return true;
    }
    else
    {
        return year % 400 == 0;
    }
}