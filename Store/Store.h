//
// Created by Taras Martynyuk on 5/1/2018.
//
#ifndef OOPFINALEXAM_STORE_H
#define OOPFINALEXAM_STORE_H
#include "Goods.h"
#include "unordered_map"
#include "GoodsSupplies.h"

class Store
{
public:
    void registerGoods(const Goods&, size_t min_amount, size_t init_amount=0);
    void include(const Goods&, size_t a);
    // throws Lack exception if there is less than minimum amount
    // of goods at the store
    void exclude(const Goods&, size_t a);

    // true if the store can give amount items of type g
    bool canExclude(const Goods& g, size_t amount);
    size_t totalAmount(const Goods&);

private:
    // id : goods info
    std::unordered_map<size_t, GoodsSupplies> goods_;

    bool goodsRegistered(const Goods& good);
};


#endif //OOPFINALEXAM_STORE_H
