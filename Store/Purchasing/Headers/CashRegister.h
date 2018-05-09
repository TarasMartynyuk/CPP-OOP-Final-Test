//
// Created by Taras Martynyuk on 5/2/2018.
//
#ifndef OOPFINALEXAM_CASHREGISTER_H
#define OOPFINALEXAM_CASHREGISTER_H
#include "GoodsShelf.h"
#include <iostream>
#include <vector>
#include <unordered_map>

class GoodsShelf;

class CashRegister
{
public:
    using amount_t = GoodsShelf::amount_t;
    CashRegister(const GoodsShelf&);

    amount_t cash() const;

    // excludes items from purchase from store,
    // and adds cash
    // items get discount if their expiration dates are soon
    // throws if not enough items
    // {goods id : amount}
    void makePurchase(std::unordered_map<size_t, amount_t> purch);

private:
    amount_t cash_;
    const GoodsShelf& shelf_;
};




#endif //OOPFINALEXAM_CASHREGISTER_H
