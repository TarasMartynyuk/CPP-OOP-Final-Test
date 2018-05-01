//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <ctime>
#include "Date.h"
#include <cassert>
#include <stdexcept>
#include "date_test.h"
#include "test_utils.h"

void run_all_date_tests()
{
    Ctor_Throws_IfYearLess1970();
    Setter_Throws_IfYearLess1970();

    Ctor_Throws_IfDayIsMoreThanMonthHas();
    Setter_Throws_IfDayIsMoreThanMonthHas();

    Ctor_Throws_IfMonthMoreThanYearHas();
    Setter_Throws_IfMonthMoreThanYearHas();

    ProducesTimestamp_EqToThatOfTimeStruct();
    LessOperator_ReturnsTrue_IfYearMonthDaySmaller();
    LessOperator_ReturnFalse_IfYearMonthDayBigger();
}

//region data validation

void Ctor_Throws_IfYearLess1970()
{
    assert(expressionThrows<std::invalid_argument>([]() -> void
    {
        Date date(1560, 0, 0);
    }));
    logPassed(__FUNCTION__);
}

void Setter_Throws_IfYearLess1970()
{
    assert(expressionThrows<std::invalid_argument>([]() -> void
    {
        Date date;
        date.setYear(1492);
    }));
    logPassed(__FUNCTION__);
}

void Ctor_Throws_IfDayIsMoreThanMonthHas()
{
    assert(expressionThrows<std::invalid_argument>([]() -> void
    {
       Date date(2000, 4, 32);
    }));
    assert(expressionThrows<std::invalid_argument>([]() -> void
    {
        Date date(2000, 3, 31);
    }));
    logPassed(__FUNCTION__);
}

void Setter_Throws_IfDayIsMoreThanMonthHas()
{
    assert(expressionThrows<std::invalid_argument>([]() -> void
    {
       Date date(2000, 4, 0);
       date.setDay(32);
    }));
    assert(expressionThrows<std::invalid_argument>([]() -> void
    {
        Date date(2000, 3, 0);
        date.setDay(31);
    }));
    logPassed(__FUNCTION__);
}

void Ctor_Throws_IfMonthMoreThanYearHas()
{
    assert(expressionThrows<std::invalid_argument>([]() -> void
    {
        Date date(2000, 12, 0);
    }));
    logPassed(__FUNCTION__);
}

void Setter_Throws_IfMonthMoreThanYearHas()
{
    assert(expressionThrows<std::invalid_argument>([]() -> void
    {
        Date date;
        date.setMonth(12);
    }));
    logPassed(__FUNCTION__);
}
//endregion


void ProducesTimestamp_EqToThatOfTimeStruct()
{
    tm tm_struct;

    tm_struct.tm_year = 1985 - 1900;
    tm_struct.tm_mon = 4;
    tm_struct.tm_mday = 18;

    Date date(1985, 4, 18);

    time_t dtmstmp = date.timestamp();
    time_t struct_stamp = mktime(&tm_struct);
        assert(dtmstmp == struct_stamp);
    logPassed(__FUNCTION__);
}

void LessOperator_ReturnsTrue_IfYearMonthDaySmaller()
{
    Date smaller(2000, 2, 2);
    Date bigger(2001, 3, 3);

    assert(smaller < bigger);
}

void LessOperator_ReturnFalse_IfYearMonthDayBigger()
{
    Date smaller(2001, 3, 3);
    Date bigger(2000, 2, 2);

    assert(!(smaller < bigger));
}



