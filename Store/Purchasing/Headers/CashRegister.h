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

    explicit CashRegister (Store&);

    amount_t cash() const;

    // excludes items from purchase from store,
    // and adds cash
    // items get discount if their expiration dates are soon
    // throws if not enough items
    // {goods id : amount}
    void makePurchase(const std::unordered_map<size_t, amount_t>& purch);

private:
    int cash_;
    Store& store_;
    
    int costs (const std::vector<Supply>& supplies,
        int cost_per_item);
};




#endif //OOPFINALEXAM_CASHREGISTER_H
