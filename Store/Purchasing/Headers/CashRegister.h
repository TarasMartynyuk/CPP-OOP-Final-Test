//
// Created by Taras Martynyuk on 5/2/2018.
//
#ifndef OOPFINALEXAM_CASHREGISTER_H
#define OOPFINALEXAM_CASHREGISTER_H
#include <iostream>
#include <vector>
#include <unordered_map>
#include "GoodsShelf.h"
#include "Store.h"

class Store;

class CashRegister
{
public:
    using amount_t = GoodsShelf::amount_t;
    using DiscountedSupply = std::pair<Supply, float*>;

    explicit CashRegister (Store&);

    double cash() const;

    // excludes items from purchase from store,
    // and adds cash
    // items get discount if their expiration dates are soon
    // throws if not enough items
    // {goods id : amount}
    void makePurchase(const std::unordered_map<size_t, amount_t>& purch);

private:
    double cash_;
    Store& store_;
    
    double costs(const std::vector<DiscountedSupply>& supplies,
        double cost_per_item);
};




#endif //OOPFINALEXAM_CASHREGISTER_H
