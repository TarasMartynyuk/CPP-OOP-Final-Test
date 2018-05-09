//
// Created by Taras Martynyuk on 5/1/2018.
//
#include "StoreExceptions.h"
#include "date_utils.h"
#include "Store.h"
#include "Discounter.h"
using  namespace std;

Store::Store()
    : shelves_(),
        cash_register_(new CashRegister(*this)) {}

//region registering

bool Store::goodsRegistered(const Goods& good) const
{
    return goodsRegistered(good.id());
}

bool Store::goodsRegistered(const size_t& goods_id) const
{
    return shelves_.count(goods_id) == 1;
}

void Store::registerGoods(const Goods& gd, amount_t min_amount)
{
    if(goodsRegistered(gd))
        { throw invalid_argument("goods already registered"); }

    shelves_.insert(std::make_pair(
        gd.id(), GoodsShelf(gd, min_amount)));
}
//endregion

void Store::include(const GoodsSupply& g_supply)
{
    if(! goodsRegistered(g_supply.goods()))
        { throw GoodsNotRegistered(g_supply.goods()); }

    if(isInFuture(g_supply.dateManufactured()))
        { throw invalid_argument("manufacturing_date must be in the past");}

    auto exp_date = addDays(g_supply.dateManufactured(),
        g_supply.goods().freshnessPeriod());

    shelves_.at(g_supply.goods().id()).addSupply(
        Supply(g_supply.amount(), exp_date));
}

void Store::exclude(const Goods& gds, amount_t amount)
{
    if(! goodsRegistered(gds))
        { throw GoodsNotRegistered(gds); }

    GoodsShelf& supplies = shelves_.at(gds.id());

   // duplicating check for Lack here, but this way the impl of Store is independent from impl of GoodsShelf
    if(! canExclude(gds, amount))
        { throw Lack(gds, amount); }

    supplies.removeNGoodsExpiringSoonest(amount);
}

bool Store::canExclude(const Goods& goods, amount_t amount) const
{
    return canExclude(goods.id(), amount);
}

bool Store::canExclude(size_t goods_id, Store::amount_t amount) const
{
    if(! goodsRegistered(goods_id))
        { throw GoodsNotRegistered(goods_id); }
    
    return shelves_.at(goods_id).
        hasEnough(amount);
}

void Store::makePurchase(Purch purch)
{
    cash_register_->makePurchase(purch);
}

Store::amount_t Store::totalAmount(const Goods& goods) const
{
    if(! goodsRegistered(goods))
        { throw GoodsNotRegistered(goods); }

    return shelves_.at(goods.id()).totalAmount();
}

void Store::show() const
{
    cout << "store with goods : { ";
    unordered_map<size_t, GoodsShelf>::const_iterator it = shelves_.begin();

    while(it != shelves_.end())
    {
        cout << "\t";
        std::cout << it->second;
        cout << "\n";
        it++;
    }
    cout << "}";
}

Store::amount_t Store::totalAmount() const
{
    return accumulate(
        shelves_.begin(), shelves_.end(),
        0, [](amount_t curr_sum, const pair<size_t, GoodsShelf>& kvp)
        {
            return curr_sum + kvp.second.totalAmount();
        });
}

Store::amount_t Store::cash() const
{
    return cash_register_->cash();
}

