//
// Created by Taras Martynyuk on 5/2/2018.
//
#include "TimeDelta.h"
#include "Date.h"

TimeDelta::TimeDelta(const tm& tm_s)
    : year(tm_s.tm_year - 1970),
      month(tm_s.tm_mon), day(tm_s.tm_mday) {}

TimeDelta TimeDelta::fromTimestamp(time_t timestamp)
{
    tm* tm_s = localtime(&timestamp);
    return TimeDelta(*tm_s);
}

//time_t TimeDelta::timestamp() const
//{
//    tm tm_s = Date::createZeroedTimeStruct(year + 70 , month, day);
//    return mktime(&tm_s);
//}

TimeDelta::TimeDelta(int y, int m, int d)
    : year(y), month(m), day(d) {}

TimeDelta::TimeDelta()
    : TimeDelta(1, 0, 0) // stub
{}
