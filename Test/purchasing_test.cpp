//
// Created by Taras Martynyuk on 5/9/2018.
//
#include "purchasing_test.h"
#include "test_utils.h"
#include "Store.h"
#include "CashRegister.h"
#include "date_utils.h"
using namespace std;
//region defs

Store testStore();

using amount_c = CashRegister::amount_t;
static const Goods nice_goods(0, "nice goods", 13, 4);
static const Goods soso_goods(1, "so-so goods", 6, 25);

static const amount_c kNiceAmount = 4;
static const amount_c kSosoAmount = 7;

using Purch = unordered_map<size_t, amount_c>;
//endregion

void run_all_purch_tests()
{
    ThrowsLack_IfPurchAmount_GraterThanStoreHas();
}

void ThrowsLack_IfPurchAmount_GraterThanStoreHas()
{
    Store st = testStore();

    Purch purch
        {
            { nice_goods.id(), kNiceAmount },
            { soso_goods.id(), kSosoAmount + 1 }
        };

    assert(expressionThrows<invalid_argument>([&](){
        st.makePurchase(purch);
    }));
    logPassed(__FUNCTION__);
}

Store testStore()
{
    Store st;

    st.registerGoods(nice_goods, 0);
    st.registerGoods(soso_goods, 0);

    st.include(GoodsSupply(
        nice_goods, kNiceAmount, today()));

    st.include(GoodsSupply(
        soso_goods, kSosoAmount, today()));

    return st;
}
