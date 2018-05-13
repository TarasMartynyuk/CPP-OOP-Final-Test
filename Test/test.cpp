//
// Created by Taras Martynyuk on 5/1/2018.
//
#include "test_utils.h"
#include "test.h"
#include "goods_shelf_test.h"
#include "include_exclude_test.h"
#include "purchasing_test.h"
#include <iostream>

void run_all_tests()
{
    run_all_supplies_tests();
    std::cout << "\n";
    test_store();
    std::cout << "\n";
    run_all_purch_tests();
    std::cout << "\n";

    logAllPassed();
}