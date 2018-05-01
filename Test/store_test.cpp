//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <cassert>
#include "store_test.h"
#include "test_utils.h"
#include "Store.h"
using namespace std;

const Goods goods (0, "test_goods", 2);
Store st;
void setup();

void test_store()
{
    IncludeExcludeCanExclude_Throws_WhenNotRegistered();
    Include_ChangesAmount();
    Exclude_ChangesAmount();
}

void IncludeExcludeCanExclude_Throws_WhenNotRegistered()
{
    expressionThrows<invalid_argument>([]() {
        Store().include(goods, Supply(20, kInPast, kInFuture));
    });
    expressionThrows<invalid_argument>([]() {
        Store().exclude(goods, 10);
    });
    expressionThrows<invalid_argument>([]() {
        Store().canExclude(goods, 10);
    });

    logPassed(__FUNCTION__);
}

void Include_ChangesAmount()
{
    setup();

    size_t old_amount = st.totalAmount(goods);
    st.include(goods, Supply(30, kInPast, kInFuture));

    assert(st.totalAmount(goods) == old_amount + 30);
    logPassed(__FUNCTION__);
}

void Exclude_ChangesAmount()
{
    setup();

    st.include(goods, Supply(30, kInPast, kInFuture));
    size_t old_amount = st.totalAmount(goods);


    st.exclude(goods, 10);

    assert(st.totalAmount(goods) == old_amount - 10);
    logPassed(__FUNCTION__);
}


void setup()
{
    st = Store();
    st.registerGoods(goods, 0);

}


