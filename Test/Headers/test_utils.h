//
// Created by Taras Martynyuk on 4/2/2018.
//
#ifndef ARRAY_TEST_UTILS_H
#define ARRAY_TEST_UTILS_H
#include <string>
#include "date.h"
using namespace date;

constexpr date::year_month_day kInPast  = 2018_y/March/30;
constexpr date::year_month_day kInPastLater  = 2018_y/March/11;

constexpr date::year_month_day  kInFutureSooner = 2019_y/April/30;
constexpr date::year_month_day  kInFutureLater = 2019_y/May/4;

template <typename TException>
bool expressionThrows( std::function<void()> expression)
{
    try
    {
        expression();
        return false;
    }
    catch(TException& e)
    {
        return true;
    }
}

void logPassed(std::string testName);
void logAllPassed();



#endif //ARRAY_TEST_UTILS_H
