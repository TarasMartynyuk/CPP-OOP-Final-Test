//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <cassert>
#include "GoodsSupplies.h"
#include "goods_supplies_test.h"

const Date kInPast(2018, 4, 30);
const Date kInFuture(2019, 4, 30);
const size_t kMinAmount = 10;

GoodsSupplies testInstance();

void run_all_supplies_tests()
{
    AddSupply_ChangesTotalAmount();
}

void AddSupply_ChangesTotalAmount()
{
    auto supplies = testInstance();

    size_t old_total = supplies.totalAmount();

    supplies.addSupply(kInFuture, 20);

    assert(supplies.totalAmount() == 20);
}



GoodsSupplies testInstance()
{
    Goods g(0, "test_goods");
    return GoodsSupplies(g, kMinAmount);
}
