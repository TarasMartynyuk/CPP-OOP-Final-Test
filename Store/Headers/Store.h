//
// Created by Taras Martynyuk on 5/1/2018.
//
#ifndef OOPFINALEXAM_STORE_H
#define OOPFINALEXAM_STORE_H
#include "CashRegister.h"
#include "Goods.h"
#include "unordered_map"
#include "GoodsShelf.h"
#include "PurchaseItem.h"

class Store
{
public:
    using amount_t = GoodsShelf::amount_t;

    Store() = default;

    void show() const;

    void registerGoods(const Goods&, amount_t min_amount);
    bool goodsRegistered(const Goods&) const;

    // takes the purchase items without discounts
    // and trades items for cash
//    void makePurchase(std::vector<PurchaseItem>);

    // throws if g is not registered
    void include(const Goods& goods, const Supply& supply);

    // throws Lack exception if there is less than minimum amount
    // of goods at the store
    // throws if g is not registered or if there is not enough goods
    void exclude(const Goods& gds, amount_t amount);

    // true if the store can give amount items of type g
    // throws if g is not registered
    bool canExclude(const Goods& goods, amount_t amount) const;
    size_t totalAmount(const Goods&) const;

private:
    // id : goods info
    std::unordered_map<size_t, GoodsShelf> goods_supplies_;

    // oh this may need to be in the GoodsShelf class actually
    static bool canExclude(
        const Goods& goods, amount_t amount,
        const GoodsShelf& supplies);
};

#endif //OOPFINALEXAM_STORE_H