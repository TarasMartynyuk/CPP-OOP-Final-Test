//
// Created by Taras Martynyuk on 5/1/2018.
//
#include <stdexcept>
#include "GoodsSupplies.h"
using namespace std;

GoodsSupplies::GoodsSupplies(
    const Goods& goods, size_t min_amount)
    : goods_(goods), min_amount_(min_amount),
      total_amount_(0), supplies(5) {}

size_t& GoodsSupplies::totalAmount()
    { return total_amount_; }

const size_t& GoodsSupplies::totalAmount() const
    { return total_amount_; }

size_t& GoodsSupplies::minAmount()
    { return  min_amount_; }

const size_t& GoodsSupplies::minAmount() const
    { return min_amount_; }
//endregion

const void GoodsSupplies::addSupply(size_t amount,
    const Date& manufacturing_date, const Date& expiration_date)
{
    if(amount == 0)
        { throw invalid_argument("cannot add a supply of 0 items"); }

    if(isInPast(expiration_date))
        { throw invalid_argument("cannot add expired goods"); }

    if(isInFuture(manufacturing_date))
        { throw invalid_argument("manufacturing_date must be in the past");}

    supplies.push_back(Supply(amount, manufacturing_date, expiration_date));
    totalAmount() += amount;
}








