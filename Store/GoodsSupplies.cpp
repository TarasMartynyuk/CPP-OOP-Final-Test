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

//GoodsSupplies::GoodsSupplies(
//    const Goods& goods, size_t min_amount, size_t init_amount)
//    : GoodsSupplies(goods, min_amount)
//{
//    if(init_amount == 0)
//        { throw invalid_argument("init_amount must be more than 0");  }
//
//    addSupply()
//}
//region properties

size_t& GoodsSupplies::totalAmount()
    { return total_amount_; }

const size_t& GoodsSupplies::totalAmount() const
    { return total_amount_; }

size_t& GoodsSupplies::minAmount()
    { return  min_amount_; }

const size_t& GoodsSupplies::minAmount() const
    { return min_amount_; }
//endregion

const void GoodsSupplies::addSupply(const Date&, size_t amount)
{
    return;
}








