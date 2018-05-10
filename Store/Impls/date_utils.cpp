//
// Created by Taras Martynyuk on 5/5/2018.
//
#include "date_utils.h"
#include "date.h"
#include <chrono>
using namespace date;
using namespace std::chrono;

local_days local_days_till_today()
{
    return floor<days>(
        make_zoned(k2ndZone, system_clock::now())
            .get_local_time());
}

year_month_day today()
{
    return year_month_day(local_days_till_today());
}

bool isInPast(
    const date::year_month_day& ymd)
    { return ymd < today(); }

bool isInFuture(
    const date::year_month_day& ymd)
    { return ymd > today(); }

date::year_month_day addDays(const date::year_month_day& ymd,
    date::days days)
{
    auto start_loc_days = static_cast<local_days> (ymd);

    return year_month_day(start_loc_days + days);
}

days daysLeft(const date::year_month_day& ymd)
{
    return static_cast<local_days>(ymd) -
        local_days_till_today();
}

