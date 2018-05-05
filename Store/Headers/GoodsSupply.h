//
// Created by Taras Martynyuk on 5/3/2018.
//
#ifndef OOPFINALEXAM_GOODSSUPPLY_H
#define OOPFINALEXAM_GOODSSUPPLY_H
#include "tz.h"
#include "Goods.h"

// a supply of some goods,
// manufactured at certain date
// part of public api
class GoodsSupply
{
public:
    using amount_t = int;

    GoodsSupply(const date::local_days& date_manufactured, const Goods& goods, int amount);

    const date::local_days& dateManufactured() const;
    void setDateManufactured(const date::local_days& date_manufactured);

    const Goods& goods() const;
    void& setGoods(const Goods& goods);

    amount_t amount() const;
    void setAmount(amount_t amount);

private:
    date::local_days date_manufactured_;
    Goods goods_;
    amount_t amount_;
};

#endif //OOPFINALEXAM_GOODSSUPPLY_H
