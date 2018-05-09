//
// Created by Taras Martynyuk on 5/2/2018.
//
#include "CashRegister.h"
#include "Discount.h"
using namespace std;

CashRegister::amount_t CashRegister::cash() const
    { return cash_; }

void CashRegister::makePurchase(
    std::unordered_map<size_t, CashRegister::amount_t> purch)
{
    // foreach goods, get the supplies to satisfy request
    // also allocate for discounts
    unordered_map<size_t, std::pair<Supply, Discount*>>
        supplies_for_purch;


//    amount_t items_count =



    // if for any good the request cannot be satisfied, throw

    //

}

