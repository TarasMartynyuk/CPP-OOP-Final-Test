//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <Test/Headers/test_utils.h>
#include "test.h"
#include "goods_supplies_test.h"
#include "date_test.h"
#include <iostream>

void run_all_tests()
{
//    run_all_date_tests();
//    std::cout << "\n";
    run_all_supplies_tests();
    std::cout << "\n";

    logAllPassed();
}
