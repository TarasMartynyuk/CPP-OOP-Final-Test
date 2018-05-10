//
// Created by Taras Martynyuk on 5/2/2018.
//
#include "CashRegister.h"
#include "Discount.h"
using namespace std;


CashRegister::CashRegister(const Store& store)
    : store_(store), cash_(0) {}

CashRegister::amount_t CashRegister::cash() const
    { return cash_; }

void CashRegister::makePurchase(
    const unordered_map<size_t, amount_t>& purch)
{
    // foreach goods, get the supplies to satisfy request
    // also allocate for discounts
    using PurchSupply = std::pair<Supply, Discount*>;
    
    bool all_registered = all_of(
        purch.begin(), purch.end(),
        [this](const pair<size_t, amount_t>& kvp) {
            return store_.goodsRegistered(kvp.first);
        });
    
    if(! all_registered)
        { throw invalid_argument("at least one of goods in purchase is not registered"); }
        
    // if for any goods the request cannot be satisfied, throw
    bool have_enough = all_of(
        purch.begin(), purch.end(),
        [this](const pair<size_t, amount_t>& kvp) {
            return store_.canExclude(
                kvp.first, kvp.second);
        });

    if(! have_enough)
        { throw invalid_argument("the store does not have enough items to exclude "
                                 "at least for one goods in the purchase"); }

    unordered_map<size_t, PurchSupply> supplies_for_purch;
    
//    for(const auto& kvp : supplies_for_purch)
//    {
//        auto supplies = store_.at()
////        supplies_for_purch.insert()
//
//    }
    
}


