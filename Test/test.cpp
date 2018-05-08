//
// Created by Taras Martynyuk on 5/1/2018.
//
#include "test_utils.h"
#include "test.h"
#include "goods_shelf_test.h"
#include "store_test.h"
#include <iostream>

void run_all_tests()
{
    run_all_supplies_tests();
    std::cout << "\n";
    test_store();
    std::cout << "\n";

    logAllPassed();
}


//#include "date_utils.h"
//#include "date.h"
//using namespace date;
//void ToLocDays_ConvertedToFrom_EqOriginal()
//{
//    year_month_day orig = kInPast;
//
//    auto loc_days = toLocalDays(orig);
//
//    year_month_day there_and_back_again(loc_days);
//
//    assert(there_and_back_again == orig);
//}
