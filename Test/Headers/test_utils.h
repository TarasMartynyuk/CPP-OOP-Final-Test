//
// Created by Taras Martynyuk on 4/2/2018.
//
#ifndef ARRAY_TEST_UTILS_H
#define ARRAY_TEST_UTILS_H
#include <string>

const Date kInPast(2018, 3, 30);
const Date kInFutureSooner(2019, 4, 30);
const Date kInFutureLater(2019, 5, 4);

template <typename TException>
bool expressionThrows( void (*const expression)())
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
