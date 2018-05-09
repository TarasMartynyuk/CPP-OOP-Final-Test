//
// Created by Taras Martynyuk on 5/2/2018.
//
#include "CashRegister.h"
#include "Discount.h"
using namespace std;


CashRegister::CashRegister(const CashRegister::GShelves& shelves)
    : shelves_(shelves) {}

CashRegister::amount_t CashRegister::cash() const
    { return cash_; }

void CashRegister::makePurchase(
    const unordered_map<size_t, amount_t>& purch)
{
    // foreach goods, get the supplies to satisfy request
    // also allocate for discounts
    using PurchSupply = std::pair<Supply, Discount*>;
    unordered_map<size_t, PurchSupply> supplies_for_purch;

//    amount_t total_items = accumulate(
//        purch.begin(), purch.end(),
//        0, []( amount_t curr_sum,
//            const pair<size_t, amount_t>& kvp)
//            -> amount_t {
//            return curr_sum + kvp.second;
//        });
    // if for any goods the request cannot be satisfied, throw
    bool have_enough = all_of(
        purch.begin(), purch.end(),
        [this](const pair<size_t, amount_t>& kvp) {
            return shelves_.at(kvp.first).
                hasEnough(kvp.second);
        });

    if(! have_enough)
        { throw invalid_argument("the store does not have enough items to exclude "
                                 "at least for 1 goods in the purchase"); }

}


