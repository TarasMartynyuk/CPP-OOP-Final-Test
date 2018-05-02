//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <cassert>
#include "store_test.h"
#include "test_utils.h"
#include "Store.h"
using namespace std;

const Goods goods (0, "test_goods", 2);
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
    expressionThrows<Store::GoodsNotRegistered>([]() {
        Store().include(goods, Supply(20, kInPast, kInFutureSooner));
    });
    expressionThrows<Store::GoodsNotRegistered>([]() {
        Store().exclude(goods, 10);
    });
    expressionThrows<Store::GoodsNotRegistered>([]() {
        Store().canExclude(goods, 10);
    });

    logPassed(__FUNCTION__);
}

void Include_ChangesAmount()
{
    Store st = testGInstance();

    size_t old_amount = st.totalAmount(goods);
    st.include(goods, Supply(30, kInPast, kInFutureSooner));

    assert(st.totalAmount(goods) == old_amount + 30);
    logPassed(__FUNCTION__);
}

void Exclude_ChangesAmount()
{
    Store st = testGInstance();

    st.include(goods, Supply(30, kInPast, kInFutureSooner));
    Store::amount_t old_amount = st.totalAmount(goods);

    st.exclude(goods, 20);

    Store::amount_t new_am = st.totalAmount(goods);
    assert(new_am == old_amount - 20);
    logPassed(__FUNCTION__);
}

void Exclude_ThrowsLack_IfNotEnoughItems()
{
    expressionThrows<Store::Lack>([]() {

        Store st = testGInstance();

        st.include(goods, Supply(20, kInPast, kInFutureSooner));
        st.exclude(goods, 50);
    });
    logPassed(__FUNCTION__);
}

void Cannot_ExcludeToLessThanMin()
{
    expressionThrows<Store::Lack>([]() {

        Store st = testGInstance();
        Goods gds(10, "test2", 3);
        st.registerGoods(gds, 30);
        st.include(goods, Supply(40, kInPast, kInFutureSooner));
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


