//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <cassert>
#include <Store/Headers/StoreExceptions.h>
#include "include_exclude_test.h"
#include "test_utils.h"
#include "Store.h"
using namespace std;

using  amount_t_st = Store::amount_t;
const Goods goods (0, "test_goods", 2, 50);
Store testGInstance();

void test_store()
{
    IncludeExcludeCanExclude_Throws_WhenNotRegistered();
    Include_ChangesAmount();

    Exclude_ThrowsLack_IfNotEnoughItems();
    Exclude_ChangesAmount();
    Cannot_ExcludeToLessThanMin();
}

void IncludeExcludeCanExclude_Throws_WhenNotRegistered()
{
    expressionThrows<GoodsNotRegistered>([]() {
        Store().include(GoodsSupply(goods, 10, kInPast));
    });
    expressionThrows<GoodsNotRegistered>([]() {
        Store().exclude(goods, 10);
    });
    expressionThrows<GoodsNotRegistered>([]() {
        Store().hasEnough(goods, 10);
    });

    logPassed(__FUNCTION__);
}

void Include_ChangesAmount()
{
    Store st = testGInstance();

    amount_t_st old_amount = st.totalAmount(goods);
    st.include(GoodsSupply(goods, 30, kInPast));

    assert(st.totalAmount(goods) == old_amount + 30);
    logPassed(__FUNCTION__);
}

void Include_Throws_IfAddingManufacturedInFuture()
{
    assert(expressionThrows<invalid_argument>([]() -> void
    {
        Store st = testGInstance();
        st.include(GoodsSupply(goods, 10, kInFutureSooner));
    }));
    logPassed(__FUNCTION__);
}

void Exclude_ChangesAmount()
{
    Store st = testGInstance();

    st.include(GoodsSupply(goods, 30, kInPast));
    Store::amount_t old_amount = st.totalAmount(goods);

    st.exclude(goods, 20);

    Store::amount_t new_am = st.totalAmount(goods);
    assert(new_am == old_amount - 20);
    logPassed(__FUNCTION__);
}

void Exclude_ThrowsLack_IfNotEnoughItems()
{
    expressionThrows<Lack>([]() {

        Store st = testGInstance();

        st.include(GoodsSupply(goods,20 , kInPast));
        st.exclude(goods, 50);
    });
    logPassed(__FUNCTION__);
}

void Cannot_ExcludeToLessThanMin()
{
    expressionThrows<Lack>([]() {

        Store st = testGInstance();
        Goods gds(10, "test2", 3, 50);
        st.registerGoods(gds, 30);
        st.include(GoodsSupply(goods, 40, kInPast));
        st.exclude(goods, 20);
    });
    logPassed(__FUNCTION__);
}

Store testGInstance()
{
    Store st;
    st.registerGoods(goods, 0);

    return st;
}


