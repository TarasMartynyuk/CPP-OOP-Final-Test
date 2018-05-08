//
// Created by Taras Martynyuk on 5/5/2018.
//
#include "date_utils.h"
#include "date.h"
#include <chrono>
using namespace date;
using namespace std::chrono;

year_month_day today()
{
    return year_month_day(
        floor<days>(
        make_zoned(k2ndZone, system_clock::now())
            .get_local_time())
    );
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
//
//date::local_days toLocalDays(const date::year_month_day& ymd)
//{
//    return
//}

