//
// Created by Taras Martynyuk on 4/30/2018.
//
#ifndef OOPFINALEXAM_DATETIME_H
#define OOPFINALEXAM_DATETIME_H
#include <ctime>
#include <string>

// a point in time after POSIX era,
// represented by date and time

// handling day in month overflows, when calculating
// deltatimes is too much for me
// let's just use the ctime struct and do operations on timestamps
class Date
{
public:
    static const Date kDefaultDate;

    Date(int year, int month, int day);
//    Date(const tm&);
    Date(const Date&);
    Date();
    static Date fromTimestamp(time_t timestamp);

    int year() const;
    int month() const;
    int day() const;
    time_t timestamp() const;

    // int, because that's what's stored in time struct
    // year, must be after the 1970 - posix era start
    void setYear(int);
    // month since january (0-11)
    void setMonth(int);
    // day of month (1- 31)
    void setDay(int);

private:
    int year_;
    int month_;
    int day_;

    // helps with the problem of using year in months setter and so on
    void setValues(int year, int month, int day);
    // all fields ae zero except those that are in args
    static tm createZeroedTimeStruct(int year, int month, int day);
};

std::ostream& operator<<(std::ostream& os, const Date & date);
bool operator==(const Date&, const Date&);
bool operator<(const Date&, const Date&);
bool operator>(const Date&, const Date&);

bool isInFuture(const Date&);
bool isInPast(const Date& date);
#endif //OOPFINALEXAM_DATETIME_H
