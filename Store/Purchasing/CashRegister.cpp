//
// Created by Taras Martynyuk on 5/2/2018.
//
#include "Discounter.h"
#include "CashRegister.h"
using namespace std;


CashRegister::CashRegister(Store& store)
    : store_(store), cash_(0) {}

CashRegister::amount_t CashRegister::cash() const
    { return cash_; }

void CashRegister::makePurchase(
    const unordered_map<size_t, amount_t>& purch)
{
    if (! store_.allGoodsRegistered(purch))
        { throw invalid_argument("at least one of goods in purchase is not registered"); }
        
    if (! store_.hasEnough(purch))
        { throw invalid_argument("the store does not have enough items to exclude "
                                 "at least for one goods in the purchase"); }
    
    // { goods_id : discounted supplies}
//    unordered_map<size_t, vector<Discounter::DiscountedSupply>>
//        discounted_supplies;
    
    for(const auto& kvp : purch)
    {
        size_t id = kvp.first;
        Store::amount_t amount = purch.at(id);
        
        vector<Supply> supplies = store_.exclude (id, amount);
        
        cash_ += costs (supplies,
                        store_.goodsForId(id).pricePerItem());
    }
}

int CashRegister::costs (
    const vector<Supply>& supplies, int cost_per_item)
{
    assert(cost_per_item > 0);
    return accumulate(supplies.begin(), supplies.end(), 0,
                      [cost_per_item](int sum, const Supply& supply)
                      {
                          return sum + supply.amount() * cost_per_item;
                      });
}


