//
// Created by Taras Martynyuk on 5/1/2018.
//
#ifndef OOPFINALEXAM_STORE_H
#define OOPFINALEXAM_STORE_H

#include "CashRegister.h"
#include "Goods.h"
#include "unordered_map"
#include "GoodsShelf.h"

class CashRegister;

class Store
{
public:
    using amount_t = GoodsShelf::amount_t;
    using Purch = std::unordered_map<size_t, amount_t>;

    Store();

    void show() const;
    
    //region registering
    
    void registerGoods(const Goods&, amount_t min_amount);
    
    bool goodsRegistered(const Goods&) const;
    
    bool goodsRegistered(const size_t&) const;
    //endregion
    //region props
    
    amount_t totalAmount(const Goods& goods) const;
    
    // amount of items of all goods
    amount_t totalAmount() const;
    
    amount_t cash() const;
    //endregion
    
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
    bool canExclude(size_t goods_id, amount_t amount) const;
    
    Store& operator=(const Store& other) = delete;

private:
    // { id : goods info }
    std::unordered_map<size_t, GoodsShelf> shelves_;
    CashRegister* cash_register_ ;
};

#endif //OOPFINALEXAM_STORE_H