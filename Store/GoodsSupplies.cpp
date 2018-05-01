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
    const Date& date_manufactured, const Date& date_expires)
{
    supplies.push_back(Supply(amount, date_manufactured, date_expires));
    totalAmount() += amount;
}








