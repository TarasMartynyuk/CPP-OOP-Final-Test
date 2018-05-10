//
// Created by Taras Martynyuk on 5/9/2018.
//
#include <Store/Purchasing/Headers/Discounter.h>
#include "purchasing_test.h"
#include "test_utils.h"
#include "Store.h"
#include "CashRegister.h"
#include "date_utils.h"
using namespace std;
using namespace date;
//region defs

using amount_c = CashRegister::amount_t;
static const Goods nice_goods(0, "nice goods", 13, 4);
static const Goods soso_goods(1, "so-so goods", 6, 25);

static const amount_c kNiceAmount = 4;
static const amount_c kSosoAmount = 7;

using Purch = unordered_map<size_t, amount_c>;
using DiscSupply = Discounter::DiscountedSupply;
Store testStore();
//endregion

void run_all_purch_tests()
{
    MakePurch_ThrowsLack_IfPurchAmount_GraterThanStoreHas();
    MakePurch_ThrowsLack_IfMoreItemsOfGoodsInPurch_ThanStoreHas();
    MakePurch_ChangesShelvesTotalAmount_ByPurchaseAmount();
    MakePurch_AddsPurchSum_ToCash();

    Discount_ReturnsNulls_IfNoOneQualifies();
}

//region purch

void MakePurch_ThrowsLack_IfPurchAmount_GraterThanStoreHas()
{
    Store st = testStore();

    Purch purch
    {
        {nice_goods.id(), kNiceAmount + kSosoAmount + 5 },
    };

    assert(expressionThrows<invalid_argument>([&](){
        st.makePurchase(purch);
    }));
    logPassed(__FUNCTION__);
}

void MakePurch_ThrowsLack_IfMoreItemsOfGoodsInPurch_ThanStoreHas()
{
    Store st = testStore();

    Purch purch
    {
        {nice_goods.id(), kNiceAmount },
        {soso_goods.id(), kSosoAmount + 1 }
    };

    assert(expressionThrows<invalid_argument>([&](){
        st.makePurchase(purch);
    }));
    logPassed(__FUNCTION__);
}

void MakePurch_ChangesShelvesTotalAmount_ByPurchaseAmount()
{
    Store st = testStore();

    Purch purch
    {
        {nice_goods.id(), kNiceAmount },
        {soso_goods.id(), kSosoAmount - 1 }
    };
    amount_c purch_amount = kNiceAmount + kSosoAmount - 1;
    amount_c orig_amount = st.totalAmount();

    st.makePurchase(purch);

    assert(st.totalAmount() == orig_amount - purch_amount);
    logPassed(__FUNCTION__);
}

void MakePurch_AddsPurchSum_ToCash()
{
    Store st = testStore();
    
    Purch purch
    {
        {nice_goods.id(), kNiceAmount },
        {soso_goods.id(), kSosoAmount - 1 }
    };
    int purch_sum = kNiceAmount * nice_goods.pricePerItem() +
        (kSosoAmount - 1) * soso_goods.pricePerItem();
    int old_cash = st.cash();
    
    st.makePurchase(purch);
    
    assert(st.cash() == old_cash + purch_sum);
    logPassed(__FUNCTION__);
}//endregion

//region discount

void Discount_ReturnsNulls_IfNoOneQualifies()
{
    days min_discount_days = Discounter::kDiscounts.at(0).first;

    assert(min_discount_days > days(0));

    vector<Supply> supplies
        {
            Supply(4, today()),
            Supply(4, today()),
        };

    auto disc_supplies = Discounter::applyDiscountsIfNeeded(supplies);

    assert(all_of(disc_supplies.begin(), disc_supplies.end(),
                  [](const DiscSupply& d_supply){
                      return d_supply.second == nullptr;
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
