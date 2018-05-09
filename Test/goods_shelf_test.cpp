//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <cassert>
#include <stdexcept>
#include <Store/Headers/StoreExceptions.h>
#include <numeric>
#include "Store.h"
#include "GoodsShelf.h"
#include "goods_shelf_test.h"
#include "test_utils.h"
#include "date.h"
#include "date_utils.h"
using namespace std;
using namespace date;
using amount_t_sh = GoodsShelf::amount_t;

GoodsShelf testGoodsShelf();

void run_all_supplies_tests()
{
    AddSupply_ChangesTotalAmount();
    AddSupply_Throws_IfAddingExpired();

    NextExpDate_IsLessThanNextDateAfterThisOne();
    NextExpDate_ReturnsTheLeastDate_OfTheAddedSupplies();

    RemoveSupplyExpNext_ChangesAmount();

    RemoveNGoods_ThrowsLack_IfNotEnoughItems();
    RemoveNGoods_ChangesTotalAmount();
    RemoveNGoods_DoesNotChangeNextExpDate_IfNextExpSupply_HasEnoughGoods();
    RemoveNGoods_ReturnsSupplies_WithTotalSumEqToRequested();
}

//region addSupply

void AddSupply_ChangesTotalAmount()
{
    auto supplies = testGoodsShelf();

    amount_t_sh old_total = supplies.totalAmount();

    supplies.addSupply(Supply(20, kInFutureSooner));

    assert(supplies.totalAmount() == old_total + 20);
    logPassed(__FUNCTION__);
}

void AddSupply_Throws_IfAddingExpired()
{
    assert(expressionThrows<invalid_argument>([]() -> void
    {
        auto supplies = testGoodsShelf();
        supplies.addSupply(Supply(20, kInPast));
    }));
    logPassed(__FUNCTION__);
}
//endregion

//region Queue

void NextExpDate_IsLessThanNextDateAfterThisOne()
{
    GoodsShelf gs = testGoodsShelf();

    gs.addSupply(Supply(5, kInFutureLater));
    gs.addSupply(Supply(5, kInFutureSooner));

    year_month_day front = gs.nextExpirationDate();
    gs.removeSupplyExpiringSoonest();

    year_month_day second_front = gs.nextExpirationDate();
    assert(front < second_front);
    logPassed(__FUNCTION__);
}

void NextExpDate_ReturnsTheLeastDate_OfTheAddedSupplies()
{
    GoodsShelf gs = testGoodsShelf();

    gs.addSupply(Supply(5, kInFutureLater));
    gs.addSupply(Supply(5, kInFutureSooner));

    gs.addSupply(Supply(
        5, kInFutureLater + months(1)));

    assert(gs.nextExpirationDate() == kInFutureSooner);
    logPassed(__FUNCTION__);
}

void RemoveSupplyExpNext_ChangesAmount()
{
    GoodsShelf gs = testGoodsShelf();

    gs.addSupply(Supply(5, kInFutureLater));
    gs.addSupply(Supply(5, kInFutureSooner));

    Supply::amount_t old_amount = gs.totalAmount();

    gs.removeSupplyExpiringSoonest();

    assert(old_amount == gs.totalAmount() + 5);
    logPassed(__FUNCTION__);
}

void RemoveNGoods_ThrowsLack_IfNotEnoughItems()
{
    expressionThrows<Lack>([]()
    {
        GoodsShelf gs = testGoodsShelf();

        gs.addSupply(Supply(5, kInFutureLater));

        gs.removeNGoodsExpiringSoonest(10);
    });
    logPassed(__FUNCTION__);
}

void RemoveNGoods_ChangesTotalAmount()
{
    GoodsShelf gs = testGoodsShelf();

    gs.addSupply(Supply(10, kInFutureLater));
    Supply::amount_t old_amount = gs.totalAmount();

    gs.removeNGoodsExpiringSoonest(10);

    assert(old_amount == gs.totalAmount() + 10);
    logPassed(__FUNCTION__);
}

void RemoveNGoods_DoesNotChangeNextExpDate_IfNextExpSupply_HasEnoughGoods()
{
    GoodsShelf gs = testGoodsShelf();

    gs.addSupply(Supply(10, kInFutureLater));
    gs.addSupply(Supply(10, kInFutureSooner));

    year_month_day old_next = gs.nextExpirationDate();

    gs.removeNGoodsExpiringSoonest(5);

    year_month_day new_next = gs.nextExpirationDate();
    assert(old_next == new_next);
    logPassed(__FUNCTION__);
}

void RemoveNGoods_ReturnsSupplies_WithTotalSumEqToRequested()
{
    auto gs = testGoodsShelf();

    gs.addSupply(Supply(3, kInFutureLater));
    gs.addSupply(Supply(6, kInFutureSooner));
    gs.addSupply(Supply(14, kInFutureSooner));

    amount_t_sh requested = 10;
    std::vector<Supply> removed = gs.removeNGoodsExpiringSoonest(requested);

//    auto accumulator = [](int sum, const Supply& right) -> amount_t_sh {
//        return sum + right.amount();
//    };
//    GoodsShelf::amount_t sum = accumulate(
//        removed.begin(), removed.end(),
//        amount_t_sh(), accumulator);

    Supply::amount_t sum = amountSum(removed);
    assert(sum == requested);
}

//endregion

GoodsShelf testGoodsShelf()
{
    const amount_t_sh kMinAmount = 10;
    Goods g(0, "test_goods", 0, 50);
    return GoodsShelf(g, kMinAmount);
}
