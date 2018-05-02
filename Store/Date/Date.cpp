//
// Created by Taras Martynyuk on 4/30/2018.
//
#include <stdexcept>
#include <iostream>
#include "Date.h"
#include "month_utils.h"
using  namespace std;

const Date Date::kDefaultDate = Date(1970, 1, 1);

//region ctors

// skipping initializer list,
// because i need to validate data through property accessors
Date::Date(const int year, const int month, const int day)
{
    setValues(year, month, day);
}

// not reusing the other ctor,
// as i, again, want to validate using property accessors
Date::Date(const Date& other)
{
    setValues(other.year(), other.month(), other.day());
}

Date::Date() : Date(kDefaultDate) {}
//endregion

//region accessors

void Date::setYear(const int year)
{
    if(year < 1970)
        { throw invalid_argument("the year must be greater than 1970"); }

    year_ = year;
}

void Date::setMonth(const int m)
{
    if(m < 0 || m > 11)
        { throw invalid_argument("month must be in range (0, 11)"); }
    month_ = m;
}

// uses the current value of month!
void Date::setDay(const int d)
{
    // time structs use mdays starting with 1, not 0
    if(d < 1 || d > daysInMonth(month(), year()))
        { throw invalid_argument("day is more than month has"); }
    day_ = d;
}

int Date::year() const
    { return year_; }

int Date::month() const
    { return month_; }

int Date::day() const
    { return day_; }
//endregion



void Date::setValues(int year, int month, int day)
{
    setYear(year);
    setMonth(month);
    setDay(day);
}

time_t Date::timestamp() const
{
    tm tm_struct = createZeroedTimeStruct(year() - 1900, month(), day());
    // time struct stores years as diff from the 1900

     return mktime(&tm_struct);
}

tm Date::createZeroedTimeStruct(int year, int month, int day)
{
    tm tm_struct;
    tm_struct.tm_year = year;
    tm_struct.tm_mon = month;
    tm_struct.tm_mday = day;

    tm_struct.tm_gmtoff = 0;
    tm_struct.tm_zone = nullptr;

    tm_struct.tm_hour = 0;
    tm_struct.tm_min = 0;
    tm_struct.tm_sec = 0;

    tm_struct.tm_yday = 0;
    tm_struct.tm_wday = 0;
    tm_struct.tm_isdst = 0;

    return tm_struct;
}

Date Date::fromTimestamp(time_t timestamp)
{
    // why of why do they require pointers
    tm* tm_struct = localtime(&timestamp);

    return Date(
        tm_struct->tm_year + 1900,
        tm_struct->tm_mon,
        tm_struct->tm_mday
    );
}

bool dateInFuture(const Date&)
{
    // compare timestamps
    return false;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.year() << "-" << date.month() << "-" << date.day();
    return os;
}

bool operator<(const Date& left, const Date& right)
{
    return left.timestamp() < right.timestamp();
}

bool isInFuture(const Date& date)
{
    return time(nullptr) < date.timestamp();
}

bool isInPast(const Date& date)
{
    return time(nullptr) > date.timestamp();
}

bool operator>(const Date& left, const Date& right)
{
    return left.timestamp() > right.timestamp();
}

bool operator==(const Date& left, const Date& right)
{
    return left.timestamp() == right.timestamp();
}

const TimeDelta operator-(const Date&, const Date&)
{
    return TimeDelta();
}

