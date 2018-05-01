//
// Created by Taras Martynyuk on 4/30/2018.
//
#include <stdexcept>
#include "Date.h"
using  namespace std;

const Date Date::kDefaultDate = Date(1970, 1, 1);

//region ctors

Date::Date(const int year, const int month, const int day)
    : tm_struct()
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

Date::Date(const Date& other)
{
    this->tm_struct = other.tm_struct;
}

Date::Date() : Date(kDefaultDate) {}
//endregion

//region accessors

void Date::setYear(const int year)
{
    if(year < 1970)
        { throw invalid_argument("the year must be greater than 1970"); }

    // time struct stores years diff from the 1900
    tm_struct.tm_year = year - 1900;
}

void Date::setMonth(const int m)
    { tm_struct.tm_mon = m; }

void Date::setDay(const int d)
    { tm_struct.tm_mday = d; }
//endregion





bool dateInFuture(const Date&)
{
    // compare timestamps
    return false;
}

