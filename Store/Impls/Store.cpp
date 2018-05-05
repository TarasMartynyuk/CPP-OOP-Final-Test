//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <Store/Headers/StoreExceptions.h>
#include "Store.h"
#include "Discounter.h"
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
        gd.id(), GoodsShelf(gd, min_amount)));
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
    const GoodsShelf& supplies)
{
    return supplies.totalAmount() > amount &&
           supplies.totalAmount() - amount >= supplies.minAmount();
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



//void Store::makePurchase(std::vector<PurchaseItem>)
//{
//    // get this from removeNGoodsExpiringSoonest - needs refactoring
//    vector<Supply> supplies_to_rem;
//    cash_register_.makePurchase(Discounter::applyDiscountsIfNeeded(supplies_to_rem));
//}


