//
// Created by Taras Martynyuk on 5/1/2018.
//
#include "Store.h"
using  namespace std;

bool Store::goodsRegistered(const Goods& good) const
{
    return goods_supplies_.count(good.id()) == 1;
}

void Store::registerGoods(const Goods& gd, amount_t min_amount)
{
    if(goodsRegistered(gd))
        { throw invalid_argument("goods already registered"); }

    goods_supplies_.insert(std::make_pair(
        gd.id(), GoodsSupplies(gd, min_amount)));
}

void Store::include(const Goods& goods, const Supply& supply)
{
    if(! goodsRegistered(goods))
        { throw GoodsNotRegistered(goods); }

    goods_supplies_.at(goods.id()).addSupply(supply);
}

void Store::exclude(const Goods& gds, amount_t amount)
{
    if(! goodsRegistered(gds))
        { throw GoodsNotRegistered(gds); }

    GoodsSupplies& supplies = goods_supplies_.at(gds.id());

   // duplicating check for Lack here, but this way the impl of Store is independent from impl of GoodsSupplies
    if(! canExclude(gds, amount))
        { throw Lack(gds, amount); }

    supplies.removeNGoodsExpiringSoonest(amount);
}

bool Store::canExclude(const Goods& goods, amount_t amount) const
{
    if(! goodsRegistered(goods))
        { throw GoodsNotRegistered(goods); }

    return canExclude(goods, amount, goods_supplies_.at(goods.id()));
}

size_t Store::totalAmount(const Goods& goods) const
{
    if(! goodsRegistered(goods))
        { throw GoodsNotRegistered(goods); }

    return goods_supplies_.at(goods.id()).totalAmount();
}

bool Store::canExclude(
    const Goods& goods, Store::amount_t amount,
    const GoodsSupplies& supplies)
{
    return supplies.totalAmount() > amount &&
           supplies.totalAmount() - amount >= supplies.minAmount();
}


