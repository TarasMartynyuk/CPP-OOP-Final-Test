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
static const Goods nice_goods(0, "nice goods", 13, 10);
static const Goods soso_goods(1, "so-so goods", 9, 25);

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
    MakePurch_IncreasesCash();

    Discount_Throws_IfExpired();
    Discount_ReturnsNulls_IfNoOneQualifies();
    Discount_ReturnsOneNotNull_IfOneQualifies();
    Discount_DiscountedPrice_LessThenNormal();
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

void MakePurch_IncreasesCash()
{
    Store st = testStore();
    
    Purch purch
    {
        {nice_goods.id(), kNiceAmount },
        {soso_goods.id(), kSosoAmount - 1 }
    };
    double old_cash = st.cash();
    
    st.makePurchase(purch);
    
    assert(st.cash() > old_cash);
    logPassed(__FUNCTION__);
}//endregion

//region discount

void Discount_ReturnsNulls_IfNoOneQualifies()
{
    days max_discount_days = Discounter::maxDiscountPeriod();

    days days1(max_discount_days.count() + 3);
    days days2(max_discount_days.count() + 7);

    vector<Supply> supplies
        {
            Supply(4, addDays(today(), days1)),
            Supply(4, addDays(today(), days2)),
        };

    auto disc_supplies = Discounter::applyDiscountsIfNeeded(supplies);

    assert(all_of(disc_supplies.begin(), disc_supplies.end(),
                  [](const DiscSupply& d_supply){
                      return d_supply.second == nullptr;
                  }));
    logPassed(__FUNCTION__);
}

void Discount_Throws_IfExpired()
{
    vector<Supply> supplies
    {
        Supply(4, addDays(today(), days(-5))),
        Supply(4, addDays(today(), days(-10))),
    };

    assert(expressionThrows<invalid_argument>([&supplies](){
        Discounter::applyDiscountsIfNeeded(supplies);
    }));
    logPassed(__FUNCTION__);
}

void Discount_ReturnsOneNotNull_IfOneQualifies()
{
    days max_discount_days = Discounter::maxDiscountPeriod();

    days days1(max_discount_days.count() - 3);
    days days2(max_discount_days.count() -5);

    vector<Supply> supplies
        {
            Supply(4, addDays(today(), days1)),
            Supply(4, addDays(today(), days2)),
        };

    auto disc_supplies = Discounter::applyDiscountsIfNeeded(supplies);

    assert(any_of(disc_supplies.cbegin(), disc_supplies.cend(),
                  [](const DiscSupply& d_supply){
                      return d_supply.second != nullptr;
                  }));
    logPassed(__FUNCTION__);
}

void Discount_DiscountedPrice_LessThenNormal()
{
    Store st;
    Store st_with_discounts;

    auto disc_days = Discounter::maxDiscountPeriod().count();
    Goods goods(0, "smth", 1.0, disc_days + 5);

    st.registerGoods(goods, 0);
    st_with_discounts.registerGoods(goods, 0);

    days more_than_discount (disc_days + 1);
    days with_discount(disc_days - 1);

    auto no_discount_exp_date = addDays(today(), more_than_discount);
    auto discount_exp_date = addDays(today(), with_discount);

    auto no_discount_manufactured = subDays(no_discount_exp_date,
                                            goods.freshnessPeriod());
    auto discount_manufactured = subDays(discount_exp_date,
                                         goods.freshnessPeriod());

    st.include(GoodsSupply(nice_goods, 5,
                           no_discount_manufactured));
    st_with_discounts.include(GoodsSupply(nice_goods, 5,
                                          discount_manufactured));

    Purch purch { {goods.id(), 3} };

    st.makePurchase(purch);
    st_with_discounts.makePurchase(purch);

    assert(st.cash() < st_with_discounts.cash());
    logPassed(__FUNCTION__);
}

Store testStore()
{
    Store st;

    st.registerGoods(nice_goods, 0);
    st.registerGoods(soso_goods, 0);

    st.include(GoodsSupply(
        nice_goods, kNiceAmount, subDays(today(), days(1))));

    st.include(GoodsSupply(
        soso_goods, kSosoAmount, subDays(today(), days(1))));

    return st;
}
