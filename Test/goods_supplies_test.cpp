//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <cassert>
#include <stdexcept>
#include "GoodsSupplies.h"
#include "goods_supplies_test.h"
#include "test_utils.h"
using namespace std;

const Date kInPast(2018, 3, 30);
const Date kInFuture(2019, 4, 30);
const size_t kMinAmount = 10;

GoodsSupplies testInstance();

void run_all_supplies_tests()
{
    AddSupply_ChangesTotalAmount();
    AddSupply_Throws_IfAddingExpired();
    AddSupply_Throws_IfAddingManufacturedInFuture();
}

void AddSupply_ChangesTotalAmount()
{
    auto supplies = testInstance();

    size_t old_total = supplies.totalAmount();

    supplies.addSupply(20, kInPast, kInFuture);

    assert(supplies.totalAmount() == old_total + 20);
    logPassed(__FUNCTION__);
}

void AddSupply_Throws_IfAddingExpired()
{
    assert(expressionThrows<invalid_argument>([]() -> void
    {
        auto supplies = testInstance();
        supplies.addSupply(2, kInPast, kInPast);
    }));
    logPassed(__FUNCTION__);
}

void AddSupply_Throws_IfAddingManufacturedInFuture()
{
    assert(expressionThrows<invalid_argument>([]() -> void
    {
        auto supplies = testInstance();
        supplies.addSupply(2, kInFuture, kInFuture);
    }));
    logPassed(__FUNCTION__);
}


GoodsSupplies testInstance()
{
    Goods g(0, "test_goods", 0);
    return GoodsSupplies(g, kMinAmount);
}
