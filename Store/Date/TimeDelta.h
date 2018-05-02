//
// Created by Taras Martynyuk on 5/2/2018.
//
#ifndef OOPFINALEXAM_TIMEDELTA_H
#define OOPFINALEXAM_TIMEDELTA_H

#include <ctime>

// yes, i know that converting timestamp like that would
// throw away a lot of data, like leap years
// and last days of months
// i jus can't implement the - and + operators for dates
// it is barely possible!
// tons of procedural code!
class TimeDelta
{
public:
    TimeDelta(int y, int m, int d);
    TimeDelta();
    // interpets timestamp as a period from epoch start to
    // the date timestamp represents
    static TimeDelta fromTimestamp(time_t);

    time_t timestamp() const;
    const int year;
    const int month;
    const int day;
private:
    explicit TimeDelta(const tm&);
};


#endif //OOPFINALEXAM_TIMEDELTA_H
