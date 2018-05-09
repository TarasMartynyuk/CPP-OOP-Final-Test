//
// Created by Taras Martynyuk on 5/1/2018.
//
#include "StoreExceptions.h"
#include "date_utils.h"
#include "Store.h"
#include "Discounter.h"
using  namespace std;

Store::Store()
    : goods_supplies_(),
        cash_register_(goods_supplies_) {}

bool Store::goodsRegistered(const Goods& good) const
{
    return goods_supplies_.count(good.id()) == 1;
}

void Store::registerGoods(const Goods& gd, amount_t min_amount)
{
    if(goodsRegistered(gd))
        { throw invalid_argument("goods already registered"); }

    goods_supplies_.insert(std::make_pair(
        gd.id(), GoodsShelf(gd, min_amount)));
}

void Store::include(const GoodsSupply& g_supply)
{
    if(! goodsRegistered(g_supply.goods()))
        { throw GoodsNotRegistered(g_supply.goods()); }

    if(isInFuture(g_supply.dateManufactured()))
        { throw invalid_argument("manufacturing_date must be in the past");}

    auto exp_date = addDays(g_supply.dateManufactured(),
        g_supply.goods().freshnessPeriod());

    goods_supplies_.at(g_supply.goods().id()).addSupply(
        Supply(g_supply.amount(), exp_date));
}

void Store::exclude(const Goods& gds, amount_t amount)
{
    if(! goodsRegistered(gds))
        { throw GoodsNotRegistered(gds); }

    GoodsShelf& supplies = goods_supplies_.at(gds.id());

   // duplicating check for Lack here, but this way the impl of Store is independent from impl of GoodsShelf
    if(! canExclude(gds, amount))
        { throw Lack(gds, amount); }

    supplies.removeNGoodsExpiringSoonest(amount);
}

bool Store::canExclude(const Goods& goods, amount_t amount) const
{
    if(! goodsRegistered(goods))
        { throw GoodsNotRegistered(goods); }

    return goods_supplies_.at(goods.id()).
        hasEnough(amount);
}

void Store::makePurchase(Purch purch)
{
    cash_register_.makePurchase(purch);
}

Store::amount_t Store::totalAmount(const Goods& goods) const
{
    if(! goodsRegistered(goods))
        { throw GoodsNotRegistered(goods); }

    return goods_supplies_.at(goods.id()).totalAmount();
}

void Store::show() const
{
    cout << "store with goods : { ";
    unordered_map<size_t, GoodsShelf>::const_iterator it = goods_supplies_.begin();

    while(it != goods_supplies_.end())
    {
        cout << "\t";
        std::cout << it->second;
        cout << "\n";
        it++;
    }
    cout << "}";
}






