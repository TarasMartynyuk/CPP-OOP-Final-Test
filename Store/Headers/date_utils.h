//
// Created by Taras Martynyuk on 5/5/2018.
//
#ifndef OOPFINALEXAM_DATE_UTILS_H
#define OOPFINALEXAM_DATE_UTILS_H
#include "date.h"
#include "tz.h"

const date::time_zone* const k2ndZone =
    date::locate_zone("Europe/Tallinn");

static const date::year_month_day kDefaultDate =
    date::year_month_day(
        date::year(1970),
        date::month(1),
        date::day(1));

bool isInPast(const date::year_month_day&);
bool isInFuture(const date::year_month_day&);

date::days daysLeft(const date::year_month_day& ymd);

date::year_month_day addDays(
    const date::year_month_day& ymd,
    date::days days
    );

date::year_month_day today();

#endif //OOPFINALEXAM_DATE_UTILS_H
