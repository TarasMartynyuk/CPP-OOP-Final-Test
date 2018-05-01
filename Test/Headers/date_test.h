//
// Created by Taras Martynyuk on 5/1/2018.
//
#ifndef OOPFINALEXAM_DATE_TEST_H
#define OOPFINALEXAM_DATE_TEST_H

void run_all_date_tests();
// if we create the timestruct with same values,
// it's timestamp must be equal to our dates
void ProducesTimestamp_EqToThatOfTimeStruct();
// it would be waay to long to test all the cases
void LessOperator_ReturnsTrue_IfYearMonthDaySmaller();
void LessOperator_ReturnFalse_IfYearMonthDayBigger();

void Ctor_Throws_IfYearLess1970();
void Setter_Throws_IfYearLess1970();

void Ctor_Throws_IfDayIsMoreThanMonthHas();
void Setter_Throws_IfDayIsMoreThanMonthHas();

void Ctor_Throws_IfMonthMoreThanYearHas();
void Setter_Throws_IfMonthMoreThanYearHas();

#endif //OOPFINALEXAM_DATE_TEST_H
