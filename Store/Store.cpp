//
// Created by Taras Martynyuk on 5/1/2018.
//
#include "Store.h"
using  namespace std;

bool Store::goodsRegistered(const Goods& good) const
{
    return goods_supplies_.count(good.id()) == 1;
}

void Store::registerGoods(const Goods& gd, const size_t min_amount)
{
    if(goodsRegistered(gd))
        { throw invalid_argument("goods already registered"); }

    goods_supplies_.insert(std::make_pair(
        gd.id(), GoodsSupplies(gd, min_amount)));
}

void Store::include(const Goods& goods, const Supply& supply)
{
    if(! goodsRegistered(goods))
        { throw invalid_argument("no such goods registered"); }

    goods_supplies_.at(goods.id()).addSupply(supply);
}

void Store::exclude(const Goods& gds, const size_t amount)
{
    if(! goodsRegistered(gds))
        { throw invalid_argument("no such goods registered"); }

    if(! canExclude(gds, amount))
        { throw Lack(gds, amount); }


}

bool Store::canExclude(const Goods& goods, const size_t amount) const
{
    if(! goodsRegistered(goods))
        { throw invalid_argument("no such goods registered"); }

    GoodsSupplies supplies = goods_supplies_.at(goods.id());
    return supplies.totalAmount() - amount >= supplies.minAmount();
}

size_t Store::totalAmount(const Goods& goods) const
{
    if(! goodsRegistered(goods))
        { throw invalid_argument("no such goods registered"); }

    return goods_supplies_.at(goods.id()).totalAmount();
}


