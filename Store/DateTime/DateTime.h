//
// Created by Taras Martynyuk on 4/30/2018.
//
#ifndef OOPFINALEXAM_DATETIME_H
#define OOPFINALEXAM_DATETIME_H
#include <ctime>
#include <string>

// a point in time after POSIX era,
// represented by date and time
class DateTime
{
public:
    DateTime(size_t year, size_t month, size_t day);
    DateTime(const std::string& dateString);
    DateTime(const tm&);

    size_t year();
    size_t month();
    size_t day();
    time_t timestamp();

private:
    // handling day in month overflows, when calculating
    // deltatimes is too much for me
    // let's just use the ctime struct
    //
    tm tm_struct;
};


#endif //OOPFINALEXAM_DATETIME_H
