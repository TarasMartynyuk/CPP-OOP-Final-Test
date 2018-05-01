//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <stdexcept>
#include <cassert>
#include "GoodsSupplies.h"
using namespace std;

//region ctors

GoodsSupplies::GoodsSupplies(
    const Goods& goods, amount_t min_amount)
    : goods_(goods), min_amount_(min_amount),
      total_amount_(0) {}

GoodsSupplies::GoodsSupplies(const GoodsSupplies& other)
    : GoodsSupplies(other.goods(), other.minAmount()) {}
//endregion

//region properties
//GoodsSupplies::amount_t& GoodsSupplies::totalAmount()
//    { return total_amount_; }

const GoodsSupplies::amount_t& GoodsSupplies::totalAmount() const
    { return total_amount_; }

//GoodsSupplies::amount_t& GoodsSupplies::minAmount()
//    { return  min_amount_; }

const GoodsSupplies::amount_t& GoodsSupplies::minAmount() const
    { return min_amount_; }

//endregion

const void GoodsSupplies::addSupply(Supply supply)
{
    if(supply.amount() <= 0)
        { throw invalid_argument("cannot add a supply of 0 or less items"); }

    if(isInPast(supply.expirationDate()))
        { throw invalid_argument("cannot add expired goods"); }

    if(isInFuture(supply.manufacturingDate()))
        { throw invalid_argument("manufacturing_date must be in the past");}

    supplies.emplace(supply);
    total_amount_ += supply.amount();
}

const Goods& GoodsSupplies::goods() const
{
    return goods_;
}

void GoodsSupplies::removeSupplyExpiringSoonest()
{
    if(supplies.size() == 0)
        { throw logic_error("supplies empty"); }

    assert(totalAmount() > supplies.top().amount());
    total_amount_ -= supplies.top().amount();
    supplies.pop();
}

const Date& GoodsSupplies::nextExpirationDate()
{
    return supplies.top().expirationDate();
}





