//
// Created by Taras Martynyuk on 4/30/2018.
//
#ifndef OOPFINALEXAM_DATETIME_H
#define OOPFINALEXAM_DATETIME_H
#include <ctime>
#include <string>

// a point in time after POSIX era,
// represented by date and time
class Date
{
public:
    static const Date kDefaultDate;

    Date(int year, int month, int day);
    Date(const tm&);
    Date(const Date&);
    Date();

    size_t year() const;
    size_t month() const;
    size_t day() const;
    time_t timestamp() const;

    // int, because that's what's stored in time struct
    // year, must be after the 1970 - posix era start
    void setYear(int);
    // month since january (0-11)
    void setMonth(int);
    // day of month (1- 31)
    void setDay(int);

private:
    // handling day in month overflows, when calculating
    // deltatimes is too much for me
    // let's just use the ctime struct
    tm tm_struct;
};

bool dateInFuture(const Date&);
#endif //OOPFINALEXAM_DATETIME_H
