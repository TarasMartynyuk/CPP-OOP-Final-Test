//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <stdexcept>
#include "GoodsSupplies.h"
using namespace std;

//region ctors

GoodsSupplies::GoodsSupplies(
    const Goods& goods, int min_amount)
    : goods_(goods), min_amount_(min_amount),
      total_amount_(0) {}

GoodsSupplies::GoodsSupplies(const GoodsSupplies& other)
    : GoodsSupplies(other.goods(), other.minAmount()) {}
//endregion

int& GoodsSupplies::totalAmount()
    { return total_amount_; }

const int& GoodsSupplies::totalAmount() const
    { return total_amount_; }

int& GoodsSupplies::minAmount()
    { return  min_amount_; }

const int& GoodsSupplies::minAmount() const
    { return min_amount_; }
//endregion

const void GoodsSupplies::addSupply(Supply supply)
{
    if(supply.amount() == 0)
        { throw invalid_argument("cannot add a supply of 0 items"); }

    if(isInPast(supply.expiringDate()))
        { throw invalid_argument("cannot add expired goods"); }

    if(isInFuture(supply.manufacturingDate()))
        { throw invalid_argument("manufacturing_date must be in the past");}

    supplies.push_back(supply);
    totalAmount() += supply.amount();
}

const Goods& GoodsSupplies::goods() const
{
    return goods_;
}










