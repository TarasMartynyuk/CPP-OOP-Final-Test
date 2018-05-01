//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <cassert>
#include <stdexcept>
#include "Store.h"
#include "GoodsSupplies.h"
#include "goods_supplies_test.h"
#include "test_utils.h"
using namespace std;

const size_t kMinAmount = 10;

GoodsSupplies testInstance();

void run_all_supplies_tests()
{
    AddSupply_ChangesTotalAmount();
    AddSupply_Throws_IfAddingExpired();
    AddSupply_Throws_IfAddingManufacturedInFuture();

    NextExpDate_IsLessThanNextDateAfterThisOne();
    NextExpDate_ReturnsTheLeastDate_OfTheAddedSupplies();

    RemoveSupplyExpNext_ChangesAmount();

    RemoveNGoods_ThrowsLack_IfNotEnoughItems();
    RemoveNGoods_ChangesTotalAmount();
    RemoveNGoods_DoesNotChangeNextExpDate_IfNextExpSupply_HasEnoughGoods();
}

//region addSupply

void AddSupply_ChangesTotalAmount()
{
    auto supplies = testInstance();

    size_t old_total = supplies.totalAmount();

    supplies.addSupply(Supply(20, kInPast, kInFutureSooner));

    assert(supplies.totalAmount() == old_total + 20);
    logPassed(__FUNCTION__);
}

void AddSupply_Throws_IfAddingExpired()
{
    assert(expressionThrows<invalid_argument>([]() -> void
    {
        auto supplies = testInstance();
        supplies.addSupply(Supply(20, kInPast, kInPast));
    }));
    logPassed(__FUNCTION__);
}

void AddSupply_Throws_IfAddingManufacturedInFuture()
{
    assert(expressionThrows<invalid_argument>([]() -> void
    {
        auto supplies = testInstance();
        supplies.addSupply(Supply(20, kInFutureSooner, kInFutureSooner));
    }));
    logPassed(__FUNCTION__);
}
//endregion

//region Queue

void NextExpDate_IsLessThanNextDateAfterThisOne()
{
    GoodsSupplies gs = testInstance();

    gs.addSupply(Supply(5, kInPast, kInFutureLater));
    gs.addSupply(Supply(5, kInPast, kInFutureSooner));

    Date front = gs.nextExpirationDate();
    gs.removeSupplyExpiringSoonest();

    Date second_front = gs.nextExpirationDate();
    assert(front < second_front);
    logPassed(__FUNCTION__);
}

void NextExpDate_ReturnsTheLeastDate_OfTheAddedSupplies()
{
    GoodsSupplies gs = testInstance();

    gs.addSupply(Supply(5, kInPast, kInFutureLater));
    gs.addSupply(Supply(5, kInPast, kInFutureSooner));
    gs.addSupply(Supply(5, kInPast,
        Date::fromTimestamp(kInFutureSooner.timestamp() + 10000)));

    assert(gs.nextExpirationDate() == kInFutureSooner);
    logPassed(__FUNCTION__);
}

void RemoveSupplyExpNext_ChangesAmount()
{
    GoodsSupplies gs = testInstance();

    gs.addSupply(Supply(5, kInPast, kInFutureLater));
    gs.addSupply(Supply(5, kInPast, kInFutureSooner));

    Supply::amount_t old_amount = gs.totalAmount();

    gs.removeSupplyExpiringSoonest();

    assert(old_amount == gs.totalAmount() + 5);
    logPassed(__FUNCTION__);
}

void RemoveNGoods_ThrowsLack_IfNotEnoughItems()
{
    expressionThrows<Store::Lack>([]()
    {
        GoodsSupplies gs = testInstance();

        gs.addSupply(Supply(5, kInPast, kInFutureLater));

        gs.removeNGoodsExpiringSoonest(10);
    });
    logPassed(__FUNCTION__);
}

void RemoveNGoods_ChangesTotalAmount()
{
    GoodsSupplies gs = testInstance();

    gs.addSupply(Supply(10, kInPast, kInFutureLater));
    Supply::amount_t old_amount = gs.totalAmount();


    gs.removeNGoodsExpiringSoonest(10);

    assert(old_amount == gs.totalAmount() + 10);
    logPassed(__FUNCTION__);
}

void RemoveNGoods_DoesNotChangeNextExpDate_IfNextExpSupply_HasEnoughGoods()
{
    GoodsSupplies gs = testInstance();

    gs.addSupply(Supply(10, kInPast, kInFutureLater));
    gs.addSupply(Supply(10, kInPast, kInFutureSooner));


    Date  old_next = gs.nextExpirationDate();

    gs.removeNGoodsExpiringSoonest(5);

    Date new_next = gs.nextExpirationDate();
    assert(old_next == new_next);
    logPassed(__FUNCTION__);
}


//endregion


GoodsSupplies testInstance()
{
    Goods g(0, "test_goods", 0);
    return GoodsSupplies(g, kMinAmount);
}
