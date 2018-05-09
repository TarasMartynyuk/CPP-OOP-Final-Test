//
// Created by Taras Martynyuk on 5/1/2018.
//
#ifndef OOPFINALEXAM_STORE_H
#define OOPFINALEXAM_STORE_H
#include "Goods.h"
#include "unordered_map"
#include "GoodsShelf.h"

class Store
{
public:
    using amount_t = GoodsShelf::amount_t;

    Store();

    void show() const;

    void registerGoods(const Goods&, amount_t min_amount);
    bool goodsRegistered(const Goods&) const;

    // trades items for cash, adding sum of purch to store cash
    // and excluding necessary amount of items
    void makePurchase(std::unordered_map<Goods, amount_t> purch);

    // throws if g is not registered
    void include(const GoodsSupply&);

    // throws Lack exception if there is less than minimum amount
    // of goods at the store
    // throws if g is not registered or if there is not enough goods
    void exclude(const Goods& gds, amount_t amount);

    // true if the store can give amount items of type g
    // throws if g is not registered
    bool canExclude(const Goods& goods, amount_t amount) const;
    amount_t totalAmount(const Goods& goods) const;

private:
    // id : goods info
    std::unordered_map<size_t, GoodsShelf> goods_supplies_;

    // oh this may need to be in the GoodsShelf class actually
    static bool canExclude(
        const Goods& goods, amount_t amount,
        const GoodsShelf& supplies);
};

#endif //OOPFINALEXAM_STORE_H