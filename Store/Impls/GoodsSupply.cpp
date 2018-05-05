//
// Created by Taras Martynyuk on 5/3/2018.
//
#include "GoodsSupply.h"
using namespace std::chrono;
using namespace date;

GoodsSupply::GoodsSupply(
    const local_days& date_manufactured,
    const Goods& goods,
    int amount) :
    date_manufactured_(date_manufactured),
    goods_(goods),
    amount_(amount) {}

const local_days& GoodsSupply::dateManufactured() const
    { return date_manufactured_; }

void GoodsSupply::setDateManufactured(const local_days& date_manufactured)
    { date_manufactured_ = date_manufactured; }

const Goods& GoodsSupply::goods() const
    { return goods_; }

void& GoodsSupply::setGoods(const Goods& goods)
    { goods_ = goods; }

GoodsSupply::amount_t GoodsSupply::amount() const
    { return amount_; }

void GoodsSupply::setAmount(GoodsSupply::amount_t amount)
    { amount_ = amount; }
