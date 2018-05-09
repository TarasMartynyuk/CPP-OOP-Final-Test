//
// Created by Taras Martynyuk on 5/1/2018.
//
#ifndef OOPFINALEXAM_STORE_H
#define OOPFINALEXAM_STORE_H

#include <Store/Purchasing/Headers/CashRegister.h>
#include "Goods.h"
#include "unordered_map"
#include "GoodsShelf.h"

class Store
{
public:
    using amount_t = GoodsShelf::amount_t;
    using Purch = std::unordered_map<size_t, amount_t>;

    Store();

    void show() const;

    void registerGoods(const Goods&, amount_t min_amount);
    bool goodsRegistered(const Goods&) const;

    amount_t totalAmount(const Goods& goods) const;

    // trades items for cash, adding sum of purch to store cash
    // and excluding necessary amount of items
    void makePurchase(Purch purch);

    // throws if g is not registered
    void include(const GoodsSupply&);

    // throws Lack exception if there is less than minimum amount
    // of goods at the store
    // throws if g is not registered or if there is not enough goods
    void exclude(const Goods& gds, amount_t amount);

    // true if the store can give amount items of type g
    // throws if g is not registered
    bool canExclude(const Goods& goods, amount_t amount) const;

    Store& operator=(const Store& other) = delete;

private:
    // { id : goods info }
    std::unordered_map<size_t, GoodsShelf> goods_supplies_;
    CashRegister cash_register_;
};

#endif //OOPFINALEXAM_STORE_H